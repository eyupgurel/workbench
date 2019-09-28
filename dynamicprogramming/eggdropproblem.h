//
// Created by egl on 9/29/19.
//

#ifndef WORKBENCH_EGGDROPPROBLEM_H
#define WORKBENCH_EGGDROPPROBLEM_H
#include <climits>
#include "../include/slab/matrix/matrix.h"
using namespace slab;
namespace dynamicprogramming{
    int count_drop(int n, int k, Matrix<int,2>& memory);
    void drive_egg_problem_solution();
}

#endif //WORKBENCH_EGGDROPPROBLEM_H
