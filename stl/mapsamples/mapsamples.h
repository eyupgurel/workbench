//
// Created by egl on 7/6/19.
//

#ifndef WORKBENCH_MAPSAMPLES_H
#define WORKBENCH_MAPSAMPLES_H

#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
#include <functional>
using namespace std;



namespace stl::mapsamples {
    struct Record {
        string name;
        int val;
    };
    struct Nocase_hash {
        int d = 1; // shift code d number of bits in each iteration
        size_t operator()(const Record& r) const
        {
            size_t h = 0;
            for (auto x : r.name) {
                h <<= d;
                h^= toupper(x);
            }
            return h;
        }
    };

    struct Nocase_equal {
        bool operator()(const Record& r,const Record& r2) const
        {
            if (r.name .size()!=r2.name .size()) return false;
            for (int i = 0; i<r.name .size(); ++i)
                if (toupper(r.name[i])!=toupper(r2.name[i]))
                    return false;
            return true;
        }
    };

    void drive_map_samples();
}

namespace std {
    template<>
    struct hash<stl::mapsamples::Record>{
        size_t operator()(const stl::mapsamples::Record &r) const
        {
            return hash<string>{}(r.name)^hash<int>{}(r.val);
        }
    };
    template<>
    struct equal_to<stl::mapsamples::Record> {
        bool operator()(const stl::mapsamples::Record& r, const stl::mapsamples::Record& r2) const
        {
            return r.name==r2.name && r.val==r2.val;
        }
    };
}

#endif //WORKBENCH_MAPSAMPLES_H
