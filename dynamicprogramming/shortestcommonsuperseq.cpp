//
// Created by egl on 9/24/19.
//

#include "shortestcommonsuperseq.h"

using namespace dynamicprogramming;

string dynamicprogramming::find_shortest_common_superseq(string a, string b) {
    if(a.empty()) return b;
    if(b.empty()) return a;

    if(a.front()==b.front()){
        string scs;
        scs.push_back(a.front());
        a.erase(a.begin(),a.begin()+1);
        b.erase(b.begin(), b.begin()+1);
        return scs + find_shortest_common_superseq(a,b);
    } else{
        string ca = a;
        ca.erase(ca.begin(),ca.begin()+1);
        string scs1;
        scs1.push_back(a.front());
        scs1 += find_shortest_common_superseq(ca,b);

        string cb = b;
        cb.erase(cb.begin(),cb.begin()+1);
        string scs2;
        scs2.push_back((b.front()));
        scs2 += find_shortest_common_superseq(a,cb);
        return scs1.length() < scs2.length() ? scs1 : scs2;
    }

}

void dynamicprogramming::drive() {
     string a{"ABCBDAB"};
     string b{"BDCABA"};
    //string a{"AB"};
    //string b{"BA"};
     string scs=find_shortest_common_superseq(a,b);
}