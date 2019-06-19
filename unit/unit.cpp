//
// Created by egl on 6/15/19.
//

#include "unit.h"
using namespace unit;

void drive_si_unit(){
    Quantity<M>x{10.5_m};
    Quantity<S>y{2.0_s};
    Quantity<MpS> speed1{10.0_mps};
    //auto double_speed{speed1*2.0L};

   // auto distance=Quantity<M>{10.0};
   // auto time=Quantity<S>{20.0};

    auto d{23.2_m};
    auto t{2.3_s};

    auto d2{square(d)};

    //auto s{d/t};

    //auto speed2=distance/time;
}