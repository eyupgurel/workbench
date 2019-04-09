//
// Created by egl on 4/9/19.
//
#ifndef WORKBENCH_SHELLSORT_H
#define WORKBENCH_SHELLSORT_H
#include <cstddef>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
namespace algorithms {
    using CFT = int(const void *, const void*);
    void ssort(void* base, size_t n, size_t sz, CFT cmp);
    void test_shell_sort();
}

#endif //WORKBENCH_SHELLSORT_H
