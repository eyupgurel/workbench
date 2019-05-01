//
// Created by egl on 5/1/19.
//

#ifndef WORKBENCH_LIFETIME_H
#define WORKBENCH_LIFETIME_H
#include <vector>
#include <string>
#include <iostream>


using namespace std;

namespace lifetime{
    struct Tracer{
        string mess;
        Tracer(const string& s);
        ~Tracer();

    };

    void trace(const vector<int>& v);

    void drive();
}


#endif //WORKBENCH_LIFETIME_H
