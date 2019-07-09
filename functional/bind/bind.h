//
// Created by egl on 7/9/19.
//

#ifndef WORKBENCH_BIND_H
#define WORKBENCH_BIND_H

#include <random>
#include <iostream>
#include <memory>
#include <functional>

namespace functional::bind {

    void f(int n1, int n2, int n3, const int& n4, int n5);
    int g(int n1);

    struct Foo {
        void print_sum(int n1, int n2)
        {
            std::cout << n1+n2 << '\n';
        }
        int data = 10;
    };

    void drive_bind_samples();
}


#endif //WORKBENCH_BIND_H
