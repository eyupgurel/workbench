//
// Created by egl on 5/15/19.
//

#ifndef WORKBENCH_BASE3_H
#define WORKBENCH_BASE3_H

namespace operators{

constexpr int ipow(int i, int n){
    return n>0 ? i*ipow(i,n-1):1;
}

template<char c>
constexpr int b3_helper(){
    static_assert(c<'3',"not a ternary digit");
    return c;
}

template<char c, char... tail>
constexpr int b3_helper(){
    static_assert(c<'3',"not a ternary digit");
    return ipow(3, sizeof...(tail))*(c-'0') + b3_helper(tail...);
}

template<char... chars>
constexpr int operator"" _b3(){
    return b3_helper(chars...);
}

void drive_base3();

}

#endif //WORKBENCH_BASE3_H
