//
// Created by egl on 6/3/19.
//

#ifndef WORKBENCH_SPECIALIZATION_H
#define WORKBENCH_SPECIALIZATION_H
#include <iostream>
using namespace std;
namespace templates {

    template<typename T>
    class SVector{
        int size;
        T* elems;
    public:
        SVector():size{0},elems{nullptr}{
            cout << "SVector is being default constructed" << endl;
        }
        explicit SVector(int sz):size{sz},elems{new T[sz]}{
            cout << "SVector is being constructed with int sz:" << sz << endl;
        }
        T& operator[](const int i){
            return elems[i];
        }
        ~SVector(){
            delete[] elems;
            cout << "SVector is destructed!" << endl;
        }
    };

    template<>
    class SVector<void*>{ // complete specialization
        int size;
        void** elems;
    public:
        SVector():size{0},elems{nullptr}{
            cout << "SVector<void*> is being default constructed" << endl;
        }
        explicit SVector(int sz):size{sz},elems{new void*[sz]}{
            cout << "SVector<void*> is being constructed with int sz:" << sz << endl;
        }
        void*& operator[](const int i){
            return elems[i];
        }
        ~SVector(){
            delete[] elems;
            cout << "SVector<void*> is destructed!" << endl;
        }
    };

    template<typename T>
    class SVector<T*>:private SVector<void*>{ // partial specialization
    public:
        using Base=SVector<void*>;
        SVector():Base(){
            cout << "SVector<T*>:private SVector<void*> is being default constructed" << endl;
        }
        explicit SVector(int sz):Base(sz){
            cout << "SVector<T*>:private SVector<void*> is being constructed with int sz:" << sz << endl;
        }
        T*& operator[](const int i){
            return reinterpret_cast<T*&>(Base::operator[](i));
        }

    };


    void drive_specializaton_cases();

}


#endif //WORKBENCH_SPECIALIZATION_H
