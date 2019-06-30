//
// Created by egl on 6/27/19.
//

#ifndef WORKBENCH_SORT_H
#define WORKBENCH_SORT_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace stl::sort{
    class Nocase{
    public:
        bool operator()(const string&,const string&)const;
    };

    void drive_stl_sort();
}


#endif //WORKBENCH_SORT_H