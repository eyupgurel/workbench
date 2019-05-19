//
// Created by egl on 5/19/19.
//

#ifndef WORKBENCH_POINTER_H
#define WORKBENCH_POINTER_H
#include <iostream>
using namespace std;
namespace pointer{
    struct C{
        const char* val;
        int i;
        void print(int x){cout << val << x << '\n';}
        int f1(int n){
            cout << "C::f1 called with:" << n << '\n';
            return i;
        }
        void f2(){
            cout << "C::f2 called" << '\n';
        }
        C(const char* v):val{v}{};
    };

    using Pmfi = void (C::*)(int); // pointer to member function taking an int
    using Pm = const char* C::*;   // pointer to char* data member of C


    class X {
    public:
        int a;
        void f(int b) {
            cout << "The value of b is "<< b << endl;
        }
    };

    class Std_interface {
    public:
        virtual void start() = 0;
        virtual void suspend() = 0;
        virtual void resume() = 0;
        virtual void quit() = 0;
        virtual void full_size() = 0;
        virtual void small() = 0;
        virtual ~Std_interface() {}
    };
    using Pstd_mem = void (Std_interface::*)(); // pointer-to-member type

    class device: public Std_interface{
        void start(){}
        void suspend(){
            cout << "device suspended\n";
        }
        void resume() {}
        void quit(){}
        void full_size() {}
        void small(){}
    };

    void derive_pointer();
}



#endif //WORKBENCH_POINTER_H
