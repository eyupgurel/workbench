//
// Created by egl on 9/25/19.
//

#ifndef WORKBENCH_SETSOFNUMBERSTHATADDUP_H
#define WORKBENCH_SETSOFNUMBERSTHATADDUP_H

#include <vector>
#include <map>
#include <iostream>
using namespace std;
namespace dynamicprogramming{
    bool find_sets_of_numbers_that_addup_to_N(vector<int>& set, int i, int n, int& r, map<pair<int,int>,bool>& history);
    void drive_to_find_sets_of_numbers();
}


#endif //WORKBENCH_SETSOFNUMBERSTHATADDUP_H
