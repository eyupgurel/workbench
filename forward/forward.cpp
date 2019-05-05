//
// Created by egl on 5/6/19.
//

#include "forward.h"
using namespace forward;

void forward::drive() {
    auto p1 = make_unique1<A>(2); // rvalue
    int i = 1;
    auto p2 = make_unique1<A>(i); // lvalue

    std::cout << "B\n";
    string s{"Hello baby kiss me! I will give you my address"};

    auto t = make_unique2<B>(2, i, 3, s, string{"I am beautiful but I have no address"});
}