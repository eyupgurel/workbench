//
// Created by egl on 7/22/19.
//

#include <iostream>
#include "pragmatic_type_erasure.h"
using namespace type_erasure::pragmatic;


anything::anything(const anything& rhs):handle_(rhs.handle_->clone()){}

anything& anything::operator=(const anything& rhs){
    //handle_= std::make_unique<typename rhs.handle_::type> .reset(new handle<std::remove_reference_t<decltype(rhs.handle_.operator*())>(rhs.handle_.get()));
    return *this;
}


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

    anything b=foo{};

    a=b;
}