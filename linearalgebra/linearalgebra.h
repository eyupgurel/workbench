//
// Created by egl on 5/16/19.
//

#ifndef WORKBENCH_LINEARALGEBRA_H
#define WORKBENCH_LINEARALGEBRA_H


#include <cstddef>
using namespace std;
namespace linearalgebra {

constexpr size_t rc_max{4};
class Matrix;
class Vector{
    float elem[rc_max]{1.0,2.2,0.2,3.7};
    friend Vector operator*(const Matrix&,const Vector&);

};

class Matrix{
    Vector v[rc_max];
    friend Vector operator*(const Matrix&,const Vector&);
};

Vector operator*(const Matrix& m, const Vector& v){
    Vector r;
    for(auto i=0;i<rc_max;++i){
        r.elem[i]=0;
        for(auto j=0;j<rc_max;++j){
           r.elem[i]+=m.v[i].elem[j]*v.elem[i];
        }
    }
    return r;
}



}


#endif //WORKBENCH_LINEARALGEBRA_H
