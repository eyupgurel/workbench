//
// Created by egl on 7/15/19.
//

#include "bitsetsamples.h"
using namespace bitsetsamples;

void bitsetsamples::drive_bitset_samples() {

    bitset<10> b1; // all 0
    bitset<16> b2 = 0xaaaa; // 1010101010101010
    bitset<32> b3 = 0xaaaa; // 00000000000000001010101010101010

    bitset<10> b4 {"1010101010"};// 1010101010
    bitset<10> b5 {"10110111011110",4}; // 0111011110

    bitset<10> b6 {string{"1010101010"}};// 1010101010
    bitset<10> b7 {string{"10110111011110"},4};// 0111011110
    bitset<10> b8 {string{"10110111011110"},2,8}; // 0011011101


    //bitset<10> b9 {string{"n0g00d"}};// invalid_argument thrown
    //bitset<10> b10 = string{"101001"}; // error : no implicit string to bitset conversion

    bitset<9> bs {"110001111"};
    std::cout << bs << '\n';    // write "110001111" to cout
    auto bs2 = bs<<3;    // bs2 == "001111000";
    cout << bs2 << '\n';    // write "001111000" to cout
    cin >> bs;    // read from cin
    bs2 = bs>>3;    // bs2 == "000110001" if the inp
    cout << bs2 << '\n';


}