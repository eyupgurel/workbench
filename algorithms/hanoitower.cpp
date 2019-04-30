//
// Created by egl on 2/7/19.
//

#include "hanoitower.h"
using namespace std;

using namespace algorithms;
    hanoi_towers::hanoi_towers(const int height)
    {
        for (auto i = 1; i <= height; i++)
        {
            tower.push_back(i);
        }
    }
    /*
        R1  D  R2
        R1-D [5] => R1-R2 [4] + R1-D 5 + R2-D [4]
        R1-R2 [4] => R1-D [3] + R1-R2 4 + D-R2 [3]
        R1-D [3] => R1-R2 [2] + R1-D 3
    */
    void hanoi_towers::move(const char* r1, const char* d, const char* r2, std::vector<int> tower) const
    {
        if (tower.size() > 1) {
            const vector<int> tower_less_base(tower.begin(), tower.begin() + tower.size() - 1);
            move(r1, r2, d, tower_less_base);
        }
        cout << "Item number " + std::to_string(tower.back()) + " moved from " + r1 + " onto " + d << endl;
        if (tower.size() > 1) {
            const vector<int> tower_less_base(tower.begin(), tower.begin() + tower.size() - 1);
            move(r2, d, r1, tower_less_base);
        }
    }

    void hanoi_towers::move(const char *r1, const char* d, const char* r2) const
    {
        move(r1, d, r2, tower);
    }
