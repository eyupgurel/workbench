//
// Created by egl on 5/14/19.
//

#ifndef WORKBENCH_OPERATORS_H
#define WORKBENCH_OPERATORS_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace operators {
    struct Assoc{
        vector<pair<string,int>>vec; // vector of {name,value} pairs
        const int& operator[](const string&)const;
        int& operator[](const string &);
    };

    void drive_assoc();
}

#endif //WORKBENCH_OPERATORS_H
