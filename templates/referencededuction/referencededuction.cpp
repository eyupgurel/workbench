//
// Created by egl on 5/25/19.
//

#include "referencededuction.h"

using namespace templates;
void templates::drive_Xref() {
    string s{"There and back again"};
    Xref<string>r1{7,"Here"};
    Xref<string>r2{9,s};
    Xref<string>r3{3,new string{"There"}};

    auto p1 = make_unique2<Xref<string>>(7,"Here");
    auto p2 = make_unique2<Xref<string>>(9,s);
    auto p3 = make_unique2<Xref<string>>(3,new string{"There"});



}