//
// Created by egl on 7/6/19.
//


#include "mapsamples.h"
using namespace stl::mapsamples;

void stl::mapsamples::drive_map_samples() {
    unordered_set<Record,Nocase_hash,Nocase_equal> m {
            { {"andy", 7}, {"al",9}, {"bill",-3}, {"barbara",12} }, 500,
            Nocase_hash{2},
            Nocase_equal{}
    };
    for (auto r : m)
        cout << "{" << r.name << ',' << r.val << "}\n";
}