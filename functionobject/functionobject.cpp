//
// Created by egl on 5/14/19.
//

#include "functionobject.h"

void functionobject::drive_function_object() {
    vector<complex<double>> vec{{1.1,0.2},{3.2,7.5}};
    list<complex<double>>lis{{0,1},{2,3}};
    complex<double>z{1.6,1.2};
    h1(vec,lis,z);
    h2(vec,lis,z);
    h3(vec,lis,z);
}

template<typename T>
void functionobject::h1(vector<complex<T>> &vec, list<complex<T>> &lst, complex<T> z) {
    for_each(vec.begin(),vec.end(),Add{2.0,3.0});
    for_each(lst.begin(),lst.end(),Add{z});
}

template<typename T>
void functionobject::h2(vector<complex<T>> &vec, list<complex<T>> &lst, complex<T> z) {
    for_each_apply_fct(vec.begin(),vec.end(),Add{2.0,3.0});
    for_each_apply_fct(lst.begin(),lst.end(),Add{z});
}

template<typename T>
void functionobject::h3(vector<complex<T>> &vec, list<complex<T>> &lst, complex<T> z) {
    for_each_apply_fct(vec.begin(),vec.end(),[](complex<T>&zelem){zelem+=complex<double>{2.0,3.0};});
    for_each_apply_fct(lst.begin(),lst.end(),[z](complex<T>&zelem){zelem+=z;});
}