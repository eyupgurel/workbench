//
// Created by egl on 2/7/19.
//


#include "vector.h"

namespace containers {
    vector::vector(const unsigned long size): elems{new double[size]}, sz{size} {

    }
    vector::vector(const std::initializer_list<double> list):
                    elems{new double[list.size()]},
                    sz{list.size()}{
        std::copy(list.begin(), list.end(),elems);
    }
    vector::~vector() {
        delete[] elems;
    }
    double& vector::operator[](const unsigned long index) {
        if(index >= sz) throw std::out_of_range("index out of range");
        return elems[index];
    }
    void vector::print() const {
        for(int i = 0; i < sz; ++i){
            std::cout << elems[i] << " ";
        }
        std::cout << std::endl;
    }
}
