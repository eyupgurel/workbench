//
// Created by egl on 6/27/19.
//

#include <algorithm>
#include "sort.h"

using namespace stl::sort;

bool Nocase::operator()(const string &lhs, const string &rhs) const {
    // return true if lhs is lexicographically less than rhs, not taking case into account
    auto p = lhs.begin();
    auto q = rhs.begin();
    while(p!=lhs.end() && q!=rhs.end() && toupper(*p)==toupper(*q)){
        ++p;
        ++q;
    }
    if(p==lhs.end()) return q!=rhs.end();
    if(q==rhs.end()) return true;
    return toupper(*p)<toupper(*q);
}

void stl::sort::drive_stl_sort(){

    vector<string>fruit{"apple", "pear", "Apple", "Pear", "lemon"};

    std::sort(fruit.begin(),fruit.end(),Nocase());
}