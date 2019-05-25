//
// Created by egl on 5/24/19.
//

#include "_tstring.h"
using namespace containers;

template<typename C>
_tstring<C>::_tstring():sz{0},ptr{ch}{
    ch[0]={};
}

template<typename C>
_tstring<C>& _tstring<C>::operator+=(C c){
    return *this;
}

