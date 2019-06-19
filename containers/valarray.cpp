//
// Created by egl on 6/19/19.
//

#include "valarray.h"

void test_print(std::valarray<int>& v, int rows, int cols, int planes)
{
    for(int r=0; r<rows; ++r) {
        for(int c=0; c<cols; ++c) {
            for(int z=0; z<planes; ++z)
                std::cout << v[r*cols*planes + c*planes + z] << ' ';
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}

void containers::drive_gslice_sample() {

    std::valarray<int> v = // 3d array: 2 x 4 x 3 elements
            { 111,112,113 , 121,122,123 , 131,132,133 , 141,142,143,
              211,212,213 , 221,222,223 , 231,232,233 , 241,242,243};
    // int ar3d[2][4][3]
    std::cout << "Initial 2x4x3 array:\n";
    test_print(v, 2, 4, 3);

    // update every value in the first columns of both planes
    v[std::gslice(0, {1, 4}, {4*3, 3})] = 1; // two level one strides of 12 elements
    // then four level two strides of 3 elements
    std::cout << "After column operation 1: \n";
    test_print(v, 2, 4, 3);

    // subtract the third column from the second column in the 1st plane
    v[std::gslice(1, {1, 4}, {4*3, 3})] -= v[std::gslice(2, {2, 4}, {4*3, 3})];

    std::cout << "After column operation 2: \n";
    test_print(v, 2, 4, 3);
}