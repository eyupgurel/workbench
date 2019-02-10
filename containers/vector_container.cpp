//
// Created by egl on 2/8/19.
//
#include "vector_container.h"

namespace containers{
    template<typename T>
    vector_container<T>::vector_container(int sz): v(sz){}
    template<typename T>
    vector_container<T>::vector_container(std::initializer_list<T> list):v(list){}
    template<typename T>
    vector_container<T>::~vector_container(){}
    template<typename T>
    T& vector_container<T>::operator[](int i){return v[i];}
    template<typename T>
    int vector_container<T>::size() const {return v.size();};

    template class vector_container<double>;
}