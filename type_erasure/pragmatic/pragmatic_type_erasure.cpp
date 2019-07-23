//
// Created by egl on 7/22/19.
//

#include <iostream>
#include "pragmatic_type_erasure.h"
using namespace type_erasure::pragmatic;

void type_erasure::pragmatic::drive_pragmatic_type_erasure() {
    int i=1;
    int* i_ptr{&i};
    anything a{i};
    a=i;
    a=i_ptr;

    a=2.0;
    a=std::string("3");
    struct foo{};
    a=foo{};

    struct bar{};

    anything b=bar{};

    a=std::move(b);

    anything c{foo{}};

    anything d{bar{}};

    d=c;

    anything l{d};

    anything three{3};
    anything four{4};

}