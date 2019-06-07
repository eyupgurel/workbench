//
// Created by egl on 6/6/19.
//

#ifndef WORKBENCH_CONVERSIONS_H
#define WORKBENCH_CONVERSIONS_H
#include <iostream>
using namespace std;
namespace templates {
    class Shape{};

    class Circle:public Shape{

    };


    template<typename T>
    class Ptr{
        T* p;
    public:

        Ptr(T* pp):p{pp}{
            cout<< "Ptr(T* pp) for " << typeid(T).name() << endl;
        }
        template<typename T2>
        explicit operator Ptr<T2>(){  //type conversion operator
            return Ptr<T2>{p};
        };
    };

    void drive_template_conversions();
}


#endif //WORKBENCH_CONVERSIONS_H
