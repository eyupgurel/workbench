//
// Created by egl on 5/14/19.
//

#include "operators.h"
using namespace operators;

int& Assoc::operator[](const string & s) {
    for(auto& p: vec)
        if(s==p.first)return p.second;
    vec.emplace_back(s,0);
    return vec.back().second;
}

void operators::drive_assoc() {
    Assoc values;
    string buf;
    ifstream is{"doc"};
    while(is>>buf)
        ++values[buf];
    for(auto& p: values.vec)
        cout << '{' << p.first << ',' << p.second << "}\n";
}