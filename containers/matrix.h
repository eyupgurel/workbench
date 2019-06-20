//
// Created by egl on 6/17/19.
//

#ifndef WORKBENCH_MATRIX_H
#define WORKBENCH_MATRIX_H


#include <vector>
#include <assert.h>
#include "../metaprogramming/metaprogramming.h"

using namespace std;
using namespace metaprogramming;
namespace containers{

    template<typename M>
    using Value_type=typename M::value_type;

    template<typename T, size_t N>
    struct Matrix_init {
        using type = initializer_list<typename Matrix_init<T,N-1>::type>;
    };

    template<typename T>
    struct Matrix_init<T,1> {
        using type = initializer_list<T>;
    };

    template<typename T>
    struct Matrix_init<T,0>; // undefined on purpose

    template<typename T, size_t N>
    using Matrix_initializer = typename Matrix_init<T, N>::type;


    struct slice {
        slice() :start(-1), length(-1), stride(1) { }
        explicit slice(size_t s) :start(s), length(-1), stride(1) { }
        slice(size_t s, size_t l, size_t n = 1) :start(s), length(l), stride(n) { }
        size_t operator()(size_t i) const { return start+i*stride; }
        static slice all;
        size_t start;// first index
        size_t length;// number of indices included (can be used for range checking)
        size_t stride;// distance between elements in sequence
    };

    template<size_t N>
    struct Matrix_slice {
        Matrix_slice() = default;// an empty matrix: no elements

        Matrix_slice(size_t s, initializer_list<size_t> exts); // extents
        Matrix_slice(size_t s, initializer_list<size_t> exts, initializer_list<size_t> strs);// extents and strides
        template<typename... Dims>// N extents
        Matrix_slice(Dims... dims){

        };

        template<typename... Dims,
                typename = Enable_if<All(Convertible<Dims,size_t>()...)>>
        size_t operator()(Dims... dims) const{// calculate index from a set of subscripts
            static_assert(sizeof...(Dims)==N,"Error in dimension!");
            size_t args[N]{sizeof(Dims)...}; //copy argument into an array
            return inner_product(args,args+N,strides.begin(),size_t{0});
        };

        size_t size;    // total number of elements
        size_t start;   // starting offset
        array<size_t,N> extents;    // number of elements in each dimension
        array<size_t,N> strides;    // offsets between elements in each dimension
    };

    template<typename T, size_t N>
    class Matrix_ref {
    public:
        Matrix_ref(const Matrix_slice<N>& s, T* p) :desc{s}, ptr{p} {}
// ... mostly like Matr ix ...
    private:
        Matrix_slice<N> desc;
        T* ptr;
    };


    constexpr bool All() { return true; }

    template<typename... Args>
    constexpr bool All(bool b, Args... args)
    {
        return b && All(args...);
    }

    template<typename... Args>
    constexpr bool Requesting_element()
    {
        return All(Convertible<Args,size_t>()...);
    }


    template<typename... Args>
    constexpr bool Requesting_slice()
    {
        return All((Convertible<Args,size_t>() || Is_same<Args,slice>())...)
        && Some(Is_same<Args,slice>()...);
    }


    template<typename List>
    bool check_non_jagged(const List& list)
    {
        auto i = list.begin();
        for (auto j = i+1; j!=list.end(); ++j)
            if (i->size()!=j->size()) return false;
        return true;
    }


    template<size_t N, typename I, typename List>
    Enable_if<(N>1),void> add_extents(I& first, const List& list)
    {
        assert(check_non_jagged(list));
        *first = list.size();
        add_extents<N-1>(++first,*list.begin());
    }

    template<size_t N, typename I, typename List>
    Enable_if<(N==1),void> add_extents(I& first, const List& list)
    {
        *first++ = list.size(); // we reached the deepest nesting
    }

    template<size_t N, typename List>
    array<size_t, N> derive_extents(const List& list)
    {
        array<size_t,N> a;
        auto f = a.begin();
        add_extents<N>(f,list); // put extents from list into f[]
        return a;
    }
    template<typename T, typename Vec>
    void add_list(const T* first, const T* last, Vec& vec)
    {
        vec.insert(vec.end(),first,last);
    }
    template<typename T, typename Vec> // nested initializer_lists
    void add_list(const initializer_list<T>* first, const initializer_list<T>* last, Vec& vec)
    {
        for (;first!=last;++first)
            add_list(first->begin(),first->end(),vec);
    }

    template<typename T, typename Vec>
    void insert_flat(initializer_list<T> list, Vec& vec)
    {
        add_list(list.begin(),list.end(),vec);
    }



    template<typename T, size_t N>
    class Matrix {
    public:
        static constexpr size_t order = N;
        using value_type = T;
        using iterator = typename std::vector<T>::iterator;
        using const_iterator = typename std::vector<T>::const_iterator;
        Matrix() = default;
        Matrix(Matrix&&) noexcept = default;// move
        Matrix& operator=(Matrix&&) noexcept = default;
        Matrix(Matrix const&) = default;// copy
        Matrix& operator=(Matrix const&) = default;
        ~Matrix() = default;
        template<typename U>// construct from Matrix_ref
        Matrix(const Matrix_ref<U,N>& x):desc{x.desc},elems{x.begin(),x.end()}{// copy desc and elements
            static_assert(Convertible<U,T>(),"Matrix constructor: incompatible element types");
        }
        template<typename U>// assign from Matrix_ref
        Matrix& operator=(const Matrix_ref<U,N>& x){
            static_assert(Convertible<U,T>(),"Matrix constructor: incompatible element types");
            desc=x.desc;
            elems.assign(x.begin(),x.end());
            return *this;
        }
        template<typename... Exts>
        explicit Matrix(Exts... exts):// specify the extents
        desc{exts...},// copy extents
        elems(desc.size){};// allocate desc.size elements and default initialize them
        Matrix(Matrix_initializer<T,N> init){// initialize from list
            desc.extents = derive_extents<T,N>(init);// deduce extents from initializer list (§29.4.4)
            elems.reserve(desc.size);// make room for slices
            insert_flat(init,elems);// initialize from initializer list (§29.4.4)
            assert(elems.size() == desc.size);
        }
        Matrix& operator=(Matrix_initializer<T,N> init){// assign from list

        };

        template<typename U>
        Matrix(initializer_list<U>) = delete;// don’t use {} except for elements
        template<typename U>
        Matrix& operator=(initializer_list<U>) = delete;

        //static constexpr size_t order() { return N; }// number of dimensions
        size_t extent(size_t n) const { return desc.extents[n]; }// #elements in the nth dimension
        size_t size() const { return elems.size(); }// total number of elements
        const Matrix_slice<N>& descriptor() const { return desc; } // the slice defining subscripting



        T* data() { return elems.data(); } // ‘‘flat’’ element access
        const T* data() const { return elems.data(); }// ...


        template<typename... Args> // m(i,j,k) subscripting with integers
        Enable_if<Requesting_element<Args...>(), T&>
        operator()(Args... args);
        template<typename... Args>
        Enable_if<Requesting_element<Args...>(), const T&>
        operator()(Args... args) const;
        template<typename... Args> // m(s1,s2,s3) subscripting with slices
        Enable_if<Requesting_slice<Args...>(), Matrix_ref<T, N>>
        operator()(const Args&... args);
        template<typename... Args>
        Enable_if<Requesting_slice<Args...>(), Matrix_ref<const T,N>>
        operator()(const Args&... args) const;

        Matrix_ref<T,N-1> operator[](size_t i) { return row(i); } // m[i] row access
        Matrix_ref<const T,N-1> operator[](size_t i) const { return row(i); }
        Matrix_ref<T,N-1> row(size_t n);
        Matrix_ref<const T,N-1> row(size_t n) const; // row access
        Matrix_ref<T,N-1> col(size_t n);
        Matrix_ref<const T,N-1> col(size_t n) const; // column access


        //Mathematical operations
        template<typename F>
        Matrix& apply(F f){ // f(x) for every element x
            for(auto& elem:elems) f(elem);
            return *this;
        };

        template<typename M, typename F>
        Enable_if<Is_same<T,M>(),Matrix<T,N>&> apply(const M& m, F f){// f(x,mx) for corresponding elements
            static_assert(m.order()==N,"+=:mismatched Matrix dimensions");
            assert(same_extents(desc,m.descriptor())); // make sure sizes match
            for (auto i = elems.begin(), j = m.begin(); i!=elems.end(); ++i, ++j)
                f(*i,*j);
            return *this;
        }

        //scalar mathematical operations
        Matrix& operator=(const T& value); // assignment with scalar
        Matrix& operator+=(const T& val){// scalar addition
            return apply([&](T&a){a+=val;});
        };
        Matrix& operator-=(const T& val){// scalar subtraction
            return apply([&](T&a){a-=val;});
        };
        Matrix& operator*=(const T& val){// scalar multiplication
            return apply([&](T&a){a*=val;});
        };
        Matrix& operator/=(const T& val){// scalar division
            return apply([&](T&a){a/=val;});
        };
        Matrix& operator%=(const T& val){// scalar modulo
            return apply([&](T&a){a%=val;});
        };
        template<typename M>    // matrix addition
        Enable_if<Is_same<T,M>(),Matrix<T,N>&> operator+=(const M& m){
            static_assert(m.order()==N,"+=:mismatched Matrix dimensions");
            assert(same_extents(desc,m.descriptor())); // make sure sizes match
            return apply(m,[](T&a, Value_type<M>&b){a+=b;});
        }

        template<typename M>    // matrix subtraction
        Enable_if<Is_same<T,M>(),Matrix<T,N>&> operator-=(const M& m){
            static_assert(m.order()==N,"-=:mismatched Matrix dimensions");
            assert(same_extents(desc,m.descriptor())); // make sure sizes match
            return apply(m,[](T&a, Value_type<M>&b){a-=b;});
        }


    private:
        Matrix_slice<N> desc;
        std::vector<T> elems;
    };

    template<typename M>
    struct Matrix_type{

    };







    template<typename T,size_t N>
    Matrix<T,N> operator+(const Matrix<T,N>& m,const T& val);
    template<typename T,size_t N>
    Matrix<T,N> operator-(const Matrix<T,N>& m,const T& val);
    template<typename T,size_t N>
    Matrix<T,N> operator*(const Matrix<T,N>& m,const T& val);
    template<typename T,size_t N>
    Matrix<T,N> operator/(const Matrix<T,N>& m,const T& val);
    template<typename T,size_t N>
    Matrix<T,N> operator%(const Matrix<T,N>& m,const T& val);

    template<typename T, size_t N>
    Matrix<T,N> operator+(const Matrix<T,N>& a, const Matrix<T,N>& b);

    template<typename T, size_t N>
    Matrix<T,N> operator-(const Matrix<T,N>& a, const Matrix<T,N>& b);


    //template<typename T, typename T2, size_t N,
    //        typename RT = Matrix<Common_type<Value_type<T>,Value_type<T2>>,N>
    //Matrix<RT,N> operator+(const Matrix<T,N>& a, const Matrix<T2,N>& b);

    template<typename T>
    Matrix<T,2> operator*(const Matrix<T,1>&u, const Matrix<T,1>&v);

    template<typename T>
    Matrix<T,1> operator*(const Matrix<T,2>&u, const Matrix<T,1>&v);

    template<typename T>
    Matrix<T,2> operator*(const Matrix<T,2>&u, const Matrix<T,2>&v);





}



#endif //WORKBENCH_MATRIX_H
