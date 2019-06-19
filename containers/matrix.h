//
// Created by egl on 6/17/19.
//
/*
#ifndef WORKBENCH_MATRIX_H
#define WORKBENCH_MATRIX_H

#include <cstddef>
#include <vector>
#include <assert.h>
#include "../metaprogramming/metaprogramming.h"

using namespace std;
using namespace metaprogramming;
namespace containers{

    template<typename M>
    using Value_type=typename M::value_type;


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
            Matrix_impl::derive_extents(init,desc.extents);// deduce extents from initializer list (§29.4.4)
            elems.reserve(desc.size);// make room for slices
            Matrix_impl::insert_flat(init,elems);// initialize from initializer list (§29.4.4)
            assert(elems.size() == desc.size);
        }
        Matrix& operator=(Matrix_initializer<T,N> init){// assign from list

        };

        template<typename U>
        Matrix(initializer_list<U>) = delete;// don’t use {} except for elements
        template<typename U>
        Matrix& operator=(initializer_list<U>) = delete;

        static constexpr size_t order() { return N; }// number of dimensions
        size_t extent(size_t n) const { return desc.extents[n]; }// #elements in the nth dimension
        size_t size() const { return elems.size(); }// total number of elements
        const Matrix_slice<N>& descriptor() const { return desc; } // the slice defining subscripting



        T* data() { return elems.data(); } // ‘‘flat’’ element access
        const T* data() const { return elems.data(); }// ...


        template<typename... Args> // m(i,j,k) subscripting with integers
        Enable_if<Matrix_impl::Requesting_element<Args...>(), T&>
        operator()(Args... args);
        template<typename... Args>
        Enable_if<Matrix_impl::Requesting_element<Args...>(), const T&>
        operator()(Args... args) const;
        template<typename... Args> // m(s1,s2,s3) subscripting with slices
        Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<T, N>>
        operator()(const Args&... args);
        template<typename... Args>
        Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<const T,N>>
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
*/