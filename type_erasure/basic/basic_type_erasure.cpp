//
// Created by egl on 7/22/19.
//

#include "basic_type_erasure.h"
using namespace type_erasure::basic;

void type_erasure::basic::drive_basic_type_erasure() {
    struct Link{
        void printName()const{
            std::cout << "Link" << std::endl;
        }
    };

    struct Zelda{
        void printName()const{
            std::cout << "Zelda" << std::endl;
        }
    };

    TypeErased te{Link{}};
    te.printName();
    te=Zelda{};
    te.printName();

}