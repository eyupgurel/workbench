//
// Created by egl on 9/21/19.
//

#include "zahlendreieck.h"

using namespace dynamicprogramming;

 vector<int> dynamicprogramming::berechnen_maximale_gesammt_kette(Matrix<int, 2> m) {
    assert(m.extent(0)==m.extent(1)); // Must be a square matrix
    int size =m.extent(0);
    auto max {0};
    auto max_j{0};
    vector<int>kette;
    Matrix<int,2>ancestor_offset(m.extent(0),m.extent(1));
    for(int i=0;i<size;++i){
        for(int j=0; j<=i;++j){
            auto offset = i==0 ? 0 : j==0 ? 0 :  i==j ? -1 :  m[i-1][j-1] > m[i-1][j] ? -1 : 0;
            ancestor_offset[i][j]+=offset;
            auto max_vorganger = i==0 ? 0 : j==0 ? m[i-1][0] : m[i-1][j+offset];
            m[i][j]+=max_vorganger;
            if(i==size-1){
                max_j=max<m[i][j]?j:max_j;
                max=max<m[i][j]?m[i][j]:max;
            }
        }
    }
    kette.emplace(kette.begin(), max_j);
    for(int i=size-2;i>-1;--i){
        kette.emplace(kette.begin(),kette[0]+ancestor_offset[i+1][kette[0]]);
    }
    return kette;
}

int dynamicprogramming::berechnen_maximale_gesammt(Matrix<int, 2>& m, vector<int> kette){
    int size = kette.size();
    auto sum = 0;
    for(int i=size-1;i>-1;--i){
        sum+=m[i][kette[i]];
    }
    return sum;
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

    auto kette = berechnen_maximale_gesammt_kette(m2);
    auto gesammt = berechnen_maximale_gesammt(m2, kette);
    cout << m2 << endl;

    cout << endl;
}