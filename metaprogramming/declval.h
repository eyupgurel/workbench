//
// Created by egl on 6/12/19.
//

#ifndef WORKBENCH_DECLVAL_H
#define WORKBENCH_DECLVAL_H
#include <utility>
#include <iostream>
namespace metaprogramming{

    struct Default { int foo() const { return 1; } };

    struct NonDefault
    {
        NonDefault(const NonDefault&) { }
        int foo() const { return 1; }
    };

    void drive_declval();
}


#endif //WORKBENCH_DECLVAL_H
