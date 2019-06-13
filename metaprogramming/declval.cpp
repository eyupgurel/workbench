//
// Created by egl on 6/12/19.
//

#include "declval.h"
using namespace metaprogramming;

void metaprogramming::drive_declval(){
    decltype(Default{}.foo()) n1 = 1;                   // type of n1 is int
    //decltype(NonDefault().foo()) n2 = n1;             // error: no default constructor
    decltype(std::declval<NonDefault>().foo()) n2 = n1; // type of n2 is int
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n';
}
