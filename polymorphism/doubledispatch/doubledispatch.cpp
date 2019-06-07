//
// Created by egl on 6/7/19.
//

#include "doubledispatch.h"
using namespace polymorphism;

void test_combinations(Triangle& t, Circle& c){
    vector<pair<Shape*,Shape*>>vs{{&t,&t},{&t,&c},{&c,&t},{&c,&c}};
    for(auto p: vs)
        p.first->intersect(*p.second);
}

void polymorphism::drive_doubledispatch() {
    Triangle t;
    Circle c;
    test_combinations(t,c);
}