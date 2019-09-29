//
// Created by egl on 9/25/19.
//

#include "longestcommonsubsequence.h"
using namespace dynamicprogramming;



string dynamicprogramming::find_longest_common_subsequence(string& lhs, string& rhs) {
    Matrix<int,2> matrix(lhs.length()+1,rhs.length()+1);
    for(size_t i=1;i<=lhs.length();++i){
        for(size_t j=1;j<=rhs.length();++j){
            if(lhs[i-1]==rhs[j-1]){
                matrix(i,j)= matrix[i-1][j-1]+1;
            } else{
                matrix(i,j) = matrix[i][j-1] > matrix[i-1][j] ? matrix[i][j-1] : matrix[i-1][j];
            }
        }
    }
    cout << matrix << endl;
    auto i=lhs.length();
    auto j= rhs.length();
    string res;
    while(i!=0 && j!=0){
        if(lhs[i-1]==rhs[j-1]){
            res.insert(res.begin(),lhs[i-1]);
            --i;
            --j;
        } else{
            //matrix(i-1,j) > matrix(i,j-1)?--i:--j;
            matrix(i,j-1) > matrix(i-1,j) ?--j:--i;
        }
    }
    return res;
}

void dynamicprogramming::drive_to_find_longest_common_subsequence() {
    //string lhs{"ABCBDAB"};
    //string rhs{"BDCABA"};

    string rhs{"ACABAD"};
    string lhs{"CABCA"};
    //string lhs{"GXTXAYB"};
    //string rhs{"AGGTAB"};

    auto lcs = find_longest_common_subsequence(lhs,rhs);
}