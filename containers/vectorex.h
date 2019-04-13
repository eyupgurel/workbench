//
// Created by egl on 4/12/19.
//

#ifndef WORKBENCH_VECTOREX_H
#define WORKBENCH_VECTOREX_H

#include <memory>
#include "vector_base.h"
using namespace std;

namespace containers {
    template<class T, class A = allocator<T>>
    class vectorex {
    private:
        vector_base<T,A> b;
        void destroy_elements();
    public:
        using size_type = unsigned int;
        explicit vectorex(size_type n, const T& val=T(), const A& a=A());
        vectorex(const vectorex<T,A>& v); //copy constructor
        vectorex& operator=(const vectorex& v); // copy assignment
        vectorex(const vectorex&& v); // move constructor
        vectorex& operator=(const vectorex&& v); // move assignment
        ~vectorex();

        size_type size(){return b.space-b.elem;}
        size_type capacity(){return b.last-b.elem;}
        void reserve(size_type n); //increase capacity to n
        void resize(size_type n, const T& = {});
        void clear(){resize(0);}
        void push_back(const T&);
    };

}


#endif //WORKBENCH_VECTOREX_H
