//
// Created by egl on 9/25/19.
//

#ifndef WORKBENCH_SETSOFNUMBERSTHATADDUP_H
#define WORKBENCH_SETSOFNUMBERSTHATADDUP_H

#include <vector>
#include <map>
#include <iostream>
#include <bitset>
using namespace std;
namespace dynamicprogramming{
    template<int N>
    bool find_sets_of_numbers_that_addup_to_N(vector<int>& set, bitset<N>& subset, int i, int n, int& r, vector<bitset<N>>& match_set, map<pair<int,int>,bool>& history);
    void drive_to_find_sets_of_numbers();
}


#endif //WORKBENCH_SETSOFNUMBERSTHATADDUP_H
