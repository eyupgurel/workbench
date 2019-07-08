//
// Created by egl on 7/8/19.
//

#ifndef WORKBENCH_HEAPSORT_H
#define WORKBENCH_HEAPSORT_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
namespace algorithms{
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
    void heapify(int arr[], int n, int i);
    // main function to do heap sort
    void heapSort(int arr[], int n);
    /* A utility function to print array of size n */
    void printArray(int arr[], int n);
    void drive_heap_sort();
}


#endif //WORKBENCH_HEAPSORT_H
