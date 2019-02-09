//
// Created by egl on 2/8/19.
//

#ifndef WORKBENCH_LIST_CONTAINER_H
#define WORKBENCH_LIST_CONTAINER_H

#include "container.h"
#include <iostream>
#include <list>

namespace containers{
    class list_container: public container {
        std::list<double> l;
    public:
        list_container(std::initializer_list<double> list);
        ~list_container();
        double& operator[](int i);
        int size() const;
    };

}


#endif //WORKBENCH_LIST_CONTAINER_H
