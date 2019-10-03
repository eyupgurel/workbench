//
// Created by egl on 10/2/19.
//

#ifndef WORKBENCH_BOOLEANPARENTHESIZATION_H
#define WORKBENCH_BOOLEANPARENTHESIZATION_H

#include <set>
#include <map>
using namespace std;

namespace dynamicprogramming{
    template<size_t N>
    int count_ways(bool (&symbols)[N], char(&operations)[N-1]);
    void drive_boolean_parenthesization();
}

#endif //WORKBENCH_BOOLEANPARENTHESIZATION_H
