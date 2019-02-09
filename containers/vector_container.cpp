//
// Created by egl on 2/8/19.
//
#include "vector_container.h"


namespace containers{
    vector_container::vector_container(int sz): v(sz){}
    vector_container::vector_container(std::initializer_list<double> list):v(list){}
    vector_container::~vector_container(){}
    double& vector_container::operator[](int i){return v[i];}
    int vector_container::size() const {return v.size();};
}