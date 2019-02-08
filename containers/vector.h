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
        vector(const unsigned long size);
        vector(const std::initializer_list<double> list);
        ~vector();
        double& operator[](const unsigned long index);
        void print() const;
        //void push_back(const double new_elem);
    private:
        double *elems;
        unsigned long sz;
    };

}

#endif //WORKBENCH_VECTOR_H
