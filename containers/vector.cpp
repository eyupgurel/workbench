//
// Created by egl on 2/7/19.
//


#include "vector.h"

namespace containers {

    vector::vector() {}

    vector::vector(int size): elems{new double[size]}, sz{size} {

    }
    vector::vector(std::initializer_list<double> list):
                    elems{new double[list.size()]},
                    sz{static_cast<int>(list.size())} {
        std::copy(list.begin(), list.end(),elems);
    }
    vector::~vector() {
        delete[] elems;
    }
    vector::vector(const vector& v){
        sz = v.size();
        elems = new double[v.size()];
        for(auto i = 0; i < sz; i++)
            elems[i] = v[i];
    }

    vector& vector::operator=(const containers::vector &v) {
        sz = v.size();
        elems = new double[v.size()];
        for(auto i = 0; i < sz; i++)
            elems[i] = v[i];
        return *this;
    }

    double& vector::operator[](int index) const{
        if(index >= sz) throw std::out_of_range("index out of range");
        return elems[index];
    }
    int vector::size() const {return sz;}


    void vector::print() const {
        for(int i = 0; i < sz; ++i){
            std::cout << elems[i] << " ";
        }
        std::cout << std::endl;
    }


}
