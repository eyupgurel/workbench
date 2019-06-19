//
// Created by egl on 6/19/19.
//

#include "_valarray.h"
using namespace containers;
void test_print(valarray<int>& v, int rows, int cols, int planes)
{
    for(int r=0; r<rows; ++r) {
        for(int c=0; c<cols; ++c) {
            for(int z=0; z<planes; ++z)
                cout << v[r*cols*planes + c*planes + z] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}

void containers::drive_gslice_sample() {

    valarray<int> v = // 3d array: 2 x 4 x 3 elements
            { 111,112,113 , 121,122,123 , 131,132,133 , 141,142,143,
              211,212,213 , 221,222,223 , 231,232,233 , 241,242,243};
    // int ar3d[2][4][3]
    cout << "Initial 2x4x3 array:\n";
    test_print(v, 2, 4, 3);

    // update every value in the first columns of both planes
    v[gslice(0, {2, 4}, {4*3, 3})] = 1; // two level one strides of 12 elements
    // then four level two strides of 3 elements
    cout << "After column operation 1: \n";
    test_print(v, 2, 4, 3);

    // subtract the third column from the second column in the 1st plane
    v[gslice(1, {1, 4}, {4*3, 3})] -= v[gslice(2, {1, 4}, {4*3, 3})];

    cout << "After column operation 2: \n";
    test_print(v, 2, 4, 3);
}