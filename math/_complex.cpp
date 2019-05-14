//
// Created by egl on 5/13/19.
//

#include "_complex.h"
using namespace math;

_complex math::operator+(_complex a, _complex b) {
    return a+=b;
}

_complex math::operator+(_complex a, ldouble r) {
    return {a.real()+r,a.imag()};
}

_complex math::operator+(ldouble r, _complex a) {
    return {a.real()+r,a.imag()};
}



void f(_complex x, _complex y, _complex z)
{
    _complex r1 {x+y+z}; // r1 = operator+(operator+(x,y),z)
    _complex r2 {x}; // r2 = x
    r2 += y;    // r2.operator+=(y)
    r2 += z;    // r2.operator+=(z)
}

void math::drive_complex(){
    _complex zq{1.2+12e3i};
    constexpr _complex cz{1.2,2.1};
     _complex z1{3.2,7.3};
    _complex z2{0.2,4.4};
    _complex z3{1.1,3};
    f(z1,z2,z3);
}