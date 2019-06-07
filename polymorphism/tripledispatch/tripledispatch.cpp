//
// Created by egl on 6/7/19.
//

#include "tripledispatch.h"
using namespace polymorphism::tripledispatch;

void test_tripledispatch_combinations(Circle& c, Triangle& t, Rectangle& r){
    vector<tuple<Shape*,Shape*,Shape*>>vt{
                                          {&c,&c,&c},{&c,&c,&t},{&c,&t,&c},
                                          {&c,&t,&t},{&c,&t,&r},{&c,&r,&t},
                                          {&c,&r,&r},{&c,&r,&c},{&c,&c,&r},

                                          {&t,&c,&c},{&t,&c,&t},{&t,&t,&c},
                                          {&t,&t,&t},{&t,&t,&r},{&t,&r,&t},
                                          {&t,&r,&r},{&t,&r,&c},{&t,&c,&r},

                                          {&r,&c,&c},{&r,&c,&t},{&r,&t,&c},
                                          {&r,&t,&t},{&r,&t,&r},{&r,&r,&t},
                                          {&r,&r,&r},{&r,&r,&c},{&r,&c,&r}
                                          };
    for(auto t: vt)
        get<0>(t)->intersect(*get<1>(t),*get<2>(t));
}

void polymorphism::tripledispatch::drive_tripledispatch(){
    Circle c;
    Triangle t;
    Rectangle r;
    test_tripledispatch_combinations(c,t,r);
}