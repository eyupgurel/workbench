#include "main.h"

//templates<typename T>  //It is not possible to (re)define an operator for a pair of built-in types, such as pointers
//vector<T> operator+(vector<T>* v1, vector<T>* v2){
//}

int main()
{
    dynamicprogramming::drive_knapsack();
    dynamicprogramming::drive_rod_cutting_problem();
    dynamicprogramming::drive_coin_change_ways();
    dynamicprogramming::drive_boolean_parenthesization();
    dynamicprogramming::drive_partition_same_sum();
    dynamicprogramming::drive_egg_problem_solution();
    dynamicprogramming::drive_to_find_shortest_common_superseq_by_back_tracking();
    dynamicprogramming::drive_to_find_longest_common_subsequence();
    dynamicprogramming::drive_to_find_sets_of_numbers();
    dynamicprogramming::drive_to_find_shortest_common_super_seq();
    dynamicprogramming::drive_maximale_dreieck_gesammt();
    auto teilfolgen = dynamicprogramming::berechnen_alle_langste_aufsteigende_teilfolge();
    auto eigenteilfolge=dynamicprogramming::berechnen_langste_aufsteigende_teilfolge();
    auto kannichenzahlen = fibonacci::berechnen_zahlen_der_kannichen();
    weakpointersamples::drive_weakpointersamples();
    drive_type_erasure_boost_custom();
    drive_boost_type_erasure_multi();
    type_erasure::pragmatic::drive_pragmatic_type_erasure();
    type_erasure::basic::drive_basic_type_erasure();
    type_erasure::drive_type_erasure();
    drive_tuple();
    bitsetsamples::drive_bitset_samples();
    movesamples::drive_move_samples();
    lambda::drive_lambda_samples();
    wrappers::drive_reference_wrapper();
    functional::bind::drive_bind_samples();

    algorithms::drive_heap_sort();
    stl::mapsamples::drive_map_samples();
    stl::vectorsamples::reading_letters_into_buff_keeping_track_of_word_boundaries();
    stl::sort::drive_stl_sort();
    drive_slab_matrix();
    drive_matrix();
    containers::drive_gslice_sample();
    drive_si_unit();

    metaprogramming::drive_metaprogramming();
    metaprogramming::drive_declval();
    polymorphism::tripledispatch::drive_tripledispatch();
    polymorphism::drive_doubledispatch();

    polymorphism::drive_visitor();
    templates::drive_template_conversions();
    drive_namebinding();
    templates::drive_var();
    templates::drive_specializaton_cases();
    templates::drive_template_algorithms();
    templates::drive_Xref();
    membertemplates::drive_membertemplates();
    typeid_::drive_typeid();
    cast::drive_cast();
    pointer::derive_pointer();
    drive_safe_vector();
    drive_linear_algebra();

    unions::drive_union_of_classes();
    functionobject::drive_function_object();
    operators::drive_assoc();
    typeconversion::drive_tiny();
    math::drive_complex();
    templates::test_template_array();
    forward::drive();
    forward::driveXref();

    containers::drive_vectorex();
    containers::drive_simple_matrix();

    lifetime::drive();
    //Assert::run_test();

    chrono::Date d{2,chrono::Month::feb,1980};
    auto dc{d};
    auto da = d;


    test_shell_sort();


    test_union();
    test_array();

    {
        vector_container<double> v8con{4.32, 43.23, 67.4, 4.22, 9.85, 23.44, 43.23, 44.43};
        test_container(v8con);

        list_container<double> l8con{5.342, 33.23, 7.4, 0.22, 9.85, 3.44, 6.23, 9.43};
        test_container(l8con);
    }


    test_vector();
    test_merge_sort();
    move_hanoi_towers();
    containers::drive_string();
    return 0;
}


void test_union(){
    unions::Entry et{string{"love"}};
    string ets{et.text()};
    unions::Entry en{2};
    int n = en.number();

    et = en;

    unions::Entry et2{string{"me tender"}};
    en = et2;

    string et2s{et2.text()};



}


void test_array(){
    using Array = myarray<Point,3>;
    Array points{{{1,2},{2,3},{4,5}}};
    //int i = points[0].x;

}

template<typename T>
void test_container(container<T>& c){
    const int sz = c.size();
    for(auto i = 0; i < sz; i++){
        std::cout << c[i] << std::endl;
    }
}
template<typename T>
containers::vector<T> square_vector(containers::vector<T>& v){
    auto sv = containers::vector<T>(v.size());
    for(auto i = 0; i < v.size(); i++){
        sv[i] = v[i] * v[i];
    }
    return sv;
}


void test_vector(){

    auto v = containers::vector<double>(5);
    v[0] = 1.7;
    v[1] = 3.14;
    v[2] = 2.74;
    v[3] = 2.22;
    v[4] = 0.102;

    {
        auto v2 = containers::vector<double>(3);
        v2[0] = 1.7;
        v2[1] = 3.14;
        v2[2] = 2.74;
    }

    auto v8 = containers::vector<double>({4.32,43.23,67.4,4.22,9.85,23.44,43.23,44.43});

    v8.print();

    auto v8_copy(v8);

    v8_copy.print();

    containers::vector<double> v8_new;
    v8_new.print();

    containers::vector<double> v9_new = v8_new = square_vector(v8);

    v9_new.print();

    containers::vector<double> v12 = square_vector(v8);



    //auto v10_new = std::move(v9_new);



    containers::vector<double> v5 = {4.32,43.23,67.4,4.22,9.85};




    containers::vector<double> v6{4.3200000000000000,43.23,67.4,4.22,9.85, 1.1};




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
