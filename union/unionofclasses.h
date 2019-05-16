//
// Created by egl on 5/15/19.
//

#ifndef WORKBENCH_UNIONOFCLASSES_H
#define WORKBENCH_UNIONOFCLASSES_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace unions {
    union S{
        string str;
        vector<int> vec;
        ~S(){}
    };
    void drive_union_of_classes();
}


#endif //WORKBENCH_UNIONOFCLASSES_H
