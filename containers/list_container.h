//
// Created by egl on 2/8/19.
//

#ifndef WORKBENCH_LIST_CONTAINER_H
#define WORKBENCH_LIST_CONTAINER_H

#include "container.h"
#include <iostream>
#include <list>

namespace containers{
    template<typename T>
    class list_container: public container<T> {
        std::list<double> l;
    public:
        list_container(std::initializer_list<T> list);
        ~list_container();
        T& operator[](int i);
        int size() const;
    };

}


#endif //WORKBENCH_LIST_CONTAINER_H
