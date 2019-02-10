#include "main.h"

int main()
{
    {
        vector_container<double> v8con{4.32, 43.23, 67.4, 4.22, 9.85, 23.44, 43.23, 44.43};
        test_container(v8con);

        list_container<double> l8con{5.342, 33.23, 7.4, 0.22, 9.85, 3.44, 6.23, 9.43};
        test_container(l8con);
    }


    test_vector();
    test_merge_sort();
    move_hanoi_towers();
    return 0;
}
template<typename T>
void test_container(container<T>& c){
    const int sz = c.size();
    for(auto i = 0; i < sz; i++){
        std::cout << c[i] << std::endl;
    }
}
template<typename T>
my_vector<T> square_vector(my_vector<T>& v){
    auto sv = my_vector<T>(v.size());
    for(auto i = 0; i < v.size(); i++){
        sv[i] = v[i] * v[i];
    }
    return sv;
}


void test_vector(){

    auto v = my_vector<double>(5);
    v[0] = 1.7;
    v[1] = 3.14;
    v[2] = 2.74;
    v[3] = 2.22;
    v[4] = 0.102;

    {
        auto v2 = my_vector<double>(3);
        v2[0] = 1.7;
        v2[1] = 3.14;
        v2[2] = 2.74;
    }

    auto v8 = my_vector<double>({4.32,43.23,67.4,4.22,9.85,23.44,43.23,44.43});

    v8.print();

    auto v8_copy(v8);

    v8_copy.print();

    my_vector<double> v8_new;
    v8_new.print();

    my_vector<double> v9_new = v8_new = square_vector(v8);

    v9_new.print();

    my_vector<double> v12 = square_vector(v8);



    //auto v10_new = std::move(v9_new);



    my_vector<double> v5 = {4.32,43.23,67.4,4.22,9.85};




    my_vector<double> v6{4.3200000000000000,43.23,67.4,4.22,9.85, 1.1};




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