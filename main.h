//
// Created by egl on 2/7/19.
//

#ifndef WORKBENCH_MAIN_H
#define WORKBENCH_MAIN_H

#include "common.h"
#include "algorithms/mergesort.h"
#include "algorithms/hanoitower.h"
#include "algorithms/shellsort.h"
#include "containers/vector.h"
#include "containers/container.h"
#include "containers/vector_container.h"
#include "containers/list_container.h"
#include "containers/myarray.h"
#include "union/Entry.h"

using namespace algorithms;
using namespace containers;


void test_merge_sort();
void move_hanoi_towers();
template<typename T>
containers::vector<T> square_vector(containers::vector<T>& v);

void test_vector();
void test_array();

template<typename T>
void test_container(container<T>& c);

void test_union();


#endif //WORKBENCH_MAIN_H
