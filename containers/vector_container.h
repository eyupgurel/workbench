//
// Created by egl on 2/8/19.
//

#ifndef WORKBENCH_VECTOR_CONTAINER_H
#define WORKBENCH_VECTOR_CONTAINER_H

#include "container.h"
#include "vector.h"

namespace containers{
    template<typename T>
    class vector_container: public container<T>{
        my_vector<T> v;
    public:
        vector_container(int sz);
        vector_container(std::initializer_list<T> list);
        ~vector_container();
        T& operator[](int i);
        int size() const;
    };
}


#endif //WORKBENCH_VECTOR_CONTAINER_H
