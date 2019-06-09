// -*- C++ -*-
//
// This file is part of The Pivot framework.
// Written by Gabriel Dos Reis.
// See LICENSE for copyright and license notices.
//

#ifndef IPR_IMPL_INCLUDED
#define IPR_IMPL_INCLUDED

#include "interface.h"
#include "utility.h"
#include <memory>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <forward_list>

// -----------------
// -- Methodology --
// -----------------
// This file provides implementations for the interface classes
// defined in <ipr/interface>.  The basic rule is that every class
// found in that header file has at least one implementation in
// this file.  That rule applies to all abstract interfaces such as
// "ipr::Expr", as well as more concrete ones like "ipr::Address".
//    Implementations for the abstract interfaces usually consists in
// providing implementations for common operations on some set of
// interfaces.  For instance, "impl::Expr provides implementation for
// the ipr::Expr::type() operation.
//    For that to work properly, without using virtual inheritance,
// we parameterize the implementations of the abstract interfaces with
// (set of) concrete interfaces.  That ensures, for example, that
// impl::Unary overrides ipr::Node::accept() and forward to the right
// ipr::Visitor::visit() hook.


namespace ipr {
    namespace impl {
        struct Lexicon;

        template<typename T>
        struct stable_farm : std::forward_list<T> {
            using std::forward_list<T>::forward_list;

            template<typename... Args>
            T* make(Args&&... args) {
                this->emplace_front(std::forward<Args>(args)...);
                return &this->front();
            }
        };

        // --------------------------------------
        // -- Implementations of ipr::Sequence --
        // --------------------------------------
        // -- ipr::Sequence --
        // The Sequence<> interface admits various implementations.
        // Here is the list of the implementations currently in use:
        //   (a) ref_sequence<>; (b) val_sequence<>;
        //   (c) empty_sequence<T>.
        // Variants exist in form of
        //   (i) decl_sequence; (ii) singleton_declset<T>.


        // -- impl::ref_sequence --
        // The class ref_sequence<T> implements Sequence<T> by storing
        // references (e.g. pointers) to data of type T, allocated
        // somewhere else.  That for example if useful when keeping track
        // of redeclarations in decl-sets.
        // In general, it can be used to implement the notion of sub-sequence.

        template<class T, class Seq = Sequence<T>>
        struct ref_sequence : Seq, private std::deque<const void*> {
            using Rep = std::deque<const void*>;
            using pointer = const T*;
            using Iterator = typename Seq::Iterator;

            explicit ref_sequence(std::size_t n = 0) : Rep(n) { }

            int size() const final { return Rep::size(); }

            using Seq::operator[];
            using Seq::begin;
            using Seq::end;

            //using Rep::reserve;
            using Rep::resize;
            using Rep::push_back;
            using Rep::push_front;

            const T& get(int p) const final { return *pointer(this->at(p)); }
        };

        // -- impl::val_sequence --
        // The class val_sequence<T> implements Sequence<T> by storing
        // the actual values, instead of references to values (as is
        // the case of ref_sequence<T>).

        template<class T, class Seq = Sequence<T>>
        struct val_sequence : Seq, private stable_farm<T> {
            using Impl = stable_farm<T>;
            using Iterator = typename Seq::Iterator;

            using Seq::operator[];
            using Seq::begin;
            using Seq::end;

            val_sequence() : mark(this->before_begin()) { }

            int size() const final {
                return std::distance(Impl::begin(), Impl::end());
            }

            template<typename... Args>
            T* push_back(Args&&... args)
            {
                mark = this->emplace_after(mark, std::forward<Args>(args)...);
                return &*mark;
            }

            const T& get(int p) const final
            {
                if (p < 0 || p >= size())
                    throw std::domain_error("val_sequence::get");

                auto b = Impl::begin();
                std::advance(b, p);
                return *b;
            }
        private:
            typename Impl::iterator mark;
        };
        // -- impl::empty_sequence --
        // There are various situations where the general notion of
        // sequence leads to consider empty sequence in implementations.
        // We could just use the generic ref_sequence<> or val_sequence<>;
        // however, this specialization will help control data size
        // inflation, as the general sequences need at least two words
        // to keep track of their elements (even when they are empty).
        template<class T>
        struct empty_sequence : ipr::Sequence<T> {
            int size() const final { return 0; }

            const T& get(int) const final
            {
                throw std::domain_error("empty_sequence::get");
            }
        };

        template<class T>
        struct node_ref {
            const T& node;
            explicit node_ref(const T& t) : node(t) { }
        };

        // -- Token --
        struct Token : ipr::Lexeme, ipr::Token {
            const String& spelling() const final { return text; }
            const Source_location& locus() const final { return location; }
            const ipr::Lexeme& lexeme() const final { return *this; }
            TokenValue value() const final { return token_value; }
            TokenCategory category() const final { return token_category; }

        private:
            const String& text;
            Source_location location;
            TokenValue token_value;
            TokenCategory token_category;
            Token(const String&, const Source_location&, TokenValue, TokenCategory);
            friend impl::Lexicon;
        };

        // -- Module_name --
        struct Module_name : ipr::Module_name {
            ref_sequence<ipr::Identifier> components;

            const ipr::Sequence<ipr::Identifier>& stems() const final;
        };

        // -- Node --
        template<class T>
        struct Node : T {
            using Interface = T;
            void accept(ipr::Visitor& v) const final { v.visit(*this); }
        };

        // In various situations, we need to store nodes in ordered
        // containers.  We could of course use the addresses of Nodes as
        // keys.  However, for simplicity and persistence reasons, we chose
        // to used an integer identifier. (Each node  acquires such an
        // identifier at its creation and retain it unchanged till the
        // end of the program.)  An obvious benefit is that ordering comes
        // for free.
        template<typename T>
        constexpr int compare(T lhs, T rhs)
        {
            return lhs < rhs ? -1 : (lhs > rhs ? 1 : 0);
        }

        constexpr int compare(const ipr::Node& lhs, const ipr::Node& rhs)
        {
            return compare(lhs.node_id, rhs.node_id);
        }

        // Helper class
        template<class Interface>
        struct Unary : Interface {
            using typename Interface::Arg_type;
            Arg_type rep;

            explicit Unary(Arg_type a) : rep{ a } { }

            Arg_type operand() const final { return rep; }
        };

        // Short for the impplementation of generic unary nodes.
        template<typename T>
        using Unary_node = Unary<Node<T>>;

        // FIXME: This class template logically inherits from impl::Unary<T>,
        // FIXME as it was in previous versions.
        // FIXME: However, VC++2015 got utterly confused.
        template<class Interface>
        struct type_from_operand : Interface {
            using typename Interface::Arg_type;
            Arg_type rep;

            explicit type_from_operand(Arg_type a) : rep(a) { }
            const ipr::Type& type() const final
            {
                return rep.type();
            }
            Arg_type operand() const final { return rep; }
        };

        template<class Interface>
        struct Binary : Interface {
            using typename Interface::Arg1_type;
            using typename Interface::Arg2_type;
            struct Rep {
                Arg1_type first;
                Arg2_type second;
            };
            Rep rep;

            Binary(const Rep& r) : rep(r) { }
            Binary(Arg1_type f, Arg2_type s) : rep{ f, s } { }

            Arg1_type first() const final { return rep.first; }
            Arg2_type second() const final { return rep.second; }
        };

        // Short hand for implementation of geeric binary nodes.
        template<typename T>
        using Binary_node = Binary<Node<T>>;

        // FIXME: see comment on type_from_operand.  VC++2015 bug.
        // FIXME: This class template logically inherits from impl::Binary<T>,
        // FIXME as it was in previous versions.
        // FIXME: However, VC++2015 got utterly confused.
        template<class Interface>
        struct type_from_second : Interface {
            using typename Interface::Arg1_type;
            using typename Interface::Arg2_type;
            struct Rep {
                Arg1_type first;
                Arg2_type second;
            };
            Rep rep;

            type_from_second(Arg1_type f, Arg2_type s) : rep{ f, s } { }

            const ipr::Type& type() const final
            {
                return this->rep.second.type();
            }
            Arg1_type first() const final { return rep.first; }
            Arg2_type second() const final { return rep.second; }
        };


        template<class Interface>
        struct Ternary : Interface {
            using typename Interface::Arg1_type;
            using typename Interface::Arg2_type;
            using typename Interface::Arg3_type;
            struct Rep {
                Arg1_type first;
                Arg2_type second;
                Arg3_type third;
            };
            Rep rep;

            Ternary(const Rep& r) : rep(r) { }
            Ternary(Arg1_type f, Arg2_type s, Arg3_type t) : rep{ f, s, t } { }

            Arg1_type first() const final { return rep.first; }
            Arg2_type second() const final { return rep.second; }
            Arg3_type third() const final { return rep.third; }
        };

        template<class Interface>
        struct Quaternary : Interface {
            using typename Interface::Arg1_type;
            using typename Interface::Arg2_type;
            using typename Interface::Arg3_type;
            using typename Interface::Arg4_type;
            struct Rep {
                Arg1_type first;
                Arg2_type second;
                Arg3_type third;
                Arg4_type fourth;
            };
            Rep rep;

            Quaternary(const Rep& r) : rep(r) { }
            Quaternary(Arg1_type f, Arg2_type s, Arg3_type t, Arg4_type u) : rep{ f, s, t, u } { }

            Arg1_type first() const final { return rep.first; }
            Arg2_type second() const final { return rep.second; }
            Arg3_type third() const final { return rep.third; }
            Arg4_type fourth() const final { return rep.fourth; }
        };


        // -------------------------
        // -- Classic expressions --
        // -------------------------

        template<class Operation>
        struct Classic : Operation {
            const ipr::Decl* op_impl = { };
            using Operation::Operation;

            Optional<ipr::Decl> implementation() const final
            {
                return { op_impl };
            }
        };

        // -- Conversion_expr --
        template<class Interface>
        struct Conversion_expr : impl::Classic<Binary_node<Interface>> {
            using Base = impl::Classic<Binary_node<Interface>>;
            using Base::Base;

            const ipr::Type& type() const { return this->rep.first; }
        };

        // -- String --
        struct String : impl::Node<ipr::String> {
            explicit String(const util::string&);

            int size() const;
            const char* begin() const;
            const char* end() const;

        private:
            const util::string& text;
        };

        // -- Linkage --
        using Linkage = Unary_node<ipr::Linkage>;

        // -------------------------
        // -- General expressions --
        // -------------------------
        // Various generalized expressions are the result of a unary
        // operator applied to an expression.  Their structure is captured
        // by ipr::Unary<>.  The class unary_expr<T> implements that
        // interface.

        template<class Interface>
        struct Expr : impl::Node<Interface> {
            const ipr::Type* constraint;

            Expr(const ipr::Type* t = 0) : constraint(t) { }
            const ipr::Type& type() const override
            {
                return *util::check(constraint);
            }
        };

        // Short hand for the implementation of generic expression nodes.
        template<typename T>
        using Unary_expr = Unary<Expr<T>>;

        template<typename T>
        using Classic_unary_expr = Classic<Unary_expr<T>>;

        template<typename T>
        using Binary_expr = Binary<Expr<T>>;

        template<typename T>
        using Classic_binary_expr = Classic<Binary_expr<T>>;

        // ----------------------------------------------------
        // -- Scopes, sequence of declarations and overloads --
        // ----------------------------------------------------
        //
        // A scope is defined to be a sequence of declarations.
        // There may be multiple instances of a declaration in
        // a scope.  All declarations sharing the same name
        // form an overload set.  Consequently a scope is partitioned
        // into overload sets, each of which is uniquely identified
        // by its name.
        // An overload set, in turn, is partitioned in sub-sets of
        // (multiple) declarations with same type.  So, each decl-set
        // within its overload set, is uniquely determined by its
        // type.  Each decl-set has a "standard" representative,
        // called the "master declaration".  A master declaration is
        // the first seen declaration of a decl-set.
        //
        // There are few special cases of the above general description.
        // Parameters, base-classes and enumerators cannot be multiply
        // declared.  Therefore within a parameter-lits, a base-class
        // list or an enumeration definition, each decl-set is
        // singleton whose sole element is the master declaration.
        //
        // A scope chains declaration together.  A declaration in a
        // Scope has a "position", that uniquely identifies it as a member
        // of a sequence.  To provide a relatively fast "subscription by position"
        // operation on a scope, the chain of declaration is
        // organized as a red-back tree where the position is used as key.
        // And alternative is a hash table, when we get there.

        using util::rb_tree::link;
        struct scope_datum : link<scope_datum> {
            // The position of this Decl in its scope.  It shall be set
            // at the actual declaration creation by the creating scope.
            int scope_pos = -1;

            // The specifiers for this declaration.  S
            ipr::DeclSpecifiers spec = { };

            // Back-pointer to this declaration.  It shall be set at
            // the declaration creation.
            const ipr::Decl* decl = { };

            // A comparator object type, implements ordering on declaration
            // position chaining declarations together, in scopes.
            struct comp;
        };

        // -- impl::decl_sequence --
        // The chain of declarations in a scope.

        struct decl_sequence : ipr::Sequence<ipr::Decl> {
            int size() const final;
            const ipr::Decl& get(int) const final;
            // Inserts a declaration in this sequence.
            void insert(scope_datum*);

        private:
            util::rb_tree::chain<scope_datum> decls;
        };

        // -- impl::singleton_declset --
        // A singleton_declset is a specialization of decl_sequence
        // that contains only a single declaration.  It is mostly used
        // to support the general interface of ipr::Scope as inherited
        // in parameter-list or enumerator definitions.

        template<class T>
        struct singleton_declset : ipr::Sequence<ipr::Decl> {
            const T& datum;

            explicit singleton_declset(const T& t) : datum(t) { }

            int size() const final { return 1; }
            const T& get(int i) const final
            {
                if (i == 1)
                    return datum;
                throw std::domain_error("singleton_declset::get");
            }
        };


        // All declarations (except parameters, base-classes, enumerations)
        // maintain data about their position and master declaration.  Since
        // all declarations in a given decl-set have the same type, only
        // the master declaration has the "type" information.
        // Similarly, only the master declaration maintains the home
        // region information.
        //
        // In a given decl-set, only one of the declarations is a definition.
        // The master declaration keeps track of that definition, so all
        // other redeclarations can refer to it through the master
        // declaration data.

        template<class> struct master_decl_data;
        struct Overload;

        // An entry in an overload set.  Part of the data that a
        // master declaration manages.  It is determined, within
        // an overload set, by its type.  All redeclarations must
        // register themselves before the master declaration, at
        // the creation time.

        struct overload_entry : link<overload_entry> {
            const ipr::Type& type;
            ref_sequence<ipr::Decl> declset;
            explicit overload_entry(const ipr::Type& t) : type(t) { }
        };


        template<class Interface>
        struct basic_decl_data : scope_datum {
            // Information about the master declararion.  This pointer
            // shall be set at actual declaration creation time.
            master_decl_data<Interface>* master_data;

            explicit basic_decl_data(master_decl_data<Interface>* mdd)
                    : master_data(mdd)
            { }
        };


        // A master declaration is the first seen introduction of
        // a name with a given type.  Further redeclarations
        // are represented by basic_decl_data<> and are linked to the
        // master declaration.  That forms the declaration-set of
        // that declaration.

        template<class Interface>
        struct master_decl_data : basic_decl_data<Interface>, overload_entry {
            // The declaration that is considered to be the definition.
            const Interface* def;
            const ipr::Linkage* langlinkage;

            // The overload set that contains this master declaration.  It
            // shall be set at the time the node for the master declaration
            // is created.
            impl::Overload* overload;
            const ipr::Region* home;
            master_decl_data(impl::Overload* ovl, const ipr::Type& t)
                    : basic_decl_data<Interface>(this),
                      overload_entry(t),
                      def(0), langlinkage(0),
                      overload(ovl),home(0)
            { }
        };

        template<>
        struct master_decl_data<ipr::Named_map>
                : basic_decl_data<ipr::Named_map>, overload_entry {
            using Base = basic_decl_data<ipr::Named_map>;
            // The declaration that is considered to be the definition.
            const ipr::Named_map* def;
            const ipr::Linkage* langlinkage;
            const ipr::Named_map* primary;
            const ipr::Region* home;

            // The overload set that contains this master declaration.  It
            // shall be set at the time the node for the master declaration
            // is created.
            impl::Overload* overload;

            // Sequence of specilizations
            decl_sequence specs;

            master_decl_data(impl::Overload*, const ipr::Type&);
        };


        struct Overload : impl::Expr<ipr::Overload> {
            // The name of this overload set.
            const ipr::Name& name;

            // All declarations happen in some region.  This is the region
            // that contains the declarations in this overload set.  It shall
            // be set at the overload set is actually created.
            const ipr::Region* where;

            // All entries in this overload set, chained together in a
            // red-back tree to permit fast retrieval based on type (as key).
            // They are all master declarations.
            util::rb_tree::chain<overload_entry> entries;

            // A sequence of master declarations.  They are added as they
            // appear in their enclosing scope.
            std::vector<scope_datum*> masters;

            explicit Overload(const ipr::Name&);

            const ipr::Sequence<ipr::Decl>& operator[](const ipr::Type&) const final;
            int size() const final;
            const ipr::Decl& get(int) const final;
            overload_entry* lookup(const ipr::Type&) const;

            template<class T>
            void push_back(master_decl_data<T>*);
        };

        // Parameters, base-subobjects and enumerations cannot be
        // multiply declared in a given region.  Therefore such a
        // declaration is the sole member in its own decl-set.
        // Furthermore, there cannot be other declaration with
        // different type but same name.  Therefore the name for
        // such a declaration defines an overload set with a single
        // member.  This class implements such a special overload set.

        struct singleton_overload : impl::Node<ipr::Overload> {
            singleton_declset<ipr::Decl> seq;

            explicit singleton_overload(const ipr::Decl&);

            const ipr::Type& type() const final;
            int size() const final;
            const ipr::Decl& get(int) const final;
            const ipr::Sequence<ipr::Decl>& operator[](const ipr::Type&) const final;
        };


        // When a name is not declared in a scope, then an empty overload
        // set is returned.  This class empty_overload implements that notion.
        // Alternatively, we could have thrown an exception to indicate
        // that failure; however, the resulting programming style might
        // be clutered by try-blocks.

        struct empty_overload : impl::Node<ipr::Overload> {
            const ipr::Type& type() const final;
            int size() const final;
            const ipr::Decl& get(int) const final;
            const ipr::Sequence<ipr::Decl>& operator[](const ipr::Type&) const final;
        };

        struct node_compare {
            int operator()(const ipr::Node& lhs, const ipr::Node& rhs) const
            {
                return compare(lhs, rhs);
            }

            int
            operator()(const ipr::Type& t, const overload_entry& e) const
            {
                return (*this)(t, e.type);
            }

            int
            operator()(const overload_entry& l, const overload_entry& r) const
            {
                return (*this)(l.type, r.type);
            }
        };

        // -----------------------
        // -- Generalized types --
        // -----------------------

        // impl::Type<T> implements the common operations supported
        // by all operations.  In particular, it implements only
        // main-variant types; qualified types are handled elsewhere.

        template<class T>
        struct Type : impl::Expr<T> {
            const ipr::Name* id = { };

            const ipr::Name& name() const final { return *util::check(id); }
        };

        template<typename T>
        using Unary_type = Unary<Type<T>>;

        template<typename T>
        using Binary_type = Binary<Type<T>>;

        // Scopes, as expressions, have Product types.  Such types could
        // be implemented directly as a separate sequence of types.
        // However, it would require coordination from the various
        // scope updaters to keep the types in sync.  An alternative,
        // implemented by typed_sequence<Seq>, is to wrap sequences
        // in "type envelop" and return the nth type as being the
        // type of the nth declaration in the sequence.

        template<class Seq>
        struct typed_sequence : impl::Type<ipr::Product>,
                                ipr::Sequence<ipr::Type> {
            Seq seq;

            typed_sequence() { }
            explicit typed_sequence(const Seq& s) : seq(s) { }

            const ipr::Sequence<ipr::Type>& operand() const final
            {
                return *this;
            }
            int size() const final { return seq.size(); }
            const ipr::Type& get(int i) const final
            {
                return seq.get(i).type();
            }
        };

        // This class template maps an interface type to its actual
        // implementation type.  It is mostly used for getting the
        // implementation type of declaration interfaces.

        template<class>
        struct traits {
        };

        // -----------------
        // -- impl::Rname --
        // -----------------
        struct Rname : Ternary<Node<ipr::Rname>> {
            explicit Rname(Rep);

            // It was not strictly necessary to actually define this class
            // and the function type().  See the comments in <ipr/interface>.
            const ipr::Type& type() const;
        };

        // Stmt<S> implements the common operations of statements.

        struct Stmt_common {
            ipr::Unit_location unit_locus;
            ipr::Source_location src_locus;
            ref_sequence<ipr::Annotation> notes;
            ref_sequence<ipr::Attribute> attrs;
        };

        template<class S>
        struct Stmt : S, Stmt_common {
            const ipr::Unit_location& unit_location() const final
            {
                return unit_locus;
            }

            const ipr::Source_location& source_location() const final
            {
                return src_locus;
            }

            const ipr::Sequence<ipr::Annotation>& annotation() const final
            {
                return notes;
            }

            const ipr::Sequence<ipr::Attribute>& attributes() const final
            {
                return attrs;
            }
        };

        // The class template Decl<> implements common operations
        // for most declarations nodes.  The exception cases are
        // handled by the class template unique_decl<>.

        template<class D>
        struct Decl : Stmt<Node<D>> {
            basic_decl_data<D> decl_data;
            ipr::Named_map* pat = { };
            val_sequence<ipr::Substitution> args;

            Decl() : decl_data{ nullptr } { }

            const ipr::Sequence<ipr::Substitution>& substitutions() const final
            { return args; }

            const ipr::Named_map& generating_map() const final
            { return *util::check(pat); }

            const ipr::Linkage& lang_linkage() const final
            {
                return *util::check(util::check(decl_data.master_data)->langlinkage);
            }

            const ipr::Region& home_region() const override {
                return *util::check(util::check(decl_data.master_data)->home);
            }

            // Set declaration specifiers for this decl.
            using D::specifiers;
            void specifiers(ipr::DeclSpecifiers s) {
                decl_data.spec = s;
            }
        };


        // Some declarations (e.g. parameters, base-classes, enumerators)
        // cannot be redeclared in their declarative regions.  Consequently
        // their decl-sets and overload sets are singleton, containing
        // only the mater declarations.  Consequently, it seems
        // heavyweight space wasteful to deploy the general representation
        // machinery for them.  The class unique_decl<> implements the
        // specialization of Decl<> in those cases.

        template<class Interface>
        struct unique_decl : impl::Stmt<Node<Interface>> {
            ipr::DeclSpecifiers spec;
            const ipr::Linkage* langlinkage;
            singleton_overload overload;
            ipr::Named_map* pat;
            val_sequence<ipr::Substitution> args;

            unique_decl() : spec(ipr::DeclSpecifiers::None),
                            langlinkage{ },
                            overload(*this),
                            pat{ }
            { }

            ipr::DeclSpecifiers specifiers() const final { return spec; }
            const ipr::Decl& master() const final { return *this; }
            const ipr::Linkage& lang_linkage() const final
            {
                return *util::check(langlinkage);
            }

            const ipr::Sequence<ipr::Substitution>& substitutions() const final
            { return args; }

            const ipr::Named_map& generating_map() const final
            { return *util::check(pat); }
        };

        struct Parameter : unique_decl<ipr::Parameter> {
            const ipr::Name& id;
            const impl::Rname& abstract_name;
            const ipr::Parameter_list* where;
            const ipr::Expr* init;

            Parameter(const ipr::Name&, const impl::Rname&);

            const ipr::Name& name() const;
            const ipr::Type& type() const;
            const ipr::Region& home_region() const;
            const ipr::Region& lexical_region() const;
            const ipr::Sequence<ipr::Decl>& decl_set() const;
            int position() const;
            Optional<ipr::Expr>initializer() const final;
            // FIXME: This should go away.
            const Parameter_list& membership() const;
        };

        struct Base_type : unique_decl<ipr::Base_type> {
            const ipr::Type& base;
            const ipr::Region& where;
            const int scope_pos;

            Base_type(const ipr::Type&, const ipr::Region&, int);
            const ipr::Type& type() const;
            const ipr::Region& lexical_region() const;
            const ipr::Region& home_region() const;
            int position() const;
            Optional<ipr::Expr> initializer() const final;
            const ipr::Sequence<ipr::Decl>& decl_set() const;
        };

        struct Enumerator : unique_decl<ipr::Enumerator> {
            const ipr::Name& id;
            const ipr::Enum& constraint;
            const int scope_pos;
            const ipr::Region* where;
            const ipr::Expr* init;

            Enumerator(const ipr::Name&, const ipr::Enum&, int);
            const ipr::Name& name() const;
            const ipr::Region& lexical_region() const;
            const ipr::Region& home_region() const;
            const ipr::Sequence<ipr::Decl>& decl_set() const;
            int position() const;
            Optional<ipr::Expr> initializer() const final;
            // FIXME: this should go away.
            const ipr::Enum& membership() const;
        };


        // Map ipr::Parameter, ipr::Base_type and ipr::Enumerator
        // to their implementation classes.  This information is
        // mostly used in the implementation of homogeneous_sequence,
        // homogeneous_scope and homogeneous_region.

        template<>
        struct traits<ipr::Parameter> {
            using rep = impl::Parameter;
        };

        template<>
        struct traits<ipr::Base_type> {
            using rep = impl::Base_type;
        };

        template<>
        struct traits<ipr::Enumerator> {
            using rep = impl::Enumerator;
        };


        // A sequence of homogenous node can be represented directly
        // as a container of the concrete implementations classes
        // instad of pointers to the interface nodes.  This is the
        // case in particular for enumerators or parameters.

        template<class Member>
        struct homogeneous_sequence : ipr::Sequence<Member> {
            using rep = typename traits<Member>::rep;
            val_sequence<rep> seq;

            int size() const { return seq.size(); }
            const rep& get(int i) const { return seq.get(i); }


            // Most nodes in homogeneous sequences need only
            // two or three arguments for their constructors.
            template<class T, class U>
            rep* push_back(const T& t, const U& u)
            {
                return seq.push_back(t, u);
            }

            template<class T, class U, class V>
            rep* push_back(const T& t, const U& u, const V& v)
            {
                return seq.push_back(t, u, v);
            }
        };


        template<class Member>
        struct homogeneous_scope : impl::Node<ipr::Scope>,
                                   ipr::Sequence<ipr::Decl>,
                                   std::allocator<void> {
            using member_rep = typename homogeneous_sequence<Member>::rep;
            typed_sequence<homogeneous_sequence<Member>> decls;
            empty_overload missing;

            explicit
            homogeneous_scope(const ipr::Type& t)
            {
                decls.constraint = &t;
            }

            int size() const { return decls.size(); }
            const Member& get(int i) const { return decls.seq.get(i); }

            const ipr::Product& type() const { return decls; }

            const ipr::Sequence<ipr::Decl>& members() const { return *this; }

            const ipr::Overload& operator[](const Name&) const;

            template<class T, class U>
            member_rep* push_back(const T& t, const U& u)
            {
                member_rep* decl = decls.seq.push_back(t, u);
                return decl;
            }

            template<class T, class U, class V>
            member_rep* push_back(const T& t, const U& u, const V& v)
            {
                member_rep* decl = decls.seq.push_back(t, u, v);
                return decl;
            }
        };

        // FIXME: Remove this linear search.
        template<class Member>
        const ipr::Overload&
        homogeneous_scope<Member>::operator[](const ipr::Name& n) const
        {
            const int s = decls.size();
            for (int i = 0; i < s; ++i) {
                const typename homogeneous_sequence<Member>::rep&
                        decl = decls.seq.get(i);
                if (decl.name().node_id == n.node_id)
                    return decl.overload;
            }

            return missing;
        }

        template<class Member,
                class RegionKind = Node<ipr::Region>>
        struct homogeneous_region : RegionKind {
            using location_span = ipr::Region::Location_span;
            const ipr::Region& parent;
            location_span extent;
            const ipr::Expr* owned_by = { };
            homogeneous_scope<Member> scope;

            int size() const { return scope.size(); }
            const Member& get(int i) const { return scope.get(i); }
            const ipr::Product& type() const { return scope.type(); }

            const ipr::Region& enclosing() const { return parent; }
            const ipr::Scope& bindings() const { return scope; }
            const location_span& span() const { return extent; }
            const ipr::Expr& owner() const { return *util::check(owned_by); }

            homogeneous_region(const ipr::Region& p, const ipr::Type& t)
                    : parent(p), scope(t)
            { }
        };

        struct Parameter_list : homogeneous_region<ipr::Parameter,
                impl::Node<ipr::Parameter_list>> {
            using Base = homogeneous_region<ipr::Parameter,
                    impl::Node<ipr::Parameter_list>>;

            Parameter_list(const ipr::Region&, const ipr::Type&);

            impl::Parameter* add_member(const ipr::Name&, const impl::Rname&);
        };

        template<class T>
        struct decl_rep : traits<T>::rep {
            decl_rep(master_decl_data<T>* mdd)
            {
                this->decl_data.master_data = mdd;
                this->decl_data.decl = this;
                mdd->declset.push_back(this);
            }

            const ipr::Name& name() const
            {
                return this->decl_data.master_data->overload->name;
            }

            ipr::DeclSpecifiers specifiers() const
            {
                return this->decl_data.spec;
            }

            const ipr::Type& type() const
            {
                return this->decl_data.master_data->type;
            }

            const ipr::Scope& scope() const
            {
                return this->decl_data.master_data->overload->where;
            }

            int position() const
            {
                return this->decl_data.scope_pos;
            }

            const ipr::Decl& master() const
            {
                return *util::check(this->decl_data.master_data->decl);
            }

            const ipr::Sequence<ipr::Decl>& decl_set() const
            {
                return this->decl_data.master_data->declset;
            }

            const T& definition() const
            {
                return *util::check(this->decl_data.master_data->def);
            }
        };


        using Array = Binary_type<ipr::Array>;
        using Decltype = Unary_type<ipr::Decltype>;
        using As_type = Binary_type<ipr::As_type>;
        using Function = Quaternary<Type<ipr::Function>>;
        using Pointer = Unary_type<ipr::Pointer>;
        using Product = Unary_type<ipr::Product>;
        using Ptr_to_member = Binary_type<ipr::Ptr_to_member>;
        using Qualified = Binary_type<ipr::Qualified>;
        using Reference = Unary_type<ipr::Reference>;
        using Rvalue_reference = Unary_type<ipr::Rvalue_reference>;
        using Sum = Unary_type<ipr::Sum>;
        using Template = Binary_type<ipr::Template>;

        using Comment = Unary_node<Comment>;

        using Phantom = Expr<ipr::Phantom>;

        using Address = Classic_unary_expr<ipr::Address>;
        using Array_delete = Classic_unary_expr<ipr::Array_delete>;
        using Complement = Classic_unary_expr<ipr::Complement>;
        using Conversion = Unary_expr<ipr::Conversion>;
        using Ctor_name = Unary_expr<ipr::Ctor_name>;
        using Delete = Classic_unary_expr<ipr::Delete>;
        using Deref = Classic_unary_expr<ipr::Deref>;
        using Dtor_name = Unary_expr<ipr::Dtor_name>;

        struct Expr_list : impl::Node<ipr::Expr_list> {
            typed_sequence<ref_sequence<ipr::Expr>> seq;

            Expr_list();
            explicit Expr_list(const ref_sequence<ipr::Expr>&);

            const ipr::Product& type() const final;

            const ipr::Sequence<ipr::Expr>& operand() const final;

            void push_back(const ipr::Expr* e) { seq.seq.push_back(e); }
            // >>>> Yuriy Solodkyy: 2007/02/02
            // Front insertable sequence is more suitable for bottom-up parsing
            void push_front(const ipr::Expr* e) { seq.seq.push_front(e); }
            // <<<< Yuriy Solodkyy: 2007/02/02
        };

        using Initializer_list = Classic_unary_expr<ipr::Initializer_list>;
        using Sizeof = Unary_expr<ipr::Sizeof>;
        using Typeid = Unary_expr<ipr::Typeid>;
        using Identifier = Unary_expr<ipr::Identifier>;

        struct Id_expr : Unary_expr<ipr::Id_expr> {
            const ipr::Decl* decl;

            explicit Id_expr(const ipr::Name&);
            const ipr::Type& type() const final;
            const ipr::Decl& resolution() const final;
        };

        using Not = Classic_unary_expr<ipr::Not>;

        using Operator = Unary_expr<ipr::Operator>;
        using Paren_expr = type_from_operand<Classic<Node<ipr::Paren_expr>>>;

        using Pre_decrement = Classic_unary_expr<ipr::Pre_decrement>;
        using Pre_increment = Classic_unary_expr<ipr::Pre_increment>;
        using Post_decrement = Classic_unary_expr<ipr::Post_decrement>;
        using Post_increment = Classic_unary_expr<ipr::Post_increment>;
        using Throw = Classic_unary_expr<ipr::Throw>;
        using Type_id = type_from_operand<Node<ipr::Type_id>>;

        using Unary_minus = Classic_unary_expr<ipr::Unary_minus>;
        using Unary_plus = Classic_unary_expr<ipr::Unary_plus>;
        using Expansion = Classic_unary_expr<ipr::Expansion>;

        using And = Classic_binary_expr<ipr::And>;
        using Annotation = Binary_node<ipr::Annotation>;
        using Array_ref = Classic_binary_expr<ipr::Array_ref>;
        using Arrow = Classic_binary_expr<ipr::Arrow>;
        using Arrow_star = Classic_binary_expr<ipr::Arrow_star>;
        using Assign = Classic_binary_expr<ipr::Assign>;
        using Bitand = Classic_binary_expr<ipr::Bitand>;
        using Bitand_assign = Classic_binary_expr<ipr::Bitand_assign>;
        using Bitor = Classic_binary_expr<ipr::Bitor>;
        using Bitor_assign = Classic_binary_expr<ipr::Bitor_assign>;
        using Bitxor = Classic_binary_expr<ipr::Bitxor>;
        using Bitxor_assign = Classic_binary_expr<ipr::Bitxor_assign>;
        using Call = Classic_binary_expr<ipr::Call>;
        using Cast = Conversion_expr<ipr::Cast>;
        using Comma = Classic_binary_expr<ipr::Comma>;
        using Const_cast = Conversion_expr<ipr::Const_cast>;
        using Datum = Conversion_expr<ipr::Datum>;
        using Div = Classic_binary_expr<ipr::Div>;
        using Div_assign = Classic_binary_expr<ipr::Div_assign>;
        using Dot = Classic_binary_expr<ipr::Dot>;
        using Dot_star = Classic_binary_expr<ipr::Dot_star>;
        using Dynamic_cast = Conversion_expr<ipr::Dynamic_cast>;
        using Equal = Classic_binary_expr<ipr::Equal>;
        using Greater = Classic_binary_expr<ipr::Greater>;
        using Greater_equal = Classic_binary_expr<ipr::Greater_equal>;
        using Less = Classic_binary_expr<ipr::Less>;
        using Less_equal = Classic_binary_expr<ipr::Less_equal>;
        using Literal = Conversion_expr<ipr::Literal>;
        using Lshift = Classic_binary_expr<ipr::Lshift>;
        using Lshift_assign = Classic_binary_expr<ipr::Lshift_assign>;

        struct Mapping : impl::Expr<ipr::Mapping> {
            impl::Parameter_list parameters;
            const ipr::Type* value_type;
            const ipr::Expr* body;
            const int nesting_level;

            Mapping(const ipr::Region&, const ipr::Type&, int);

            const ipr::Parameter_list& params() const final;
            const ipr::Type& result_type() const final;
            const ipr::Expr& result() const final;
            int depth() const final;
            impl::Parameter* param(const ipr::Name&, const impl::Rname&);
        };

        using Member_init = Binary_expr<ipr::Member_init>;
        using Minus = Classic_binary_expr<ipr::Minus>;
        using Minus_assign = Classic_binary_expr<ipr::Minus_assign>;
        using Modulo = Classic_binary_expr<ipr::Modulo>;
        using Modulo_assign = Classic_binary_expr<ipr::Modulo_assign>;
        using Mul = Classic_binary_expr<ipr::Mul>;
        using Mul_assign = Classic_binary_expr<ipr::Mul_assign>;
        using Not_equal = Classic_binary_expr<ipr::Not_equal>;
        using Or = Classic_binary_expr<ipr::Or>;
        using Plus = Classic_binary_expr<ipr::Plus>;
        using Plus_assign = Classic_binary_expr<ipr::Plus_assign>;
        using Reinterpret_cast = Conversion_expr<ipr::Reinterpret_cast>;
        using Rshift = Classic_binary_expr<ipr::Rshift>;
        using Rshift_assign = Classic_binary_expr<ipr::Rshift_assign>;
        using Scope_ref = Binary_expr<ipr::Scope_ref>;
        using Static_cast = Conversion_expr<ipr::Static_cast>;
        using Template_id = Binary_expr<ipr::Template_id>;

        using Conditional = Ternary<Classic<Expr<ipr::Conditional>>>;

        struct New : Classic<Expr<ipr::New>> {
            const ipr::Expr_list* where;
            const ipr::Type& what;
            const ipr::Expr_list* args;

            New(const ipr::Expr_list*, const ipr::Type&, const ipr::Expr_list*);
            Optional<ipr::Expr_list> placement() const final;
            const ipr::Type& allocated_type() const final;
            Optional<ipr::Expr_list> initializer() const final;
        };

        struct expr_factory {
            // Returns an IPR node for unified string literals.
            const ipr::String& get_string(const char*);
            const ipr::String& get_string(const std::string&);

            // Returns an IPR node a language linkage.
            const ipr::Linkage& get_linkage(const char*);
            const ipr::Linkage& get_linkage(const std::string&);
            const ipr::Linkage& get_linkage(const ipr::String&);

            Annotation* make_annotation(const ipr::String&, const ipr::Literal&);

            // Build a node for a missing expression of an unspecified type.
            Phantom* make_phantom();
            // Build an unspecified expression node of a given type.
            const ipr::Phantom* make_phantom(const ipr::Type&);

            // Returns an IPR node for a typed literal expression.
            Literal* make_literal(const ipr::Type&, const ipr::String&);
            Literal* make_literal(const ipr::Type&, const char*);
            Literal* make_literal(const ipr::Type&, const std::string&);

            // Builds an IPR object for an identifier.
            Identifier* make_identifier(const ipr::String&);
            Identifier* make_identifier(const char*);
            Identifier* make_identifier(const std::string&);

            // Builds an IPR object for an operator name.
            Operator* make_operator(const ipr::String&);
            Operator* make_operator(const char*);
            Operator* make_operator(const std::string&);

            Address* make_address(const ipr::Expr&);
            Array_delete* make_array_delete(const ipr::Expr&);
            Complement* make_complement(const ipr::Expr&);
            Conversion* make_conversion(const ipr::Type&);
            Ctor_name* make_ctor_name(const ipr::Type&);
            Delete* make_delete(const ipr::Expr&);
            Deref* make_deref(const ipr::Expr&);
            Dtor_name* make_dtor_name(const ipr::Type&);
            Expr_list* make_expr_list();
            Sizeof* make_sizeof(const ipr::Expr&);
            Typeid* make_typeid(const ipr::Expr&);
            Initializer_list* make_initializer_list(const ipr::Expr_list&);
            impl::Id_expr* make_id_expr(const ipr::Name&);
            Id_expr* make_id_expr(const ipr::Decl&);
            Not* make_not(const ipr::Expr&);
            Paren_expr* make_paren_expr(const ipr::Expr&);
            Post_increment* make_post_increment(const ipr::Expr&);
            Post_decrement* make_post_decrement(const ipr::Expr&);
            Pre_increment* make_pre_increment(const ipr::Expr&);
            Pre_decrement* make_pre_decrement(const ipr::Expr&);
            Throw* make_throw(const ipr::Expr&);
            Type_id* make_type_id(const ipr::Type&);
            Unary_minus* make_unary_minus(const ipr::Expr&);
            Unary_plus* make_unary_plus(const ipr::Expr&);
            Expansion* make_expansion(const ipr::Expr&);

            And* make_and(const ipr::Expr&, const ipr::Expr&);
            Array_ref* make_array_ref(const ipr::Expr&, const ipr::Expr&);
            Arrow* make_arrow(const ipr::Expr&, const ipr::Expr&);
            Arrow_star* make_arrow_star(const ipr::Expr&, const ipr::Expr&);
            Assign* make_assign(const ipr::Expr&, const ipr::Expr&);
            Bitand* make_bitand(const ipr::Expr&, const ipr::Expr&);
            Bitand_assign* make_bitand_assign(const ipr::Expr&, const ipr::Expr&);
            Bitor* make_bitor(const ipr::Expr&, const ipr::Expr&);
            Bitor_assign* make_bitor_assign(const ipr::Expr&, const ipr::Expr&);
            Bitxor* make_bitxor(const ipr::Expr&, const ipr::Expr&);
            Bitxor_assign* make_bitxor_assign(const ipr::Expr&, const ipr::Expr&);
            Cast* make_cast(const ipr::Type&, const ipr::Expr&);
            Call* make_call(const ipr::Expr&, const ipr::Expr_list&);
            Comma* make_comma(const ipr::Expr&, const ipr::Expr&);
            Const_cast* make_const_cast(const ipr::Type&, const ipr::Expr&);
            Datum* make_datum(const ipr::Type&, const ipr::Expr_list&);
            Div* make_div(const ipr::Expr&, const ipr::Expr&);
            Div_assign* make_div_assign(const ipr::Expr&, const ipr::Expr&);
            Dot* make_dot(const ipr::Expr&, const ipr::Expr&);
            Dot_star* make_dot_star(const ipr::Expr&, const ipr::Expr&);
            Dynamic_cast* make_dynamic_cast(const ipr::Type&, const ipr::Expr&);
            Equal* make_equal(const ipr::Expr&, const ipr::Expr&);
            Greater* make_greater(const ipr::Expr&, const ipr::Expr&);
            Greater_equal* make_greater_equal(const ipr::Expr&, const ipr::Expr&);
            Less* make_less(const ipr::Expr&, const ipr::Expr&);
            Less_equal* make_less_equal(const ipr::Expr&, const ipr::Expr&);
            Lshift* make_lshift(const ipr::Expr&, const ipr::Expr&);
            Lshift_assign* make_lshift_assign(const ipr::Expr&, const ipr::Expr&);
            Member_init* make_member_init(const ipr::Expr&, const ipr::Expr&);
            Minus* make_minus(const ipr::Expr&, const ipr::Expr&);
            Minus_assign* make_minus_assign(const ipr::Expr&, const ipr::Expr&);
            Modulo* make_modulo(const ipr::Expr&, const ipr::Expr&);
            Modulo_assign* make_modulo_assign(const ipr::Expr&, const ipr::Expr&);
            Mul* make_mul(const ipr::Expr&, const ipr::Expr&);
            Mul_assign* make_mul_assign(const ipr::Expr&, const ipr::Expr&);
            Not_equal* make_not_equal(const ipr::Expr&, const ipr::Expr&);
            Or* make_or(const ipr::Expr&, const ipr::Expr&);
            Plus* make_plus(const ipr::Expr&, const ipr::Expr&);
            Plus_assign* make_plus_assign(const ipr::Expr&, const ipr::Expr&);
            Reinterpret_cast* make_reinterpret_cast(const ipr::Type&,
                                                    const ipr::Expr&);
            Scope_ref* make_scope_ref(const ipr::Expr&, const ipr::Expr&);
            Rshift* make_rshift(const ipr::Expr&, const ipr::Expr&);
            Rshift_assign* make_rshift_assign(const ipr::Expr&, const ipr::Expr&);
            Template_id* make_template_id(const ipr::Name&,
                                          const ipr::Expr_list&);
            Static_cast* make_static_cast(const ipr::Type&, const ipr::Expr&);
            New* make_new(const ipr::Type&);
            New* make_new(const ipr::Type&, const ipr::Expr_list&);
            New* make_new(const ipr::Expr_list&, const ipr::Type&,
                          const ipr::Expr_list&);
            Conditional* make_conditional(const ipr::Expr&, const ipr::Expr&,
                                          const ipr::Expr&);

            Rname* rname_for_next_param(const Mapping&, const ipr::Type&);

            Mapping* make_mapping(const ipr::Region&, const ipr::Type&, int = 0);

        private:
            util::string::arena string_pool;
            util::rb_tree::container<impl::String> strings;

            // Language linkage nodes.
            util::rb_tree::container<impl::Linkage> linkages;

            util::rb_tree::container<impl::Conversion> convs;
            util::rb_tree::container<impl::Ctor_name> ctors;
            util::rb_tree::container<impl::Dtor_name> dtors;
            util::rb_tree::container<impl::Identifier> ids;
            util::rb_tree::container<impl::Literal> lits;
            util::rb_tree::container<impl::Operator> ops;
            util::rb_tree::container<impl::Rname> rnames;
            util::rb_tree::container<impl::Scope_ref> scope_refs;
            util::rb_tree::container<Template_id> template_ids;
            util::rb_tree::container<impl::Type_id> type_ids;
            util::rb_tree::container<impl::Sizeof> sizeofs;
            util::rb_tree::container<impl::Typeid> xtypeids;

            stable_farm<impl::Phantom> phantoms;

            stable_farm<impl::Address> addresses;
            stable_farm<impl::Annotation> annotations;
            stable_farm<impl::Array_delete> array_deletes;
            stable_farm<impl::Complement> complements;
            stable_farm<impl::Delete> deletes;
            stable_farm<impl::Deref> derefs;
            stable_farm<impl::Expr_list> xlists;
            stable_farm<impl::Id_expr> id_exprs;
            stable_farm<impl::Initializer_list> init_lists;
            stable_farm<impl::Not> nots;
            stable_farm<impl::Pre_increment> pre_increments;
            stable_farm<impl::Pre_decrement> pre_decrements;
            stable_farm<impl::Post_increment> post_increments;
            stable_farm<impl::Post_decrement> post_decrements;
            stable_farm<impl::Paren_expr> parens;
            stable_farm<impl::Throw> throws;
            stable_farm<impl::Unary_minus> unary_minuses;
            stable_farm<impl::Unary_plus> unary_pluses;
            stable_farm<impl::Expansion> expansions;

            stable_farm<impl::And> ands;
            stable_farm<impl::Array_ref> array_refs;
            stable_farm<impl::Arrow> arrows;
            stable_farm<impl::Arrow_star> arrow_stars;
            stable_farm<impl::Assign> assigns;
            stable_farm<impl::Bitand> bitands;
            stable_farm<impl::Bitand_assign> bitand_assigns;
            stable_farm<impl::Bitor> bitors;
            stable_farm<impl::Bitor_assign> bitor_assigns;
            stable_farm<impl::Bitxor> bitxors;
            stable_farm<impl::Bitxor_assign> bitxor_assigns;
            stable_farm<impl::Cast> casts;
            stable_farm<impl::Call> calls;
            stable_farm<impl::Comma> commas;
            stable_farm<impl::Const_cast> ccasts;
            stable_farm<impl::Datum> data;
            stable_farm<impl::Div> divs;
            stable_farm<impl::Div_assign> div_assigns;
            stable_farm<impl::Dot> dots;
            stable_farm<impl::Dot_star> dot_stars;
            stable_farm<impl::Dynamic_cast> dcasts;
            stable_farm<impl::Equal> equals;
            stable_farm<impl::Greater> greaters;
            stable_farm<impl::Greater_equal> greater_equals;
            stable_farm<impl::Less> lesses;
            stable_farm<impl::Less_equal> less_equals;
            stable_farm<impl::Lshift> lshifts;
            stable_farm<impl::Lshift_assign> lshift_assigns;
            stable_farm<impl::Member_init> member_inits;
            stable_farm<impl::Minus> minuses;
            stable_farm<impl::Minus_assign> minus_assigns;
            stable_farm<impl::Modulo> modulos;
            stable_farm<impl::Modulo_assign> modulo_assigns;
            stable_farm<impl::Mul> muls;
            stable_farm<impl::Mul_assign> mul_assigns;
            stable_farm<impl::Not_equal> not_equals;
            stable_farm<impl::Or> ors;
            stable_farm<impl::Plus> pluses;
            stable_farm<impl::Plus_assign> plus_assigns;
            stable_farm<impl::Reinterpret_cast> rcasts;
            stable_farm<impl::Rshift> rshifts;
            stable_farm<impl::Rshift_assign> rshift_assigns;
            stable_farm<impl::Static_cast> scasts;

            stable_farm<impl::New> news;
            stable_farm<impl::Conditional> conds;
            stable_farm<impl::Mapping> mappings;

            const ipr::String& get_string(const char*, int);
        };


        struct Named_map : impl::Decl<ipr::Named_map> {
            const ipr::Udt* member_of;
            impl::Mapping* init;
            const ipr::Region* lexreg;
            impl::Expr_list args;

            Named_map();

            const ipr::Named_map& primary_named_map() const;
            const ipr::Sequence<ipr::Decl>& specializations() const;
            const ipr::Mapping& mapping() const;
            Optional<ipr::Expr> initializer() const final;
            const ipr::Region& lexical_region() const;
        };

        template<>
        struct traits<ipr::Named_map> {
            using rep = impl::Named_map;
        };

        template<class Interface>
        struct decl_factory {
            stable_farm<decl_rep<Interface>> decls;
            stable_farm<master_decl_data<Interface>> master_info;

            // We have gotten an overload-set for a name, and we are about
            // to enter the first declaration for that name with the type T.
            decl_rep<Interface>* declare(Overload* ovl, const ipr::Type& t)
            {
                // Grab bookkeeping memory for this master declaration.
                master_decl_data<Interface>* data = master_info.make(ovl, t);
                // The actual representation for the declaration points back
                // to the master declaration bookkeeping store.
                decl_rep<Interface>* master = decls.make(data);
                // Inform the overload-set that we have a new master declaration.
                ovl->push_back(data);

                return master;
            }

            decl_rep<Interface>* redeclare(overload_entry* decl)
            {
                return decls.make
                        (static_cast<master_decl_data<Interface>*>(decl));
            }
        };


        struct Alias : impl::Decl<ipr::Alias> {
            const ipr::Expr* aliasee;
            const ipr::Region* lexreg;

            Alias();
            Optional<ipr::Expr> initializer() const final;
            const ipr::Region& lexical_region() const;
        };

        template<>
        struct traits<ipr::Alias> {
            using rep = impl::Alias;
        };

        struct Var : impl::Decl<ipr::Var> {
            const ipr::Expr* init;
            const ipr::Region* lexreg;

            Var();

            Optional<ipr::Expr> initializer() const final;
            const ipr::Region& lexical_region() const final;
        };

        template<>
        struct traits<ipr::Var> {
            using rep = impl::Var;
        };

        // FIXME: Field should use unique_decl, not impl::Decl.
        struct Field : impl::Decl<ipr::Field> {
            const ipr::Udt* member_of;
            const ipr::Expr* init;

            Field();

            const ipr::Udt& membership() const final;

            // Override ipr::Decl::lexical_region.  Which is the
            // same as home_region for a Field.  Note that fields
            // are always nonstatic data members.
            const ipr::Region& lexical_region() const final;
            const ipr::Region& home_region() const final;
            Optional<ipr::Expr> initializer() const final;
        };

        template<>
        struct traits<ipr::Field> {
            using rep = impl::Field;
        };

        // FIXME: Bitfield should use unique_decl, not impl::Decl
        struct Bitfield : impl::Decl<ipr::Bitfield> {
            const ipr::Expr* length;
            const ipr::Udt* member_of;
            const ipr::Expr* init;

            Bitfield();

            const ipr::Expr& precision() const final;
            const ipr::Region& lexical_region() const final;
            const ipr::Region& home_region() const final;
            const ipr::Udt& membership() const final;
            Optional<ipr::Expr> initializer() const final;
        };

        template<>
        struct traits<ipr::Bitfield> {
            using rep = impl::Bitfield;
        };

        struct Typedecl : impl::Decl<ipr::Typedecl> {
            const ipr::Type* init;
            const ipr::Udt* member_of;
            const ipr::Region* lexreg;

            Typedecl();

            const ipr::Udt& membership() const final;
            Optional<ipr::Expr> initializer() const final;
            const ipr::Region& lexical_region() const final;
        };

        template<>
        struct traits<ipr::Typedecl> {
            using rep = impl::Typedecl;
        };

        struct Fundecl : impl::Decl<ipr::Fundecl> {
            const ipr::Udt* member_of;
            impl::Mapping* init;
            const ipr::Region* lexreg;

            Fundecl();

            const ipr::Mapping& mapping() const final;
            const ipr::Udt& membership() const final;
            Optional<ipr::Expr> initializer() const final;
            const ipr::Region& lexical_region() const final;
        };

        template<>
        struct traits<ipr::Fundecl> {
            using rep = impl::Fundecl;
        };


        // A heterogeneous scope is a sequence of declarations of
        // almost of kinds.  The omitted kinds being parameters,
        // base-class subobjects and enumerators.   Those form
        // a homogeneous scope, implemented by homogeneous_scope.

        struct Scope : impl::Node<ipr::Scope> {
            Scope(const ipr::Region&, const ipr::Type&);

            const ipr::Type& type() const;
            const ipr::Sequence<ipr::Decl>& members() const;
            const ipr::Overload& operator[](const ipr::Name&) const;

            impl::Alias* make_alias(const ipr::Name&, const ipr::Expr&);
            impl::Var* make_var(const ipr::Name&, const ipr::Type&);
            impl::Field* make_field(const ipr::Name&, const ipr::Type&);
            impl::Bitfield* make_bitfield(const ipr::Name&, const ipr::Type&);
            impl::Typedecl* make_typedecl(const ipr::Name&, const ipr::Type&);
            impl::Fundecl* make_fundecl(const ipr::Name&, const ipr::Function&);
            impl::Named_map* make_primary_map(const ipr::Name&,
                                              const ipr::Template&);
            impl::Named_map* make_secondary_map(const ipr::Name&,
                                                const ipr::Template&);

        private:
            const ipr::Region& region;
            util::rb_tree::container<impl::Overload> overloads;
            typed_sequence<decl_sequence> decls;
            empty_overload missing;

            decl_factory<ipr::Alias> aliases;
            decl_factory<ipr::Var> vars;
            decl_factory<ipr::Field> fields;
            decl_factory<ipr::Bitfield> bitfields;
            decl_factory<ipr::Fundecl> fundecls;
            decl_factory<ipr::Typedecl> typedecls;
            decl_factory<ipr::Named_map> primary_maps;
            decl_factory<ipr::Named_map> secondary_maps;

            template<class T> inline void add_member(T*);
        };


        // A heterogeneous region is a region of program text that
        // contains heterogeneous scope (as defined above).

        struct Region : impl::Node<ipr::Region> {
            using location_span = ipr::Region::Location_span;
            const ipr::Region* parent;
            location_span extent;
            const ipr::Expr* owned_by;
            impl::Scope scope;

            const ipr::Region& enclosing() const;
            const ipr::Scope& bindings() const;
            const location_span& span() const;
            const ipr::Expr& owner() const;

            impl::Region* make_subregion();

            // Convenient functions, forwarding to those of SCOPE.
            impl::Alias* declare_alias(const ipr::Name& n, const ipr::Type& t)
            {
                return scope.make_alias(n, t);
            }

            impl::Var* declare_var(const ipr::Name& n, const ipr::Type& t)
            {
                return scope.make_var(n, t);
            }

            impl::Field* declare_field(const ipr::Name& n, const ipr::Type& t)
            {
                return scope.make_field(n, t);
            }

            impl::Bitfield* declare_bitfield(const ipr::Name& n,
                                             const ipr::Type& t)
            {
                return scope.make_bitfield(n, t);
            }

            Typedecl* declare_type(const ipr::Name& n, const ipr::Type& t)
            {
                return scope.make_typedecl(n, t);
            }

            Fundecl* declare_fun(const ipr::Name& n, const ipr::Function& t)
            {
                return scope.make_fundecl(n, t);
            }

            Named_map* declare_primary_map(const ipr::Name& n,
                                           const ipr::Template& t)
            {
                return scope.make_primary_map(n, t);
            }

            Named_map* declare_secondary_map(const ipr::Name& n,
                                             const ipr::Template& t)
            {
                return scope.make_secondary_map(n, t);
            }

            Region(const ipr::Region*, const ipr::Type&);

        private:
            stable_farm<Region> subregions;
        };


        // Implement common operations for user-defined types.  The case
        // of enums is handled separately because its body is a
        // homogeneous region.

        template<class Interface>
        struct Udt : impl::Type<Interface> {
            Region body;
            Udt(const ipr::Region* pr, const ipr::Type& t) : body(pr, t)
            {
                this->constraint = &t;
                body.owned_by = this;
            }

            const ipr::Region& region() const final { return body; }

            impl::Alias*
            declare_alias(const ipr::Name& n, const ipr::Type& t)
            {
                impl::Alias* alias = body.declare_alias(n, t);
                //alias->member_of = this; // FIX: Add member_of to Alias
                return alias;
            }

            impl::Field*
            declare_field(const ipr::Name& n, const ipr::Type& t)
            {
                impl::Field* field = body.declare_field(n, t);
                field->member_of = this;
                return field;
            }

            impl::Bitfield*
            declare_bitfield(const ipr::Name& n, const ipr::Type& t)
            {
                impl::Bitfield* field = body.declare_bitfield(n, t);
                field->member_of = this;
                return field;
            }

            impl::Var*
            declare_var(const ipr::Name& n, const ipr::Type& t)
            {
                impl::Var* var = body.declare_var(n, t);
                return var;
            }

            impl::Typedecl*
            declare_type(const ipr::Name& n, const ipr::Type& t)
            {
                impl::Typedecl* typedecl = body.declare_type(n, t);
                typedecl->member_of = this;
                return typedecl;
            }

            impl::Fundecl*
            declare_fun(const ipr::Name& n, const ipr::Function& t)
            {
                impl::Fundecl* fundecl = body.declare_fun(n, t);
                fundecl->member_of = this;
                return fundecl;
            }

            impl::Named_map*
            declare_primary_map(const ipr::Name& n, const ipr::Template& t)
            {
                impl::Named_map* map = body.declare_primary_map(n, t);
                map->member_of = this;
                return map;
            }

            impl::Named_map*
            declare_secondary_map(const ipr::Name& n, const ipr::Template& t)
            {
                impl::Named_map* map = body.declare_secondary_map(n, t);
                map->member_of = this;
                return map;
            }
        };

        struct Enum : impl::Type<ipr::Enum> {
            homogeneous_region<ipr::Enumerator> body;
            const Kind enum_kind;

            const ipr::Region& region() const final;
            const Sequence<ipr::Enumerator>& members() const final;
            Kind kind() const final;
            impl::Enumerator* add_member(const ipr::Name&);

            Enum(const ipr::Region&, const ipr::Type&, Kind);
        };

        using Union = Udt<ipr::Union>;
        using Namespace = Udt<ipr::Namespace>;

        struct Class : impl::Udt<ipr::Class> {
            homogeneous_region<ipr::Base_type> base_subobjects;

            Class(const ipr::Region&, const ipr::Type&);

            const ipr::Sequence<ipr::Base_type>& bases() const final;
            impl::Base_type* declare_base(const ipr::Type&);

        };

        struct Auto : impl::Type<ipr::Auto> {
        };

        // This class is responsible for creating nodes that
        // represent types.  It is responsible for the storage
        // management that is implied.  Notice that the type nodes
        // created by this class may need additional processing such
        // as setting their types (as expressions) and their names.

        struct type_factory {
            // Build an IPR node for an expression that denotes a type.
            // The linkage, if not specified, is assumed to be C++.
            impl::As_type* make_as_type(const ipr::Expr&);
            impl::As_type* make_as_type(const ipr::Expr&, const ipr::Linkage&);

            impl::Array* make_array(const ipr::Type&, const ipr::Expr&);
            impl::Qualified* make_qualified(ipr::Type_qualifier,
                                            const ipr::Type&);
            impl::Decltype* make_decltype(const ipr::Expr&);
            impl::Function* make_function(const ipr::Product&, const ipr::Type&,
                                          const ipr::Sum&, const ipr::Linkage&);
            impl::Pointer* make_pointer(const ipr::Type&);
            impl::Product* make_product(const ipr::Sequence<ipr::Type>&);
            impl::Ptr_to_member* make_ptr_to_member(const ipr::Type&,
                                                    const ipr::Type&);
            impl::Reference* make_reference(const ipr::Type&);
            impl::Rvalue_reference* make_rvalue_reference(const ipr::Type&);
            impl::Sum* make_sum(const ipr::Sequence<ipr::Type>&);
            impl::Template* make_template(const ipr::Product&, const ipr::Type&);

            impl::Enum* make_enum(const ipr::Region&, const ipr::Type&, Enum::Kind);
            impl::Class* make_class(const ipr::Region&, const ipr::Type&);
            impl::Union* make_union(const ipr::Region&, const ipr::Type&);
            impl::Namespace* make_namespace(const ipr::Region*, const ipr::Type&);

        private:
            util::rb_tree::container<impl::Array> arrays;
            util::rb_tree::container<impl::Decltype> decltypes;
            util::rb_tree::container<impl::As_type> type_refs;
            util::rb_tree::container<impl::Function> functions;
            util::rb_tree::container<impl::Pointer> pointers;
            util::rb_tree::container<impl::Product> products;
            util::rb_tree::container<impl::Ptr_to_member> member_ptrs;
            util::rb_tree::container<impl::Qualified> qualifieds;
            util::rb_tree::container<impl::Reference> references;
            util::rb_tree::container<impl::Rvalue_reference> refrefs;
            util::rb_tree::container<impl::Sum> sums;
            util::rb_tree::container<impl::Template> templates;
            stable_farm<impl::Enum> enums;
            stable_farm<impl::Class> classes;
            stable_farm<impl::Union> unions;
            stable_farm<impl::Namespace> namespaces;
        };


        // ----------------------------------
        // -- Implementation of statements --
        // ----------------------------------

        using Ctor_body = Binary<Stmt<Expr<ipr::Ctor_body>>>;
        using Do = type_from_second<Stmt<Node<ipr::Do>>>;
        using Expr_stmt = type_from_operand<Stmt<Node<ipr::Expr_stmt>>>;
        using Empty_stmt = type_from_operand<Stmt<Node<ipr::Empty_stmt>>>;
        using Goto = type_from_operand<Stmt<Node<ipr::Goto>>>;
        using Handler = type_from_second<Stmt<Node<ipr::Handler>>>;
        using If_then = type_from_second<Stmt<Node<ipr::If_then>>>;
        using If_then_else = Ternary<Stmt<Expr<ipr::If_then_else>>>;
        using Labeled_stmt = type_from_second<Stmt<Node<ipr::Labeled_stmt>>>;
        using Return = type_from_operand<Stmt<Node<ipr::Return>>>;
        using Switch = type_from_second<Stmt<Node<ipr::Switch>>>;
        using While = type_from_second<Stmt<Node<ipr::While>>>;

        // A Block holds a heterogeneous region, suitable for
        // recording the set of declarations appearing in that
        // block.  It also holds a sequence of handlers, when the
        // block actually represents a C++ try-block.

        struct Block : impl::Stmt<Node<ipr::Block>> {
            Region region;
            ref_sequence<ipr::Stmt> stmt_seq;
            ref_sequence<ipr::Handler> handler_seq;

            Block(const ipr::Region&, const ipr::Type&);

            const ipr::Type& type() const final;
            const ipr::Scope& members() const final;
            const ipr::Sequence<ipr::Stmt>& body() const final;
            const ipr::Sequence<ipr::Handler>& handlers() const final;

            // The scope of declarations in this block
            Scope* scope() { return &region.scope; }

            void add_stmt(const ipr::Stmt* s)
            {
                stmt_seq.push_back(s);
            }

            void add_handler(const ipr::Handler* h)
            {
                handler_seq.push_back(h);
            }
        };


        // A for-statement node in its most general form is a quaternry
        // expresion; for flexibility, it is made in a way that
        // supports settings of its components after construction.

        struct For : Stmt<Expr<ipr::For>> {
            const ipr::Expr* init;
            const ipr::Expr* cond;
            const ipr::Expr* inc;
            const ipr::Stmt* stmt;

            For();

            const ipr::Type& type() const final;
            const ipr::Expr& initializer() const final;
            const ipr::Expr& condition() const final;
            const ipr::Expr& increment() const final;
            const ipr::Stmt& body() const final;
        };

        struct For_in : Stmt<Expr<ipr::For_in>> {
            const ipr::Var* var;
            const ipr::Expr* seq;
            const ipr::Stmt* stmt;

            For_in();

            const ipr::Type& type() const final;
            const ipr::Var& variable() const final;
            const ipr::Expr& sequence() const final;
            const ipr::Stmt& body() const final;
        };


        // A Break node can record the selction- of iteration-statement it
        // transfers control out of.

        struct Break : Stmt<Node<ipr::Break>> {
            const ipr::Stmt* stmt;

            Break();
            const ipr::Type& type() const final;
            const ipr::Stmt& from() const final;
        };

        // Like a Break, a Continue node can refer back to the
        // iteration-statement containing it.
        struct Continue : Stmt<Node<ipr::Continue>> {
            const ipr::Stmt* stmt;

            Continue();
            const ipr::Type& type() const final;
            const ipr::Stmt& iteration() const final;
        };


        // This factory class takes on the implementation burden of
        // allocating storage for statement nodes and their constructions.

        struct stmt_factory : expr_factory {
            impl::Break* make_break();
            impl::Continue* make_continue();
            impl::Empty_stmt* make_empty_stmt();
            impl::Block* make_block(const ipr::Region&, const ipr::Type&);
            impl::Ctor_body* make_ctor_body(const ipr::Expr_list&,
                                            const ipr::Block&);
            impl::Expr_stmt* make_expr_stmt(const ipr::Expr&);
            impl::Goto* make_goto(const ipr::Expr&);
            impl::Return* make_return(const ipr::Expr&);
            impl::Do* make_do(const ipr::Stmt&, const ipr::Expr&);
            impl::If_then* make_if_then(const ipr::Expr&, const ipr::Stmt&);
            impl::Switch* make_switch(const ipr::Expr&, const ipr::Stmt&);
            impl::Handler* make_handler(const ipr::Decl&, const ipr::Block&);
            impl::Labeled_stmt* make_labeled_stmt(const ipr::Expr&,
                                                  const ipr::Stmt&);
            impl::While* make_while(const ipr::Expr&, const ipr::Stmt&);
            impl::If_then_else* make_if_then_else(const ipr::Expr&,
                                                  const ipr::Stmt&,
                                                  const ipr::Stmt&);
            impl::For* make_for();
            impl::For_in* make_for_in();

        protected:
            stable_farm<impl::Break> breaks;
            stable_farm<impl::Continue> continues;
            stable_farm<impl::Empty_stmt> empty_stmts;
            stable_farm<impl::Block> blocks;
            stable_farm<impl::Expr_stmt> expr_stmts;
            stable_farm<impl::Goto> gotos;
            stable_farm<impl::Return> returns;
            stable_farm<impl::Ctor_body> ctor_bodies;
            stable_farm<impl::Do> dos;
            stable_farm<impl::If_then> ifs;
            stable_farm<impl::Handler> handlers;
            stable_farm<impl::Labeled_stmt> labeled_stmts;
            stable_farm<impl::Switch> switches;
            stable_farm<impl::While> whiles;
            stable_farm<impl::If_then_else> ifelses;
            stable_farm<impl::For> fors;
            stable_farm<impl::For_in> for_ins;
        };


        // This template will be instantiated to implementations
        // of several builtin type singletons.  It does not reuse
        // implementations of Type, and Binary, to save space since
        // most data needed by those implementations are shared.
        template<class T>
        struct Builtin : impl::Expr<T> {
            using Arg1_type = typename T::Arg1_type;
            using Arg2_type = typename T::Arg2_type;
            Builtin(const ipr::Name& n, Arg2_type l, const ipr::Type& t)
                    : impl::Expr<T>(&t), id(n), link(l) { }

            const ipr::Name& name() const { return id; }
            Arg1_type first() const { return id; }
            Arg2_type second() const { return link; }

        private:
            const ipr::Name& id;
            Arg2_type link;
        };


        // -- impl::Lexicon --
        struct Lexicon : ipr::Lexicon, stmt_factory {
            Lexicon();
            ~Lexicon();

            const ipr::Linkage& cxx_linkage() const final;
            const ipr::Linkage& c_linkage() const final;

            const ipr::Identifier& get_identifier(const char*);
            const ipr::Identifier& get_identifier(const std::string&);
            const ipr::Identifier& get_identifier(const ipr::String&);

            const ipr::Operator& get_operator(const char*);
            const ipr::Operator& get_operator(const std::string&);
            const ipr::Operator& get_operator(const ipr::String&);

            const ipr::Ctor_name& get_ctor_name(const ipr::Type&);
            const ipr::Dtor_name& get_dtor_name(const ipr::Type&);

            const ipr::Conversion& get_conversion(const ipr::Type&);

            const ipr::Scope_ref& get_scope_ref(const ipr::Expr&,
                                                const ipr::Expr&);

            const ipr::Template_id& get_template_id(const ipr::Name&,
                                                    const ipr::Expr_list&);

            const ipr::Literal& get_literal(const ipr::Type&, const char*);
            const ipr::Literal& get_literal(const ipr::Type&, const std::string&);
            const ipr::Literal& get_literal(const ipr::Type&, const ipr::String&);

            const ipr::Type& void_type() const final;
            const ipr::Type& bool_type() const final;

            const ipr::Type& char_type() const final;
            const ipr::Type& schar_type() const final;
            const ipr::Type& uchar_type() const final;
            const ipr::Type& wchar_t_type() const final;

            const ipr::Type& short_type() const final;
            const ipr::Type& ushort_type() const final;

            const ipr::Type& int_type() const final;
            const ipr::Type& uint_type() const final;

            const ipr::Type& long_type() const final;
            const ipr::Type& ulong_type() const final;

            const ipr::Type& long_long_type() const final;
            const ipr::Type& ulong_long_type() const final;

            const ipr::Type& float_type() const final;
            const ipr::Type& double_type() const final;
            const ipr::Type& long_double_type() const final;

            const ipr::Type& ellipsis_type() const final;

            const ipr::Type& typename_type() const final;
            const ipr::Type& class_type() const final;
            const ipr::Type& union_type() const final;
            const ipr::Type& enum_type() const final;
            const ipr::Type& namespace_type() const final;

            const ipr::Array& get_array(const ipr::Type&, const ipr::Expr&);

            const ipr::As_type& get_as_type(const ipr::Expr&);
            const ipr::As_type& get_as_type(const ipr::Expr&,
                                            const ipr::Linkage&);

            const ipr::Decltype& get_decltype(const ipr::Expr&);

            const ipr::Function& get_function(const ipr::Product&,
                                              const ipr::Type&, const ipr::Sum&);
            const ipr::Function& get_function(const ipr::Product&,
                                              const ipr::Type&);
            const ipr::Function& get_function(const ipr::Product&,
                                              const ipr::Type&,
                                              const ipr::Sum&,
                                              const ipr::Linkage&);
            const ipr::Function& get_function(const ipr::Product&,
                                              const ipr::Type&,
                                              const ipr::Linkage&);

            const ipr::Pointer& get_pointer(const ipr::Type&);

            const ipr::Product& get_product(const ref_sequence<ipr::Type>&);

            const ipr::Ptr_to_member& get_ptr_to_member(const ipr::Type&,
                                                        const ipr::Type&);

            const ipr::Reference& get_reference(const ipr::Type&);
            const ipr::Rvalue_reference& get_rvalue_reference(const ipr::Type&);

            const ipr::Qualified& get_qualified(ipr::Type_qualifier,
                                                const ipr::Type&);

            const ipr::Sum& get_sum(const ref_sequence<ipr::Type>&);

            const ipr::Template& get_template(const ipr::Product&,
                                              const ipr::Type&);

            impl::Mapping* make_mapping(const ipr::Region&);
            impl::Parameter* make_parameter(const ipr::Name&, const ipr::Type&,
                                            impl::Mapping&);

            impl::Class* make_class(const ipr::Region&);
            impl::Enum* make_enum(const ipr::Region&, Enum::Kind);
            impl::Namespace* make_namespace(const ipr::Region&);
            impl::Union* make_union(const ipr::Region&);

            int make_fileindex(const ipr::String&);
            const ipr::String& to_filename(int) const;

            const impl::Token* make_token(const ipr::String&,
                                          const Source_location&,
                                          TokenValue, TokenCategory);

            const ipr::Auto& get_auto();

        private:
            void record_builtin_type(const ipr::As_type&);

            using Filemap = stable_farm<impl::String>;
            Filemap filemap;
            stable_farm<impl::Token> tokens;
            type_factory types;
            util::rb_tree::container<ref_sequence<ipr::Expr>> expr_seqs;
            util::rb_tree::container<ref_sequence<ipr::Type>> type_seqs;
            util::rb_tree::container<node_ref<ipr::As_type>> builtin_map;
            stable_farm<impl::Auto> autos;

            const impl::Builtin<ipr::As_type> anytype;
            const impl::Builtin<ipr::As_type> classtype;
            const impl::Builtin<ipr::As_type> uniontype;
            const impl::Builtin<ipr::As_type> enumtype;
            const impl::Builtin<ipr::As_type> namespacetype;
            const impl::Builtin<ipr::As_type> voidtype;
            const impl::Builtin<ipr::As_type> booltype;
            const impl::Builtin<ipr::As_type> chartype;
            const impl::Builtin<ipr::As_type> schartype;
            const impl::Builtin<ipr::As_type> uchartype;
            const impl::Builtin<ipr::As_type> wchar_ttype;
            const impl::Builtin<ipr::As_type> shorttype;
            const impl::Builtin<ipr::As_type> ushorttype;
            const impl::Builtin<ipr::As_type> inttype;
            const impl::Builtin<ipr::As_type> uinttype;
            const impl::Builtin<ipr::As_type> longtype;
            const impl::Builtin<ipr::As_type> ulongtype;
            const impl::Builtin<ipr::As_type> longlongtype;
            const impl::Builtin<ipr::As_type> ulonglongtype;
            const impl::Builtin<ipr::As_type> floattype;
            const impl::Builtin<ipr::As_type> doubletype;
            const impl::Builtin<ipr::As_type> longdoubletype;
            const impl::Builtin<ipr::As_type> ellipsistype;

            template<class T> T* finish_type(T*);
        };

        template<typename T>
        struct unit_base : T {
            unit_base(impl::Lexicon& l)
                    : context{ l },
                      global_ns{ nullptr, context.namespace_type() }
            {
                global_ns.id = &context.get_identifier("");
            }

            void accept(Translation_unit::Visitor& v) const override {
                v.visit(*this);
            }

            const ipr::Global_scope& global_namespace() const final {
                return global_ns;
            }

            const ipr::Sequence<ipr::Module>& imported_modules() const final {
                return modules_imported;
            }

            Region* global_region() { return &global_ns.body; }
            Scope* global_scope() { return &global_ns.body.scope; }
            ref_sequence<ipr::Module>* imports() { return &modules_imported; }

        private:
            impl::Lexicon& context;
            impl::Udt<ipr::Global_scope> global_ns;
            ref_sequence<ipr::Module> modules_imported;
        };

        template<typename T>
        struct basic_unit : unit_base<T> {
            const ipr::Module& parent;
            impl::ref_sequence<ipr::Decl> owned_decls;

            basic_unit(impl::Lexicon& l, const ipr::Module& m)
                    : unit_base<T>{ l }, parent{ m }
            { }
            const ipr::Module& parent_module() const final { return parent; }
            const ipr::Sequence<ipr::Decl>& purview() const final {
                return owned_decls;
            }
        };

        using Translation_unit = unit_base<ipr::Translation_unit>;
        using Module_unit = basic_unit<ipr::Module_unit>;

        struct Interface_unit : basic_unit<ipr::Interface_unit> {
            impl::ref_sequence<ipr::Module> modules_exported;
            impl::ref_sequence<ipr::Decl> decls_exported;

            Interface_unit(impl::Lexicon&, const ipr::Module&);
            const ipr::Sequence<ipr::Module>& exported_modules() const final;
            const ipr::Sequence<ipr::Decl>& exported_declarations() const final;
        };

        struct Module : ipr::Module {
            using ImplUnits = impl::val_sequence<impl::Module_unit, ipr::Sequence<ipr::Module_unit>>;
            impl::Lexicon& lexicon;
            impl::Module_name stems;
            impl::Interface_unit iface;
            ImplUnits units;

            Module(impl::Lexicon&);
            const ipr::Module_name& name() const final;
            const ipr::Interface_unit& interface_unit() const final;
            const ipr::Sequence<ipr::Module_unit>& implementation_units() const final;
            impl::Module_unit* make_unit();
        };
    }
}

#endif
