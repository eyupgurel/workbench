//
// Created by egl on 7/12/19.
//

#include "movesamples.h"

using namespace movesamples;
movesamples::person get_person(){
    person p{"Eyüp", "Gürel"};
    return p;
}


void movesamples::drive_move_samples() {
    person me1{get_person()};
    person me2=get_person();
}