//
// Created by egl on 2/7/19.
//


#include "vector.h"

namespace containers {
    template<typename T>
    my_vector<T>::my_vector():elems{nullptr},sz{0} {}

    template<typename T>
    my_vector<T>::my_vector(int size): elems{new T[size]}, sz{size} {
    }

    template<typename T>
    my_vector<T>::my_vector(std::initializer_list<T> list):
                    elems{new T[list.size()]},
                    sz{static_cast<int>(list.size())} {
        std::copy(list.begin(), list.end(),elems);
    }

    template<typename T>
    my_vector<T>::my_vector(const my_vector<T>& v): elems{new T[v.size()]}, sz(v.size()){
        for(auto i = 0; i < sz; i++)
            elems[i] = v[i];
    }

    template<typename T>
    my_vector<T>& my_vector<T>::operator=(const my_vector<T> &v) {
        auto p = new T[v.size()];
        sz = v.size();
        if(elems!= nullptr) delete[] elems;
        elems = p;
        for(auto i = 0; i < sz; i++)
            elems[i] = v[i];
        return *this;
    }

    template<typename T>
    my_vector<T>::my_vector(my_vector<T> &&v):elems{v.elems}, sz{v.size()} {
        v.elems = nullptr;
        v.sz = 0;
    }

    template<typename T>
    my_vector<T>& my_vector<T>::operator=(my_vector<T>&& v) {
        elems = v.elems;
        sz = v.size();
        v.elems = nullptr;
        v.sz = 0;
        return *this;
    }

    template<typename T>
    my_vector<T>::~my_vector() {
        delete[] elems;
    }

    template<typename T>
    T& my_vector<T>::operator[](int index) const{
        if(index >= sz) throw std::out_of_range("index out of range");
        return elems[index];
    }

    template<typename T>
    int my_vector<T>::size() const {return sz;}


    template<typename T>
    void my_vector<T>::print() const {
        for(int i = 0; i < sz; ++i){
            std::cout << elems[i] << " ";
        }
        std::cout << std::endl;
    }
    template class my_vector<double>;
}

