//
// Created by egl on 10/7/19.
//

#include "coinchange.h"

using namespace dynamicprogramming;

int dynamicprogramming::bottom_up_count_change_ways(vector<int> &coins, int total_sum) {
    int matrix[total_sum+1][coins.size()+1];
    memset(matrix,0,sizeof(int)*(total_sum+1)*(coins.size()+1));
    for(auto j=0;j<=coins.size();++j){
        matrix[0][j]=1;
    }
    for(auto i=1;i<=total_sum;++i){
        matrix[i][0]=0;
    }

    for(auto i=1;i<=total_sum;++i){
        for(auto j=1;j<=coins.size();++j){
            matrix[i][j] = matrix[i][j-1];
            if((i-coins[j-1])>=0){
                matrix[i][j]+= matrix[i-coins[j-1]][j];
            }

        }
    }

    for(auto i=0;i<=total_sum;++i){
        for(auto j=0;j<=coins.size();++j){
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }

    return matrix[total_sum][coins.size()];

}

int dynamicprogramming::top_down_count_change_ways(vector<int>& coins, int offset, int total_sum) {

    if(offset<0 || total_sum < 0 )
        return 0;
    if(total_sum == 0){
        return 1;
    }
    int ways{0};

    ways+= top_down_count_change_ways(coins, offset, total_sum - coins[offset]);
    ways+= top_down_count_change_ways(coins, offset-1, total_sum);
    return ways;
}


void dynamicprogramming::drive_coin_change_ways() {
    vector<int> coinset1{1,2,3};

    auto ways = bottom_up_count_change_ways(coinset1,4);

    ways=top_down_count_change_ways(coinset1, coinset1.size()-1 , 4);

    vector<int>coinset2{2, 5, 3, 6};
    ways=top_down_count_change_ways(coinset2,coinset2.size()-1,10);

    ways = bottom_up_count_change_ways(coinset2,10);

    vector<int>coinset3{1, 3, 5, 7};
    ways=top_down_count_change_ways(coinset3,coinset3.size()-1,15);

    ways = bottom_up_count_change_ways(coinset3,15);

}





