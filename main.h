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
#include "containers/vectorex.h"
#include "containers/container.h"
#include "containers/vector_container.h"
#include "containers/list_container.h"
#include "containers/myarray.h"
#include "containers/simplematrix.h"
#include "containers/_string.h"
#include "union/Entry.h"
#include "assert/assert.h"
#include "chrono/chrono.h"
#include "lifetime/lifetime.h"
#include "forward/forward.h"
#include "forward/Xref.h"
#include "templates/array/array.h"
#include "math/_complex.h"
#include "typeconversion/tiny.h"
#include "operators/operators.h"
#include "functionobject/functionobject.h"
#include "union/unionofclasses.h"
#include "pointer/pointer.h"
#include "cast/cast.h"
#include "typeid/typeid.h"
#include "membertemplates/membertemplates.h"
#include "templates/referencededuction/referencededuction.h"


using namespace algorithms;
using namespace containers;

void drive_safe_vector();
void drive_linear_algebra();
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
