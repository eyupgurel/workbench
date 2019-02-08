#include "main.h"

using namespace algorithms;
using namespace containers;
using vector = containers::vector;


int main()
{
    test_vector();
    test_merge_sort();
    move_hanoi_towers();
    return 0;
}

void test_vector(){
    auto v = vector(5);
    v[0] = 1.7;
    v[1] = 3.14;
    v[2] = 2.74;
    v[3] = 2.22;
    v[4] = 0.102;

    {
        auto v2 = vector(3);
        v2[0] = 1.7;
        v2[1] = 3.14;
        v2[2] = 2.74;
    }

    auto v8 = vector({4.32,43.23,67.4,4.22,9.85,23.44,43.23,44.43});

    v8.print();


}

void test_merge_sort(){
    const auto RANDOM_NUMBER_LEN = 300;
    std::vector<int> random_numbers(RANDOM_NUMBER_LEN);
    generate(random_numbers.begin(), random_numbers.end(), []()
    {
        return rand() % 10000;
    });
    merge_sort ms(random_numbers.data(), RANDOM_NUMBER_LEN);
    ms.sort();
}

void move_hanoi_towers(){
    hanoi_towers tower(5);
    tower.move("R1", "D", "R2");
}