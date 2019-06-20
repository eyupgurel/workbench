//
// Created by egl on 6/17/19.
//

#include <numeric>
#include "matrix.h"
using namespace containers;



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

void drive_matrix(){
    Matrix<int,2> m2 {
            {1,2,3},
            {11,12,13}
    };
}
