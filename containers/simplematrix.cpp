//
// Created by egl on 5/3/19.
//


#include "simplematrix.h"
using namespace containers;

template<class T>
simplematrix<T> containers::operator+(const containers::simplematrix<T> &l,
                                      const containers::simplematrix<T> &r) {
    if(l.dim[0]!=r.dim[0] || l.dim[1]!=r.dim[1])
        throw runtime_error("unequal matrix sizes in +");
    simplematrix res{l.dim[0],l.dim[1]};
    constexpr auto n = res.size();
    for(auto i=0; i<n; ++i)
        res.elem[i]=l.elem[i]+r.elem[i];
    return res;
}

void containers::drive_simple_matrix(){
    simplematrix<int>sm{2,2};
    auto sm1{sm};
    auto sm2 = sm;
    sm1 = sm2;
}

template<class T>
simplematrix<T>::simplematrix(const simplematrix<T> & sm):dim{sm.dim},elem{new T[sm.size()]} {
    uninitialized_copy(sm.elem,sm.elem+sm.size(),elem);
}

template<class T>
simplematrix<T>& simplematrix<T>::operator=(const containers::simplematrix<T> & sm) {
    if (dim[0]!=sm.dim[0] || dim[1]!=sm.dim[1])
        throw runtime_error("bad size in Matrix =");
    copy(sm.elem,sm.elem+sm.size(),elem);
    return *this;
}

template<class T>
simplematrix<T>::simplematrix(simplematrix&& sm):dim{sm.dim},elem{sm.elem}{
    sm.dim = {0,0};
    sm.elem = nullptr;
}

template<class T>
simplematrix<T>& simplematrix<T>::operator=(simplematrix<T>&& sm)noexcept{
    swap(dim,sm.dim);
    swap(elem,sm.elem);
    return *this;
}




