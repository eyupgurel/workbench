//
// Created by egl on 5/3/19.
//

#ifndef WORKBENCH_SIMPLEMATRIX_H
#define WORKBENCH_SIMPLEMATRIX_H
#include <array>
#include <memory>
using namespace std;
namespace containers{
    template<class T>
    class simplematrix {
    private:
        array<int,2>dim;
        T* elem; //pointer to dim[0]*dim[1] elements of type T
    public:
        simplematrix(int d1, int d2):dim{d1,d2},elem{new T[d1*d2]}{}
        int size() const{return dim[0]*dim[1];}

        simplematrix(const simplematrix&);
        simplematrix& operator=(const simplematrix&);
        simplematrix(simplematrix&&);
        simplematrix& operator=(simplematrix&&)noexcept;
        ~simplematrix(){delete[] elem;}
    };

    template<class T>
    simplematrix<T> operator+(const simplematrix<T>& l, const simplematrix<T>& b);

    void drive_simple_matrix();

}


#endif //WORKBENCH_SIMPLEMATRIX_H
