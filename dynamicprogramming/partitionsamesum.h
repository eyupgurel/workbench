//
// Created by egl on 9/30/19.
//

#ifndef WORKBENCH_PARTITIONSAMESUM_H
#define WORKBENCH_PARTITIONSAMESUM_H
#include <numeric>
#include <iostream>
#include <stack>

using namespace std;

namespace dynamicprogramming{
    void recursive_sum(int arr[], int n, int i, int partial_sum, stack<int>& set, stack<stack<int>>&sets);
    bool partition(int arr[], int n, int sum);
    void drive_partition_same_sum();
}

#endif //WORKBENCH_PARTITIONSAMESUM_H
