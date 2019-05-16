//
// Created by egl on 5/15/19.
//

#include "unionofclasses.h"
using namespace unions;

void unions::drive_union_of_classes() {
    S s{"Hello World!"};
    // at this point reading from s.vec is undefined behaviour
    cout << "s.str" << s.str << '\n';
    s.str.~basic_string();
    new (&s.vec) vector<int>;
    s.vec.push_back(10);
    cout << s.vec.size() << '\n';
    s.vec.~vector();
}