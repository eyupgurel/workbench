//
// Created by egl on 7/10/19.
//

#include "lambda.h"
using namespace lambda;

void lambda::drive_lambda_samples() {
    int x=10;

    auto c1 = [x](int y){return x*y>55;};
    auto c2= c1;
    auto c3 = c2;
    auto r1=c3(4);
    auto r2=c3(6);

    FilterContainer filters;
    filters.emplace_back([](int value){return value%5==0;});


}