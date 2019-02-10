//
// Created by egl on 2/8/19.
//
#include "list_container.h"

namespace containers {
    template<typename T>
    list_container<T>::list_container(std::initializer_list<T> list):l(list){}
    template<typename T>
    list_container<T>::~list_container() {}
    template<typename T>
    T& list_container<T>::operator[](int i)
    {
        for(auto& item: l){
            if(i==0) return item;
            --i;
        }
        throw std::out_of_range("List container");
    }
    template<typename T>
    int list_container<T>::size() const {return static_cast<int>(l.size());}

    template class list_container<double>;
}
