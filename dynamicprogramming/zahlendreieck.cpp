//
// Created by egl on 9/21/19.
//

#include "zahlendreieck.h"

using namespace dynamicprogramming;

 int dynamicprogramming::berechnen_maximale_gesammt(Matrix<int, 2>& m) {
    assert(m.extent(0)==m.extent(1)); // Must be a square matrix
    auto max {0};
    auto max_j{0};
    for(size_t i=0;i<m.extent(0);++i){
        for(size_t j=0; j<=i;++j){
            auto max_vorganger = i==0 ? 0 : j==0 ? m[i-1][0] :  i==j ? m[i-1][j-1] : m[i-1][j-1] > m[i-1][j] ? m[i-1][j-1] : m[i-1][j];
            m[i][j]+=max_vorganger;
            if(i==m.extent(0)-1){
                max=max<m[i][j]?m[i][j]:max;
                max_j=max<m[i][j]?j:max_j;
            }
        }
    }
    return max;
}

void dynamicprogramming::drive_maximale_dreieck_gesammt() {
    Matrix<int,2> m2 {
            {10,-1,-1,-1,-1,-1,-1},
            {82,81,-1,-1,-1,-1,-1},
            {4, 6,10,-1,-1,-1,-1},
            {2, 14,35,7,-1,-1,-1},
            {41,3,52,26,15,-1,-1},
            {32,90,11,87,56,23,-1},
            {54,65,89,32,71,9,31}
    };

    cout << m2 << endl;

    auto w = berechnen_maximale_gesammt(m2);
    cout << m2 << endl;

    cout << endl;
}