//
// Created by egl on 5/27/19.
//

#include "algorithms.h"
using namespace templates;

void templates::drive_template_algorithms() {
    double d[4]{2.1,2.3,0.3,5.7};

    auto sum=add<double*,double>(d,d+4);
    auto total=accumulate<double*,double>(d,d+4,0.0,std::plus<>{});
    auto multi=accumulate<double*,double>(d,d+4,1.0,std::multiplies<>{});

}

