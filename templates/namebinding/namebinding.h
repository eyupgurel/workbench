//
// Created by egl on 6/5/19.
//

#ifndef WORKBENCH_NAMEBINDING_H
#define WORKBENCH_NAMEBINDING_H

#include <iostream>
using namespace std;
namespace templates{

    void f(double) { cout << "Function f(double)" << endl; }

    template <class A> struct container{ // point of definition of container
        void member1(){
            // This call is not template dependent,
            // because it does not make any use of a template parameter.
            // The name is resolved at the point of definition, so f(int) is not visible.
            f(1);
        }
        void member2(A arg);
    };

    void f(int) { cout << "Function f(int)" << endl; }

    void h(double) { cout << "Function h(double)" << endl; }

    template <class A> void container<A>::member2(A arg){
        // This call is template dependent, so qualified name lookup only finds
        // names visible at the point of instantiation.
        templates::h(arg);
    }

    template struct container<int>; // point of instantiation of container<int>

    void h(int) { cout << "Function h(int)" << endl; }

}


#endif //WORKBENCH_NAMEBINDING_H
