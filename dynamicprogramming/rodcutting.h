//
// Created by egl on 10/10/19.
//

#ifndef WORKBENCH_RODCUTTING_H
#define WORKBENCH_RODCUTTING_H
#include <vector>
#include <map>
#include <cmath>
using namespace std;
namespace dynamicprogramming{
    int max_cut(vector<int>& price_list, int index, int length);
    int bottom_up_max_cut(map<int,int>& price_list);
    int top_down_max_cut(vector<int>& price_list);
    void drive_rod_cutting_problem();
}


#endif //WORKBENCH_RODCUTTING_H
