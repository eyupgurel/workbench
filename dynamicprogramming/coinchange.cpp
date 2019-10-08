//
// Created by egl on 10/7/19.
//

#include "coinchange.h"

using namespace dynamicprogramming;

void dynamicprogramming::count_coin_change_ways(vector<int>& coins, int offset, int total_sum, int& ways) {

    if(offset<0 || total_sum < 0 )
        return;
    if(total_sum == 0){
        ways+=1;
        return;
    }

    count_coin_change_ways(coins, offset, total_sum - coins[offset], ways);
    count_coin_change_ways(coins, offset-1, total_sum, ways);
}


void dynamicprogramming::drive_coin_change_ways() {
    vector<int> coinset1{1,2,3};
    int ways{0};
    count_coin_change_ways(coinset1, coinset1.size()-1 , 4,ways);

    vector<int>coinset2{2, 5, 3, 6};
    ways=0;
    count_coin_change_ways(coinset2,coinset2.size()-1,10,ways);


    vector<int>coinset3{1, 3, 5, 7};
    ways=0;
    count_coin_change_ways(coinset3,coinset3.size()-1,15,ways);

}

