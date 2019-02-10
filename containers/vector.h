//
// Created by egl on 2/7/19.
//

#ifndef WORKBENCH_VECTOR_H
#define WORKBENCH_VECTOR_H

#include <stdexcept>
#include <iostream>



namespace containers {
template <typename T>
    class vector {
    public:
        vector();
        explicit vector(int size);
        vector(std::initializer_list<T> list);
        vector(const vector<T>& v);
        vector<T>& operator=(const vector<T>& v);
        vector(vector<T>&& v);
        vector<T>& operator=(vector<T>&& v);
        ~vector();
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
