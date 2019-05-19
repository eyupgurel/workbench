//
// Created by egl on 5/18/19.
//

#ifndef WORKBENCH_VECTOR_H
#define WORKBENCH_VECTOR_H
#include <vector>
#include <stdexcept>

using namespace std;

namespace inheritance{

    template<typename T>
    struct safe_vector: public vector<T> {
        using vector<T>::vector;
        T& operator[](size_t i){check(i); return this->at(i);}
        const T& operator[](size_t i)const{check(i); return this->at(i);}
        void check(size_t n){
            if(n>=this->size())
                throw range_error("safe_vector::check() failed!");
        }
    };
}


#endif //WORKBENCH_VECTOR_H
