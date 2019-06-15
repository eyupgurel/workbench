//
// Created by egl on 6/13/19.
//

#ifndef WORKBENCH__TUPLE_H
#define WORKBENCH__TUPLE_H
#include <iostream>
#include <vector>
#include <string>
#include "../metaprogramming/metaprogramming.h"
using namespace std;
using namespace metaprogramming;
namespace containers{

    template<typename... Tail> class _tuple;
    template<> class _tuple<>{};
    template<typename Head, typename... Tail>
    class _tuple<Head, Tail...>:private _tuple<Tail...>{
        /*
        Basically, a tuple stores its head (first (type,value) pairs)
        and derives from the tuple of its tail (the rest of the (type/value) pairs).
        Note that the type is encoded in the type, not stored as data
        */
        using inherited = _tuple<Tail...>;

    public:
        constexpr _tuple(){}//default:the empty tuple
        // Construct tuple from separate arguments:

   /*     _tuple(Add_const_reference<Head> head,
               Add_const_reference <Tail>... tail):
        m_head{head},inherited{tail...}{
        }

        _tuple(Add_rvalue_reference<Head> head,
               Add_rvalue_reference <Tail>... tail):
                m_head{std::move(head)},inherited{std::move(tail)...}{
        }
    */
        template <typename _Head, typename... _Tail>
        _tuple(_Head&& head,_Tail&&... tail):m_head{forward<_Head>(head)},
                                            inherited{forward<_Tail>(tail)...}{

        }

        // Construct tuple from another tuple:
        template<typename... Values>
        _tuple(const _tuple<Values...>& other):m_head{other.head()},inherited{other.tail()}{}
        template<typename... Values>
        _tuple& operator=(const _tuple<Values...>& other){
            m_head=other.head();
            tail()=other.tail();
            return *this;
        }
    protected:
        Head m_head;
    private:
        Add_lvalue_reference<Head> head(){return m_head;}
        Add_const_reference<Head> head()const{return m_head;}
        inherited& tail(){return static_cast<inherited&>(*this);}
        const inherited& tail()const{return static_cast<const inherited&>(this);}
    };

    template<typename... _Elements>
    constexpr _tuple<typename __decay_and_strip<_Elements>::__type...>
    __make_tuple(_Elements&&... __args)
    {
        typedef _tuple<typename __decay_and_strip<_Elements>::__type...>
                __result_type;
        return __result_type{std::forward<_Elements>(__args)...};
    }


    class Nil{};

    template<typename T1=Nil,typename T2=Nil,typename T3=Nil,typename T4=Nil>
    struct Tuple:Tuple<T2,T3,T4>{
        T1 elem;
        using Base=Tuple<T2,T3,T4>;
        Base* tail(){return static_cast<Base*>(this);}
        const Base* tail()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1,const T2& t2,const T3& t3,const T4& t4):Base{t2,t3,t4},elem{t1}{}
    };

    template<>
    struct Tuple<>{
        Tuple(){}
    };

    template<typename T1>
    struct Tuple<T1>:Tuple<>{
        T1 elem;
        using Base=Tuple<>;
        Base* tail(){return static_cast<Base*>(this);}
        const Base* tail()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1):Base{},elem{t1}{}
    };

    template<typename T1,typename T2>
    struct Tuple<T1,T2>:Tuple<T2>{
        T1 elem;
        using Base=Tuple<T2>;
        Base* tail(){return static_cast<Base*>(this);}
        const Base* tail()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1,const T2& t2):Base{t2},elem{t1}{}
    };

    template<typename T1,typename T2,typename T3>
    struct Tuple<T1,T2,T3>:Tuple<T2,T3>{
        T1 elem;
        using Base=Tuple<T2,T3>;
        Base* tail(){return static_cast<Base*>(this);}
        const Base* tail()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1,const T2& t2,const T3& t3):Base{t2,t3},elem{t1}{}
    };

    template<typename Ret, int N>
    struct getNth{
        template<typename T>
        static Ret& get(T&t){
            return getNth<Ret,N-1>::get(*t.tail());
        }

        template<typename T>
        static const Ret& get(const T&t){
            return getNth<Ret,N-1>::get(*t.tail());
        }
    };

    template<typename Ret>
    struct getNth<Ret,0>{
        template<typename T>
        static Ret& get(T&t){
            return t.elem;
        }

        template<typename T>
        static const Ret& get(const T&t){
            return t.elem;
        }
    };

    template<int N, typename T1, typename T2, typename T3, typename T4>
    Select<N, T1, T2, T3, T4>& get(Tuple<T1, T2, T3, T4>& t)
    {
        return getNth<Select<N, T1, T2, T3, T4>,N>::get(t);
    }

    template<int N, typename T1, typename T2, typename T3, typename T4>
    const Select<N, T1, T2, T3, T4>& get(const Tuple<T1, T2, T3, T4>& t)
    {
        return getNth<Select<N, T1, T2, T3, T4>,N>::get(t);
    }


    template<typename T1, typename T2, typename T3, typename T4>
    void print_elements(ostream& os, const Tuple<T1,T2,T3,T4>& t)
    {
        os << t.elem << ", ";
        print_elements(os,*t.tail());
    }
    template<typename T1, typename T2, typename T3>
    void print_elements(ostream& os, const Tuple<T1,T2,T3>& t)
    {
        os << t.elem << ", ";
        print_elements(os,*t.tail());
    }
    template<typename T1, typename T2>
    void print_elements(ostream& os, const Tuple<T1,T2>& t)
    {
        os << t.elem << ", ";
        print_elements(os,*t.tail());
    }
    template<typename T1>
    void print_elements(ostream& os, const Tuple<T1>& t)
    {
        os << t.elem;
        print_elements(os,*t.tail());
    }
    template<>
    void print_elements(ostream& os, const Tuple<>& t)
    {
        os << "";
    }

    template<typename T1, typename T2, typename T3, typename T4>
    ostream& operator<<(ostream& os, const Tuple<T1,T2,T3,T4>& t)
    {
        os << "{ ";
        print_elements(os,t);
        os << " }";
        return os;
    }


}
#endif //WORKBENCH__TUPLE_H
