//
// Created by egl on 9/17/19.
//

#include "fibonacci.h"

using namespace fibonacci;
using namespace std;

int fibonacci::berechnen_zahlen_der_kannichen() {
    auto kannichenzahlen = 2;

    array<int,13> zeugen{2};
    for(auto i=1;i<13;++i){
        auto geschlectsreifzahlen=0;
        for(auto j=0;j<i-1;++j){
            geschlectsreifzahlen+=zeugen[j];
        }
        kannichenzahlen += geschlectsreifzahlen;
        zeugen[i] = kannichenzahlen;
    }
    return kannichenzahlen;
}
