//
// Created by egl on 5/14/19.
//

#ifndef WORKBENCH_TINY_H
#define WORKBENCH_TINY_H
#include <stdexcept>
using namespace std;
namespace typeconversion {

    class Tiny {
        char v;
        void assign(int i){
            if(i&~077) throw range_error("Bad range"); v=i;}
    public:
        Tiny(int i){assign(i);}
        Tiny& operator=(int i){assign(i); return *this;}
        operator int()const{
            return v;
        } //conversion to int function;
    };

    void drive_tiny();

}


#endif //WORKBENCH_TINY_H
