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


void test_merge_sort();
void move_hanoi_towers();
template<typename T>
vector<T> square_vector(vector<T>& v);
void test_vector();
template<typename T>
void test_container(container<T>& c);


#endif //WORKBENCH_MAIN_H
