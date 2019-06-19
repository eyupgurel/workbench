//
// Created by egl on 6/17/19.
//
/*
#include "matrix.h"
using namespace containers;

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
    Matrix_slice(Dims... dims);

    template<typename... Dims,
            typename = Enable_if<All(Convertible<Dims,size_t>()...)>>
    size_t operator()(Dims... dims) const;// calculate index from a set of subscripts

    size_t size;    // total number of elements
    size_t start;   // starting offset
    array<size_t,N> extents;    // number of elements in each dimension
    array<size_t,N> strides;    // offsets between elements in each dimension
tü
};


template<typename T,size_t N>
Matrix<T,N> containers::operator+(const Matrix<T,N>& m,const T& val){
    Matrix<T,N> res=m;
    res+=val;
    return res;
}

template<typename T,size_t N>
Matrix<T,N> containers::operator-(const Matrix<T,N>& m,const T& val){
    Matrix<T,N> res=m;
    res-=val;
    return res;
}

template<typename T,size_t N>
Matrix<T,N> containers::operator*(const Matrix<T,N>& m,const T& val){
    Matrix<T,N> res=m;
    res*=val;
    return res;
}

template<typename T,size_t N>
Matrix<T,N> containers::operator/(const Matrix<T,N>& m,const T& val){
    Matrix<T,N> res=m;
    res+=val;
    return res;
}

template<typename T,size_t N>
Matrix<T,N> containers::operator%(const Matrix<T,N>& m,const T& val){
    Matrix<T,N> res=m;
    res%=val;
    return res;
}


template<typename T, size_t N>
Matrix<T,N> containers::operator+(const Matrix<T,N>& a, const Matrix<T,N>& b){
    Matrix<T,N> res = a;
    res+=b;
    return res;
}

template<typename T, size_t N>
Matrix<T,N> containers::operator-(const Matrix<T,N>& a, const Matrix<T,N>& b){
    Matrix<T,N> res = a;
    res-=b;
    return res;
}


template<typename T>
Matrix<T,2> containers::operator*(const Matrix<T,1>&u, const Matrix<T,1>&v){
    const size_t n = u.extent();
    const size_t m = v.extent();
    Matrix<T,2> res(n,m);
    for(size_t i=0; i<n; ++i)
        for(size_t j=0; j<m;++j)
            res(i,j)=u[i]*v[j];
    return res;
}


template<typename T>
Matrix<T,1> containers::operator*(const Matrix<T,2>&u, const Matrix<T,1>&v){
    assert(u.extent(1)==v.extent(0));
    const size_t n=u.extent(0);
    const size_t m=u.extent(1);
    Matrix<T,1> res(n);
    for(size_t i=0; i<n; ++i)
        for(size_t j=0; j<m; ++j)
            res(i)+=u[j]*v[j];
    return res;
}


template<typename T>
Matrix<T,2> containers::operator*(const Matrix<T,2>&u, const Matrix<T,2>&v){
    assert(u.extent(1)==v.extent(0));
    size_t m=u.extent(0);
    size_t n=v.extent(1);
    size_t p=u.extent(1);

    Matrix<T,2>res(m,n);
    for(size_t i=0; i<m;++i)
        for(size_t j=0; j<n; ++j)
            for(size_t k=0; k<p; ++k)
                res(i,j)+=u(i,k)*v(k,j);
    return res;
}
 */