//
// Created by egl on 10/10/19.
//

#include "rodcutting.h"
using namespace dynamicprogramming;

int dynamicprogramming::bottom_up_max_cut(map<int,int> &price_list) {
    for(size_t i=2;i<price_list.size();++i){
        int mid = floor(i/2);
        int partial_max{0};
        for(int j=0;j<=mid;++j){
            partial_max = price_list[j]+price_list[i-j] > partial_max ? price_list[j]+price_list[i-j] : partial_max;
        }
        price_list[i]=partial_max;
    }
    return price_list[price_list.size()-1];
}

int dynamicprogramming::max_cut(vector<int> &price_list, int index, int length) {

    if(index>price_list.size()-1 || length<=0)
        return 0;

    int cut = price_list[index-1] + max_cut(price_list, index, length - index);
    int no_cut = max_cut(price_list,index+1,length);

    return cut > no_cut ? cut : no_cut;
}

void dynamicprogramming::drive_rod_cutting_problem() {
    map<int,int>price_map{{0,0},{1,1},{2,5},{3,8},{4,9},{5,10},{6,17},{7,17},{8,20}};
    auto max_val = bottom_up_max_cut(price_map);
    vector<int> price_list{1, 5, 8, 9, 10, 17, 17, 20};
    max_val = max_cut(price_list, 1, 8);
    price_list = {3,5,8,9,10,17,17,20,24,30};
    max_val =  max_cut(price_list, 1, 10);
}


int dynamicprogramming::top_down_max_cut(vector<int> &price_list) {

    for(size_t i=0;i<price_list.size();++i){
        
    }


}