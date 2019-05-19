//
// Created by egl on 5/19/19.
//

#include "pointer.h"

using namespace pointer;

using Pstd_mem = void (Std_interface::*)(); // pointer-to-member type


void f(Std_interface* p)
{
    Pstd_mem s = &Std_interface::suspend;
    p->suspend();
    (p->*s)();
}


void pointer::derive_pointer(){
    // declare pointer to data member
    int X::*ptiptr = &X::a;

    // declare a pointer to member function
    void (X::* ptfptr) (int) = &X::f;

    // create an object of class type X
    X xobject;

    // initialize data member
    xobject.*ptiptr = 10;

    cout << "The value of a is " << xobject.*ptiptr << endl;

    // call member function
    (xobject.*ptfptr) (20);


    device d;
    f(&d);
}