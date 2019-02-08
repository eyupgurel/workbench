//
// Created by egl on 2/7/19.
//

#ifndef WORKBENCH_MERGESORT_H
#define WORKBENCH_MERGESORT_H
// TODO: Reference additional headers your program requires here.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace algorithms {
    class merge_sort {
    private:
        struct numbers_array {
            int *numbers;
            int numbers_length;
        };
        numbers_array numbers_;
    public:
        explicit merge_sort(int *numbers, const int length) {
            numbers_.numbers = numbers;
            numbers_.numbers_length = length;
        }

        void sort() const;

        void print(int *numbers, int length) const;

    private:
        void sort(numbers_array numbers) const;

        numbers_array *split(const numbers_array arr) const;

        void merge(const numbers_array *pair, const numbers_array into) const;


    };

}
#endif //WORKBENCH_MERGESORT_H
