//
// Created by egl on 5/11/19.
//

#ifndef WORKBENCH_ARRAY_H
#define WORKBENCH_ARRAY_H

#include <cstddef>
using namespace std;
namespace templates {
    template<typename T, size_t N>
    constexpr size_t array_size(T(&)[N]) { return N; };

    void test_template_array();
}

#endif //WORKBENCH_ARRAY_H
