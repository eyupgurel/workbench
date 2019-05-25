//
// Created by egl on 5/23/19.
//

#ifndef WORKBENCH_TYPEID_H
#define WORKBENCH_TYPEID_H

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
namespace typeid_{

    struct Poly { // polymor phic base class
        virtual void f(){};
// ...
    };
    struct Non_poly { /* ... */ }; // no virtual functions
    struct D1
            : Poly { /* ... */ };
    struct D2
            : Non_poly { /* ... */ };


    struct Base {}; // non-polymorphic
    struct Derived : Base {};

    struct Base2 { virtual void foo() {} }; // polymorphic
    struct Derived2 : Base2 {};

    void drive_typeid();
}

#endif //WORKBENCH_TYPEID_H
