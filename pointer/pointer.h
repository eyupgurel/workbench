//
// Created by egl on 5/19/19.
//

#ifndef WORKBENCH_POINTER_H
#define WORKBENCH_POINTER_H
#include <iostream>
using namespace std;
namespace pointer{
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
