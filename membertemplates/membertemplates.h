//
// Created by egl on 5/25/19.
//

#ifndef WORKBENCH_MEMBERTEMPLATES_H
#define WORKBENCH_MEMBERTEMPLATES_H

namespace membertemplates {
    template<typename Scalar>
    class _complex{
    public:
        _complex():re{},im{}{}
        template<typename T>
        _complex(T r, T i):re{r},im{r}{}
        _complex(_complex& c):re{c.real()},im{c.imag()}{}
        template<typename T>
        _complex(_complex<T>c):re{c.real()},im{c.imag()}{}
        Scalar real(){return re;}
        Scalar imag(){return im;};
    private:
        Scalar re;
        Scalar im;
    };
    void drive_membertemplates();
}


#endif //WORKBENCH_MEMBERTEMPLATES_H
