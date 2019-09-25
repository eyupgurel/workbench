//
// Created by egl on 2/7/19.
//

#ifndef WORKBENCH_MAIN_H
#define WORKBENCH_MAIN_H

#include "common.h"
#include "algorithms/mergesort.h"
#include "algorithms/hanoitower.h"
#include "algorithms/shellsort.h"
#include "algorithms/heapsort.h"
#include "containers/vector.h"
#include "containers/vectorex.h"
#include "containers/container.h"
#include "containers/vector_container.h"
#include "containers/list_container.h"
#include "containers/myarray.h"
#include "containers/simplematrix.h"
#include "containers/_string.h"
#include "containers/_valarray.h"
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
#include "templates/algorithms/algorithms.h"
#include "templates/specialization/specialization.h"
#include "templates/typererasure/typeerasure.h"
#include "templates/conversions/conversions.h"
#include "polymorphism/doubledispatch/doubledispatch.h"
#include "polymorphism/tripledispatch/tripledispatch.h"
#include "polymorphism/visitor/visitor.h"
#include "metaprogramming/metaprogramming.h"
#include "metaprogramming/declval.h"
#include "stl/sort/sort.h"
#include "stl/vectorsamples/vectorsamples.h"
#include "stl/mapsamples/mapsamples.h"
#include "stl/bitsetsamples/bitsetsamples.h"
#include "functional/bind/bind.h"
#include "wrappers/reference_wrapper_.h"
#include "lambda/lambda.h"
#include "movesamples/movesamples.h"
#include "type_erasure/type_erasure.h"
#include "type_erasure/basic/basic_type_erasure.h"
#include "type_erasure/pragmatic/pragmatic_type_erasure.h"
#include "memory/weakptr/weakpointersamples.h"
#include "fibonacci/fibonacci.h"
#include "dynamicprogramming/langsteaufsteigendeteilfolge.h"
#include "dynamicprogramming/zahlendreieck.h"
#include "dynamicprogramming/shortestcommonsuperseq.h"
#include "dynamicprogramming/setsofnumbersthataddup.h"

using namespace algorithms;
using namespace containers;
void drive_slab_matrix();
void drive_matrix();
void drive_namebinding();
void drive_safe_vector();
void drive_linear_algebra();
void test_merge_sort();
void move_hanoi_towers();
void drive_tuple();
void drive_si_unit();

void drive_boost_type_erasure_multi();
void drive_type_erasure_boost_custom();

template<typename T>
containers::vector<T> square_vector(containers::vector<T>& v);

void test_vector();
void test_array();

template<typename T>
void test_container(container<T>& c);

void test_union();


#endif //WORKBENCH_MAIN_H
