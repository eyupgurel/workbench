//
// Created by egl on 10/16/19.
//

#include <cstring>
#include "knapsack.h"
using namespace dynamicprogramming;

int dynamicprogramming::load_knapsack(vector<int> &item_value, vector<int> &item_weight, int capacity, int index) {
        //boundary conditions
        if(index >= item_value.size())
            return 0;

        if(capacity-item_weight[index]<0)
            return  load_knapsack(item_value,item_weight,capacity, index+1);

        return max(item_value[index] + load_knapsack(item_value, item_weight, capacity - item_weight[index],index+1), load_knapsack(item_value,item_weight,capacity, index+1));
}

int dynamicprogramming::bottom_up_solve_knapsack(vector<int> &item_value, vector<int> &item_weight, int capacity) {
  //  int subproblem[capacity+1][item_value.size()+1];

    int subproblem[capacity+1][item_value.size()+1];
    memset(subproblem,0,(capacity+1)*(item_value.size()+1)*sizeof(int));
    for(auto i=1; i<=capacity+1;++i){
        for(auto j=1;j<=item_value.size();++j){
            int include = i - item_weight[j-1] < 0 ? 0 : subproblem[i - item_weight[j-1]][j-1] + item_value[j-1];
            int exclude = subproblem[i][j-1];
            subproblem[i][j]=max(include,exclude);
        }
    }
    return subproblem[capacity][item_value.size()];
}

void dynamicprogramming::drive_knapsack() {
    vector<int> item_value {60, 100, 120};
    vector<int> item_weight {10, 20, 30};
    auto max_val = bottom_up_solve_knapsack(item_value,item_weight,50);
    max_val = load_knapsack(item_value,item_weight,50,0);

}

