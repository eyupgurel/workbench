//
// Created by egl on 9/29/19.
//


#include "eggdropproblem.h"

using namespace dynamicprogramming;

int dynamicprogramming::count_drop(int n, int k, Matrix<int,2>& memory){ //find guaranteed number of min egg drops to delineate break line
    if(memory[n][k]!=-1) return memory[n][k];
    if(n==0) return 0;
    if(n==1) return k;
    if(k==0 || k==1) return k;

    auto drop_count = INT_MAX;
    for(auto i=1; i<=k; ++i){
        auto case_break = 1 + count_drop(n-1,i-1,memory);
        auto case_no_break = 1 + count_drop(n,k-i,memory);
        auto ith_drop_count = case_break > case_no_break ? case_break : case_no_break;
        drop_count = ith_drop_count < drop_count ? ith_drop_count : drop_count;
    }
    memory(n,k)=drop_count;
    return drop_count;
}

void dynamicprogramming::drive_egg_problem_solution(){
    Matrix<int,2> memory(101,101);
    for(auto i=0; i<101;  ++i)
        for(auto j=0; j<101; ++j)
            memory(i,j)=-1;
    auto count = count_drop(2,100,memory);
}