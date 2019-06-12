//
// Created by egl on 6/10/19.
//


#include "metaprogramming.h"

using namespace metaprogramming;

void metaprogramming::f(int x){
    cout << "f(int x) called with x:"  << x << endl;
}

void metaprogramming::f(double y){
    cout << "f(double y) called with y:"  << y << endl;
}

void if_f_callable_with_T_run_function(){
    X<int>xi;
    xi.use_f(3);
    X<double>xd;
    xd.use_f(2.71);

    //X<string> x;
    //x.use_f("test"); //Error no member named 'use_f'

}

void test_fac(){
    constexpr int fac5=fac<5>();
    constexpr int fac6=fac2(6);
    constexpr int fac7 = fac3<7>::value;
}

void test_tuple(){
    tuple<int,double,double> triple{1,0.2,2.71};
    auto e = get<2>(triple);
}

void select_int_type(){
    typename Integer<4>::type i4 = 8; // 4-byte integer
    typename Integer<1>::type i1 = 9; // 1-byte integer
}

void run_simple_samples(){
    if(is_polymorphic<int>::value) cout<<"big surprise!";
    enum class Axis:char{x,y,z};
    enum flags{off,x=1,y=x<<1,z=x<<2,t=x<<3};
    typename underlying_type<Axis>::type t1;
    typename underlying_type<flags>::type t2;

    using Array=Array_type<int,3>;

    Array::type i{4};
    constexpr int s=Array::dim;

}

void smartly_allocated_test(){
    Holder<double> scoped;
    Holder<array<double,200>> heaped;
    *scoped=7.7;
    (*heaped)[22]=23.22;
}

void selecting_function(){
    struct X{ //write X
        void operator()(int x){cout << "X is=" << x << endl; }
    };
    struct Y{ //write Y
        void operator()(int y){cout << "Y is=" << y << endl; }
    };

    Conditional<(sizeof(int)>4),X,Y>{}(7); // make an X or a Y and call it

    using Z = Conditional<(is_polymorphic<X>()),X,Y>;

    Z zz;
    zz(8);
}


void metaprogramming::drive_metaprogramming() {
    if_f_callable_with_T_run_function();
    test_fac();
    test_tuple();
    select_int_type();
    selecting_function();
    smartly_allocated_test();
    run_simple_samples();
    smartly_allocated_test();

}