//
// Created by egl on 2/7/19.
//


#include "vector.h"
using namespace containers;

    template<typename T>
    vector<T>::vector():elems{nullptr},sz{0} {}

    template<typename T>
    vector<T>::vector(int size): elems{new T[size]}, sz{size} {
    }

    template<typename T>
    vector<T>::vector(std::initializer_list<T> list):
                    elems{new T[list.size()]},
                    sz{static_cast<int>(list.size())} {
        std::copy(list.begin(), list.end(),elems);
    }

    template<typename T>
    vector<T>::vector(const vector<T>& v): elems{new T[v.size()]}, sz(v.size()){
        for(auto i = 0; i < sz; i++)
            elems[i] = v[i];
    }

    template<typename T>
    vector<T>& vector<T>::operator=(const vector<T> &v) {
        auto p = new T[v.size()];
        sz = v.size();
        if(elems!= nullptr) delete[] elems;
        elems = p;
        for(auto i = 0; i < sz; i++)
            elems[i] = v[i];
        return *this;
    }

    template<typename T>
    vector<T>::vector(vector<T> &&v):elems{v.elems}, sz{v.size()} {
        v.elems = nullptr;
        v.sz = 0;
    }

    template<typename T>
    vector<T>& vector<T>::operator=(vector<T>&& v) {
        elems = v.elems;
        sz = v.size();
        v.elems = nullptr;
        v.sz = 0;
        return *this;
    }

    template<typename T>
    vector<T>::~vector() {
        delete[] elems;
    }

    template<typename T>
    T& vector<T>::operator[](int index) const{
        if(index >= sz) throw std::out_of_range("index out of range");
        return elems[index];
    }

    template<typename T>
    int vector<T>::size() const {return sz;}


    template<typename T>
    void vector<T>::print() const {
        for(int i = 0; i < sz; ++i){
            std::cout << elems[i] << " ";
        }
        std::cout << std::endl;
    }
    template class vector<double>;

