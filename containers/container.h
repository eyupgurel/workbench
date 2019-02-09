//
// Created by egl on 2/8/19.
//

#ifndef WORKBENCH_CONTAINER_H
#define WORKBENCH_CONTAINER_H

#include <initializer_list>
#include <zconf.h>


namespace containers{
    class container{
    public:
        virtual double& operator[](int i) = 0;
        virtual int size() const = 0;
        virtual ~container() = default;
    };

}
#endif //WORKBENCH_CONTAINER_H
