//
// Created by egl on 6/6/19.
//

#include "conversions.h"
using namespace templates;
void f(Ptr<Circle> &pc)
{
    Ptr<Shape> ps {pc};
    //Ptr<Circle> pc2 {ps}; //invalid conversion from ‘Shape*’ to ‘Circle*’
}
void templates::drive_template_conversions() {
    Circle c;
    Ptr<Circle>pc{&c};
    f(pc);
}