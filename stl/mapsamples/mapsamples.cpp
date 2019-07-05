//
// Created by egl on 7/6/19.
//


#include "mapsamples.h"
using namespace stl::mapsamples;

size_t hf(const Record& r) { return hash<string>()(r.name)^hash<int>()(r.val);}
bool eq (const Record& r, const Record& r2) { return r.name==r2.name && r.val==r2.val;}

void stl::mapsamples::drive_map_samples() {
    unordered_set<Record,Nocase_hash,Nocase_equal> m1 {
            { {"andy", 7}, {"al",9}, {"bill",-3}, {"barbara",12} }, 500,
            Nocase_hash{2},
            Nocase_equal{}
    };
    for (auto r : m1)
        cout << "{" << r.name << ',' << r.val << "}\n";

    unordered_set<Record,Nocase_hash,Nocase_equal> m2 {
            { {"andy", 7}, {"al",9}, {"bill",-3}, {"barbara",12} }
    };
    for (auto r : m2)
        cout << "{" << r.name << ',' << r.val << "}\n";

    unordered_set<Record,decltype(&hf),decltype(&eq)> m3 {
            { {"andy", 7}, {"al",9}, {"bill",-3}, {"barbara",12} },500,
            hf,
            eq
    };
    for (auto r : m3)
        cout << "{" << r.name << ',' << r.val << "}\n";


    unordered_set<Record, // value type
    function<size_t(const Record&)>,// hash type
    function<bool(const Record&,const Record&)>// equal type
    > m4{  { {"andy", 7}, {"al",9}, {"bill",-3}, {"barbara",12} },500,
          [](const Record& r) { return hash<string>{}(r.name)^hash<int>{}(r.val); },
          [](const Record& r, const Record& r2) { return r.name==r2.name && r.val==r2.val; }
    };
    for (auto r : m4)
        cout << "{" << r.name << ',' << r.val << "}\n";

    auto ahf = [](const Record& r) { return hash<string>()(r.name)^hash<int>()(r.val); };
    auto aeq = [](const Record& r, const Record& r2) { return r.name==r2.name && r.val==r2.val; };
    unordered_set<Record,decltype(ahf),decltype(aeq)> m5{{ {"andy", 7}, {"al",9}, {"bill",-3}, {"barbara",12} },500,ahf,aeq};

    for (auto r : m5)
        cout << "{" << r.name << ',' << r.val << "}\n";

    unordered_set<Record> m6 {
            { {"andy", 7}, {"al",9}, {"bill",-3}, {"barbara",12} }
    };
    for (auto r : m6)
        cout << "{" << r.name << ',' << r.val << "}\n";
}




