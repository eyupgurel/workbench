//
// Created by egl on 9/21/19.
//

#ifndef WORKBENCH_ZAHLENDREIECK_H
#define WORKBENCH_ZAHLENDREIECK_H

#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include "../include/slab/matrix/matrix.h"

using namespace std;
using namespace slab;
namespace dynamicprogramming{
    vector<int> berechnen_maximale_gesammt_kette(Matrix<int, 2> m);
    int berechnen_maximale_gesammt(Matrix<int, 2>& m, vector<int> kette);
    void drive_maximale_dreieck_gesammt();
}

#endif //WORKBENCH_ZAHLENDREIECK_H
