//
// Created by egl on 9/24/19.
//

#ifndef WORKBENCH_SHORTESTCOMMONSUPERSEQ_H
#define WORKBENCH_SHORTESTCOMMONSUPERSEQ_H

#include <string>
#include <vector>
#include <map>
using namespace std;
namespace dynamicprogramming{
    string find_shortest_common_superseq(string a, string b);
    //int find_shortest_common_superseq2(string& a, string& b, vector<pair<int,int>>& history, int pa, int pb);
    void drive_to_find_shortest_common_super_seq();

}


#endif //WORKBENCH_SHORTESTCOMMONSUPERSEQ_H
