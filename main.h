//
// Created by egl on 2/7/19.
//

#ifndef WORKBENCH_MAIN_H
#define WORKBENCH_MAIN_H

#include "algorithms/mergesort.h"
#include "algorithms/hanoitower.h"
#include "containers/vector.h"
#include "containers/container.h"
#include "containers/vector_container.h"
#include "containers/list_container.h"

using namespace algorithms;
using namespace containers;
using vector = containers::vector;

void test_merge_sort();
void move_hanoi_towers();
void test_vector();
void test_container(container& c);


#endif //WORKBENCH_MAIN_H
