//
// Created by egl on 2/7/19.
//

#include "mergesort.h"

using namespace std;
using namespace algorithms;
    void merge_sort::sort() const {
        sort(numbers_);
    }

    void merge_sort::sort(numbers_array numbers) const {

        if (numbers.numbers_length > 1) // if length < 2 there is nothing to do this is atomic scale
        {
            //the array ought to be splitted in recursion down to the atomic scale
            auto const pair = split(numbers);
            sort(pair[0]);
            sort(pair[1]);
            //merge here. It is safe to merge here because they are already sorted on previous steps
            merge(pair, numbers);
            //we are done with the pair reclaim resources
            free(pair[0].numbers);
            free(pair[1].numbers);
            free(pair);
        }
    }

    merge_sort::numbers_array *merge_sort::split(const numbers_array arr) const {
        auto const half_size = arr.numbers_length / 2;
        const auto pair = static_cast<numbers_array *> (malloc(2 * sizeof(numbers_array)));

        pair[0].numbers_length = half_size;
        pair[0].numbers = static_cast<int *> (malloc(pair[0].numbers_length * sizeof(int)));
        pair[1].numbers_length = arr.numbers_length - half_size;
        pair[1].numbers = static_cast<int *> (malloc(pair[1].numbers_length * sizeof(int)));

        for (auto i = 0; i < pair[0].numbers_length; i++) {
            pair[0].numbers[i] = arr.numbers[i];
        }
        for (auto i = pair[0].numbers_length; i < arr.numbers_length; i++) {
            pair[1].numbers[i - pair[0].numbers_length] = arr.numbers[i];
        }
        return pair;

    }

    void merge_sort::merge(const numbers_array *pair, const numbers_array into) const {
        auto first_arr_index = 0;
        auto second_arr_index = 0;
        while (first_arr_index + second_arr_index < pair[0].numbers_length + pair[1].numbers_length) {
            if (first_arr_index == pair[0].numbers_length) {
                into.numbers[first_arr_index + second_arr_index] = pair[1].numbers[second_arr_index];
                second_arr_index++;
                continue;
            }

            if (second_arr_index == pair[1].numbers_length) {
                into.numbers[first_arr_index + second_arr_index] = pair[0].numbers[first_arr_index];
                first_arr_index++;
                continue;
            }

            if (pair[0].numbers[first_arr_index] < pair[1].numbers[second_arr_index]) {
                into.numbers[first_arr_index + second_arr_index] = pair[0].numbers[first_arr_index];
                first_arr_index++;
            } else {
                into.numbers[first_arr_index + second_arr_index] = pair[1].numbers[second_arr_index];
                second_arr_index++;
            }
        }
    }


    void merge_sort::print(int *numbers, const int length) const {
        for (auto i = 0; i < length; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }