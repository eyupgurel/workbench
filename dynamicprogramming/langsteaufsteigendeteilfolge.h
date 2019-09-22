//
// Created by egl on 9/18/19.
//

#ifndef WORKBENCH_LANGSTEAUFSTEIGENDETEILFOLGE_H
#define WORKBENCH_LANGSTEAUFSTEIGENDETEILFOLGE_H
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;
namespace dynamicprogramming{
    vector<int> lese_folge();
    vector<vector<int>>  berechnen_alle_langste_aufsteigende_teilfolge();
    vector<int>  berechnen_langste_aufsteigende_teilfolge();
}

#endif //WORKBENCH_LANGSTEAUFSTEIGENDETEILFOLGE_H
