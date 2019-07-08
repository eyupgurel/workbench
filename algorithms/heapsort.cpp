//
// Created by egl on 7/8/19.
//

#include "heapsort.h"
using namespace algorithms;

void algorithms::heapify(int *arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void algorithms::heapSort(int *arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void algorithms::printArray(int *arr, int n) {
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void algorithms::drive_heap_sort() {

    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);

    //stl samples
    string s = "herewego";
    make_heap(s.begin(),s.end()); //worheege
    pop_heap(s.begin(),s.end()); // rogheeew
    pop_heap(s.begin(),s.end()-1);// ohgeeerw
    pop_heap(s.begin(),s.end()-2);// hegeeorw
    *(s.end()-3)='f';
    push_heap(s.begin(),s.end()-2);// hegeefrw
    *(s.end()-2)='x';
    push_heap(s.begin(),s.end()-1);// xeheefge
    *(s.end()-1)='y';
    push_heap(s.begin(),s.end());// yxheefge
    sort_heap(s.begin(),s.end());// eeefghxy
    reverse(s.begin(),s.end());// yxhgfeee

}