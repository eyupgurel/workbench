//
// Created by egl on 5/1/19.
//

#include "lifetime.h"
using namespace lifetime;

Tracer::Tracer(const string &s):mess{s} {
    clog<<mess;
}
Tracer::~Tracer() {
    clog<<"~"<<mess;
}

void lifetime::trace(const vector<int> &v) {
    Tracer tr{"in lifetime::trace\n"};
    for(auto x: v)
        Tracer trf{string{"v loop "}+to_string(x)+'\n'};
}

void lifetime::drive() {
    trace({2,3,5});
}