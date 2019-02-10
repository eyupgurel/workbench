//
// Created by egl on 2/7/19.
//

#ifndef WORKBENCH_VECTOR_H
#define WORKBENCH_VECTOR_H

#include <stdexcept>
#include <iostream>



namespace containers {
template <typename T>
    class my_vector {
    public:
        my_vector();
        explicit my_vector(int size);
        my_vector(std::initializer_list<T> list);
        my_vector(const my_vector<T>& v);
        my_vector<T>& operator=(const my_vector<T>& v);
        my_vector(my_vector<T>&& v);
        my_vector<T>& operator=(my_vector<T>&& v);
        ~my_vector();
        T& operator[](int index) const;
        int size() const;
        void print() const;
        //void push_back(const double new_elem);
    private:
        T *elems;
        int sz;
    };

}

#endif //WORKBENCH_VECTOR_H
