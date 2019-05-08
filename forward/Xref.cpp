//
// Created by egl on 5/6/19.
//

#include "Xref.h"
using namespace forward;

void forward::driveXref() {
    string x {"There and back again"};

    auto p1 = make_unique<Xref<string>>(7,"Here");
    auto p2 = make_unique<Xref<string>>(9,x);

    Xref<string> r1 {7, string{"Here"}};// r1 owns a copy of string{"Here"}
    Xref<string> r2 {9,x};// r2 just refers to x
    Xref<string> r3 {3,new string{"There"}};// r3 owns the string{"There"}



}