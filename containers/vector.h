//
// Created by egl on 2/7/19.
//

#ifndef WORKBENCH_VECTOR_H
#define WORKBENCH_VECTOR_H

#include <stdexcept>
#include <iostream>


namespace containers {

    class vector {
    public:
        vector();
        vector(int size);
        vector(std::initializer_list<double> list);
        vector(const vector& v);
        vector& operator=(const vector& v);
        ~vector();
        double& operator[](int index) const;
        int size() const;
        void print() const;
        //void push_back(const double new_elem);
    private:
        double *elems;
        int sz;
    };

}

#endif //WORKBENCH_VECTOR_H
