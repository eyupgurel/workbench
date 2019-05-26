//
// Created by egl on 5/25/19.
//

#ifndef WORKBENCH_REFERENCEDEDUCTION_H
#define WORKBENCH_REFERENCEDEDUCTION_H

#include <string>
#include "../../forward/forward.h"
using namespace std;
using namespace forward;

namespace templates {
template<typename T>
class Xref{
public:
    Xref(int i,T* p):index{i},elem{p},owned{true}{
        cout << "Xref(int i,T* p) called!" << endl;
    }
    Xref(int i, T& lr):index{i},elem{&lr},owned{false}{
        cout << "Xref(int i, T& lr) called!" << endl;
    }
    Xref(int i, T&& rr):index{i},elem{new T(move(rr))},owned{true}{
        cout << "Xref(int i, T&& rr) called!" << endl;
    }
    ~Xref(){if(owned) delete elem;}
private:
    int index;
    T* elem;
    bool owned;
};

void drive_Xref();
}


#endif //WORKBENCH_REFERENCEDEDUCTION_H
