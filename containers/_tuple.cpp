//
// Created by egl on 6/13/19.
//

#include "_tuple.h"
using namespace containers;

void drive_tuple() {

    Tuple<double , int, char> t1 {1.1, 42, 'a'};
    cout << t1 << "\n";
    cout << Tuple<double ,int,int,int>{1.2,3,5,7} << "\n";
    cout << Tuple<double ,int,int>{1.2,3,5} << "\n";
    cout << Tuple<double ,int>{1.2,3} << "\n";
    cout << Tuple<double>{1.2} << "\n";
    cout << Tuple<>{} << "\n";


    auto xxx = Tuple{1.2,3,'x',1223};



    cout << "{ " // write { 1.1, 42, a }
         << get<0>(t1) << ", "
         << get<1>(t1) << ", "
         << get<2>(t1) << " }\n";

    auto xx = get<0>(t1); // xx is a double

    get<2>(t1)='b';

    cout << t1 << "\n";

    const Tuple<double , int, char> t2 {1.1, 42, 'a'};
    //get<2>(t2) = 'b';// error : t2 is const
    char cc = get<2>(t2);


}