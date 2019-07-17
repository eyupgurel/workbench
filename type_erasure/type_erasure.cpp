//
// Created by egl on 7/17/19.
//

#include "type_erasure.h"
using namespace type_erasure;
void open_door(const Opener &o) {
    o.open();
}

void greet_tom(const Greeter &g) {
    g.greet("Tom");
}

void open_door_and_greet_john(const OpenerAndGreeter &g) {
    g.open();
    g.greet("John");
}

void type_erasure::drive_type_erasure() {

    English en;
    French fr;

    open_door(en);
    open_door(fr);
    std::cout << "----------------\n";
    greet_tom(en);
    greet_tom(fr);
    std::cout << "----------------\n";
    open_door_and_greet_john(en);
    open_door_and_greet_john(fr);
}