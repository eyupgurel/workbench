//
// Created by egl on 5/14/19.
//

#include "tiny.h"
using namespace typeconversion;

int square(int i){
    return i*i;
}

Tiny divide(Tiny t){
    return t/2;
}

void typeconversion::drive_tiny() {
    Tiny c1=2;

    Tiny ti= square(c1);

    Tiny td = divide(8);

    Tiny c2=62;
    Tiny c3 = c2 - c1;
    Tiny c4 = c3;
    int i = c1 + c2;

    //c1 = c1 + c2; // range error: c1 can’t be 64
    i = c3 - 64;  // i = -4
    //c2 = c3 - 64; // range error: c2 can’t be -4
    c3 = c4;    // no range check (not necessary)
}