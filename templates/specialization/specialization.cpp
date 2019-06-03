//
// Created by egl on 6/3/19.
//

#include "specialization.h"
using namespace templates;

void templates::drive_specializaton_cases() {
    SVector<double> sv(3);
    cout << "sv[2]=" << sv[2] << endl;

    SVector<void*>svvp(15);
    cout << "svvp[14]=" << svvp[14] << endl;

    SVector<double*>svp(25);
    cout << "svp[25]=" << svp[24] << endl;


}