//
// Created by egl on 5/14/19.
//

#ifndef WORKBENCH_FUNCTIONOBJECT_H
#define WORKBENCH_FUNCTIONOBJECT_H

#include <complex>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
namespace functionobject{

    template<typename Iter, typename Fct>
    Fct for_each_apply_fct(Iter beg, Iter end, Fct fct){
        while(beg!=end)
            fct(*beg++);
        return fct;
    }

    template<typename T>
    class Add{
        complex<T> zval;
    public:
        Add(complex<T> z):zval{z}{}
        Add(T r, T i):zval{{r,i}}{}
        void operator()(complex<T>&z)const{z+=zval;}
    };
    template<typename T>
    void h1(vector<complex<T>>& vec, list<complex<T>>& lst, complex<T> z);

    template<typename T>
    void h2(vector<complex<T>>& vec, list<complex<T>>& lst, complex<T> z);

    template<typename T>
    void h3(vector<complex<T>>& vec, list<complex<T>>& lst, complex<T> z);

    void drive_function_object();
}

#endif //WORKBENCH_FUNCTIONOBJECT_H
