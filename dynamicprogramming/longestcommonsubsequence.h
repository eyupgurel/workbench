//
// Created by egl on 9/25/19.
//

#ifndef WORKBENCH_LONGESTCOMMONSUBSEQUENCE_H
#define WORKBENCH_LONGESTCOMMONSUBSEQUENCE_H
#include <string>
#include <vector>
#include <iostream>
#include "../include/slab/matrix/matrix.h"
using namespace std;
using namespace slab;
namespace dynamicprogramming {
    string find_longest_common_subsequence(string& lhs, string& rhs);
    void drive_to_find_longest_common_subsequence();
}

#endif //WORKBENCH_LONGESTCOMMONSUBSEQUENCE_H
