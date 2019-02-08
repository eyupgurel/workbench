//
// Created by egl on 2/7/19.
//

#ifndef WORKBENCH_HANOITOWER_H
#define WORKBENCH_HANOITOWER_H
// TODO: Reference additional headers your program requires here.
#include <iostream>
#include <vector>
#include <string>
namespace algorithms{

    class hanoi_towers
    {
    private:
        void move(const char * r1, const char * d, const char * r2, std::vector<int>tower) const;
    public:
        explicit hanoi_towers(const int height);
        std::vector<int> tower;
        void move(const char *r1, const char * d, const char * r2) const;

    };

}
#endif //WORKBENCH_HANOITOWER_H
