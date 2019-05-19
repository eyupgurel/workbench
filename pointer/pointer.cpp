//
// Created by egl on 5/19/19.
//

#include "pointer.h"

using namespace pointer;

void g(C& z1, C& z2){
    C* p{&z2};
    Pmfi pf=&C::print;
    Pm pm=&C::val;

    z1.print(1);
    (z1.*pf)(2);
    z1.*pm="nv 1";
    p->*pm="nv 2";
    z2.print(3);
    (p->*pf)(4);


}

void f(Std_interface* p)
{
    Pstd_mem s = &Std_interface::suspend;
    p->suspend();
    (p->*s)();
}


void pointer::derive_pointer(){
    C z1{"Sing a"};
    C z2{"Song"};
    g(z1,z2);

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