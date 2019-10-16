//
// Created by egl on 10/16/19.
//

#ifndef WORKBENCH_KNAPSACK_H
#define WORKBENCH_KNAPSACK_H
#include <vector>
using namespace std;
namespace dynamicprogramming{
    int load_knapsack(vector<int>& item_value, vector<int>& item_weight, int capacity, int index);

    int bottom_up_solve_knapsack(vector<int>& item_value, vector<int>& item_weight, int capacity);

    void drive_knapsack();
}

#endif //WORKBENCH_KNAPSACK_H
