//
// Created by egl on 2/7/19.
//


#include "vector.h"

namespace containers {

    vector::vector():elems{nullptr},sz{0} {}

    vector::vector(int size): elems{new double[size]}, sz{size} {

    }
    vector::vector(std::initializer_list<double> list):
                    elems{new double[list.size()]},
                    sz{static_cast<int>(list.size())} {
        std::copy(list.begin(), list.end(),elems);
    }

    vector::vector(const vector& v): elems{new double[v.size()]}, sz(v.size()){
        for(auto i = 0; i < sz; i++)
            elems[i] = v[i];
    }

    vector& vector::operator=(const vector &v) {
        auto p = new double[v.size()];
        sz = v.size();
        if(elems!= nullptr) delete[] elems;
        elems = p;
        for(auto i = 0; i < sz; i++)
            elems[i] = v[i];
        return *this;
    }

    vector::vector(vector &&v):elems{v.elems}, sz{v.size()} {
        v.elems = nullptr;
        v.sz = 0;
    }

    vector& vector::operator=(vector&& v) {
        elems = v.elems;
        sz = v.size();
        v.elems = nullptr;
        v.sz = 0;
        return *this;
    }

    vector::~vector() {
        delete[] elems;
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
