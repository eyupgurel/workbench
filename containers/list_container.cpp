//
// Created by egl on 2/8/19.
//
#include "list_container.h"

namespace containers {
    list_container::list_container(std::initializer_list<double> list):l(list){}
    list_container::~list_container() {}
    double& list_container::operator[](int i)
    {
        for(auto& item: l){
            if(i==0) return item;
            --i;
        }
        throw std::out_of_range("List container");
    }
    int list_container::size() const {return static_cast<int>(l.size());}
}
