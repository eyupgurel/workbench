/*******************************************************************************
 * EXPECTED OUTPUT:
 *******************************************************************************

m1 = {{2,4,6},{8,10,12}}
m2 = {{1,2,3},{4,5,6}}
m3 = {{3,6,9},{12,15,18}}
m4 = {{1,2},{3,4},{5,6}}
m5 = {{44,56},{98,128}}

 ******************************************************************************/
/*
#include <iostream>
using namespace std;
#include "../blas/gemv.h"
#include "../matrix.h"
#include "../matrix_ops.h"


using namespace slab;

void drive_matrix_arithmetric_operations() {
    Matrix<int, 2> m1{{1, 2, 3}, {4, 5, 6}};    // 2-by-3
    Matrix<int, 2> m2{m1};                      // copy
    m1 *= 2;                                    // scale: {{2,4,6},{8,10,12}}
    Matrix<int, 2> m3 = m1 + m2;                // add: {{3,6,9},{12,15,18}}
    Matrix<int, 2> m4{{1, 2}, {3, 4}, {5, 6}};  // 3-by-2
    //Matrix<int, 2> m5 = matmul(m1, m4);         // multiply: {{44,56}, {98,128}}

   // cout << "\nm1 = " << m1 << "\nm2 = " << m2 << "\nm3 = " << m3
     //    << "\nm4 = " << m4 << "\nm5 = " << m5 << endl;
}

*/