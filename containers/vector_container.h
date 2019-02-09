//
// Created by egl on 2/8/19.
//

#ifndef WORKBENCH_VECTOR_CONTAINER_H
#define WORKBENCH_VECTOR_CONTAINER_H

#include "container.h"
#include "vector.h"

namespace containers{
    class vector_container: public container{
        vector v;
    public:
        vector_container(int sz);
        vector_container(std::initializer_list<double> list);
        ~vector_container();
        double& operator[](int i);
        int size() const;
    };
}


#endif //WORKBENCH_VECTOR_CONTAINER_H
