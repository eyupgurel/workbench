//
// Created by egl on 9/25/19.
//

#include "setsofnumbersthataddup.h"

using namespace dynamicprogramming;
void dynamicprogramming::find_sets_of_numbers_that_addup_to_N(vector<int> &set, int i, int n, int& r) {
    //termination condition
    if(set[i]==n){ //last element is equal to the remainder we are done it is a match
        r++;
        return;
    }
    if (set[i]>n || i==set.size()-1) return;
    //There are two alternatives
    find_sets_of_numbers_that_addup_to_N(set, i+1, n-set[i],r); //include current number
    find_sets_of_numbers_that_addup_to_N(set, i+1, n,r); //exclude current number
}

void dynamicprogramming::drive_to_find_sets_of_numbers() {
    vector<int> set{2,4,6,10,8,8,16};
    int r = 0;
    find_sets_of_numbers_that_addup_to_N(set,0,16,r);
}