//
// Created by egl on 9/25/19.
//

#include "setsofnumbersthataddup.h"

using namespace dynamicprogramming;
bool dynamicprogramming::find_sets_of_numbers_that_addup_to_N(vector<int> &set, int i, int n, int& r, map<pair<int,int>,bool>& history) {

    auto pair = make_pair(i,n);
    cout << i << " " << n << endl;
    if(history.find(pair)!=history.end()){
        return history[pair];
    }
    bool match;
    if(set[i]==n){ //last element is equal to the remainder we are done it is a match
        r++;
        match = true;
    } else if (set[i]>n || i==set.size()-1){
        match = false;
    } else{
        //There are two alternatives
        auto b1 = find_sets_of_numbers_that_addup_to_N(set, i+1, n-set[i],r,history); //include current number
        auto b2 = find_sets_of_numbers_that_addup_to_N(set, i+1, n,r,history); //exclude current number
        match = b1 || b2;
    }
    history[pair]=match;
    return match;
}

void dynamicprogramming::drive_to_find_sets_of_numbers() {
    vector<int> set{2,4,6,10,8,8,16};
    int r = 0;
    map<pair<int,int>,bool> history;
    auto b= find_sets_of_numbers_that_addup_to_N(set,0,16,r,history);
}