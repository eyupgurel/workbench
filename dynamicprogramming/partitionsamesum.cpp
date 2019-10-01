//
// Created by egl on 9/30/19.
//

#include "partitionsamesum.h"

using namespace dynamicprogramming;

bool dynamicprogramming::partition(int arr[], int n, int target_sum) {
    bool has_sum[target_sum+1][n+1]{false};

    for(int j=0;j<n+1;++j)
        has_sum[0][j]=true;

    for(int i=1;i<target_sum+1;++i)
        has_sum[i][0]=false;

    for(int i=1;i<target_sum+1;++i){
        for(int j=1;j<n+1;++j){
            has_sum[i][j]= has_sum[i][j-1];
            if(arr[j-1]<=i)
                has_sum[i][j]|=has_sum[i-arr[j-1]][j-1];
        }
    }

    // uncomment this part to print table
    for (int i = 0; i < target_sum+1; ++i){
        for (int j = 0; j < n+1; ++j){
            cout << has_sum[i][j] << " ";
        }
        cout<<endl;
    }


    return has_sum[target_sum][n];
}



void dynamicprogramming::recursive_sum(int arr[], int n, int i, int partial_sum, stack<int>& set, stack<stack<int>>&sets){
    if (partial_sum == 0) {
        sets.push(set);
        return;
    }
    if(i==n || partial_sum < 0) return;
    set.push(arr[i]);
    recursive_sum(arr,n,i+1,partial_sum-arr[i],set,sets);
    set.pop();
    recursive_sum(arr,n,i+1,partial_sum,set,sets);
}



void dynamicprogramming::drive_partition_same_sum(){
    int arr1[]{1, 5, 11, 5};
    auto arr_sum1 = accumulate(arr1,arr1+4,0);
    stack<int> set1;
    stack<stack<int>> sets1;
    if(arr_sum1 % 2 == 0) {
        recursive_sum(arr1, 4, 0, arr_sum1 / 2, set1, sets1);
        auto has=partition(arr1,4,arr_sum1/2);
    }
    int arr2[] {1, 0, 3};
    auto arr_sum2 = accumulate(arr2,arr2+3,0);
    stack<int> set2;
    stack<stack<int>> sets2;
    if (arr_sum2 % 2 == 0)
        recursive_sum(arr2,3,0,arr_sum2/2,set2,sets2);

   int arr3[]{3, 1, 1, 2, 2, 1};
   auto arr_sum3 = accumulate(arr3,arr3+6,0);
    if(arr_sum3 % 2 == 0) {
        auto has =partition(arr3,6,arr_sum3/2);
        cout << has;
    }



}