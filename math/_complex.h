//
// Created by egl on 5/13/19.
//

#ifndef WORKBENCH__COMPLEX_H
#define WORKBENCH__COMPLEX_H

namespace math{
    using ldouble = long double;
    class _complex {
        ldouble re,im;
    public:
        constexpr _complex(ldouble r, ldouble i):re{r},im{i}{}
        _complex(ldouble r):re{r},im{0}{}
        _complex():re{0},im{0}{}

        constexpr ldouble real()const {return re;}
        void real(ldouble d){re=d;}
        constexpr ldouble imag()const {return im;}
        void imag(ldouble d){im=d;}
        _complex& operator+=(_complex z){re+=z.re,im+=z.im;return *this;}
        _complex& operator+=(ldouble r){re+=r;return *this;}
        _complex& operator-=(_complex z){re-=z.re,im-=z.im;return *this;}
    };
    constexpr _complex operator "" _i(ldouble d)
    {
        return {0,d}; // complex is a literal type
    }
    _complex operator+(_complex a, _complex b);
    _complex operator+(_complex a, ldouble r);
    _complex operator+(ldouble r, _complex b);

    void drive_complex();
}



#endif //WORKBENCH__COMPLEX_H
