//
// Created by egl on 10/7/19.
//

#ifndef WORKBENCH_COINCHANGE_H
#define WORKBENCH_COINCHANGE_H
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
namespace dynamicprogramming{
    int bottom_up_count_change_ways(vector<int>& coins, int total_sum);
    int top_down_count_change_ways(vector<int>& coins, int offset, int total_sum);
    void drive_coin_change_ways();
}

#endif //WORKBENCH_COINCHANGE_H
