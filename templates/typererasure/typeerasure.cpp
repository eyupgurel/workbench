//
// Created by egl on 6/3/19.
//

#include "typeerasure.h"
using namespace templates;

void templates::drive_var() {
    var vd{2.3};
    vd._inner.get();
    vd=3;
}
