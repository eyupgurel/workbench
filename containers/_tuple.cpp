//
// Created by egl on 6/13/19.
//

#include "_tuple.h"
using namespace containers;

void drive_tuple() {
    Tuple<double , int, char> x {1.1, 42, 'a'};
    cout << x << "\n";
    cout << Tuple<double ,int,int,int>{1.2,3,5,7} << "\n";
    cout << Tuple<double ,int,int>{1.2,3,5} << "\n";
    cout << Tuple<double ,int>{1.2,3} << "\n";
    cout << Tuple<double>{1.2} << "\n";
    cout << Tuple<>{} << "\n";

}