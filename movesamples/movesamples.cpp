//
// Created by egl on 7/12/19.
//

#include "movesamples.h"

using namespace movesamples;

template<typename T>
T&& reidentify_person1(T&& p){
    p.name="Ricardo";
    p.surname="Gomez";
    return std::forward<T>(p);
}

movesamples::person&& reidentify_person2(movesamples::person&& p){
    p.name="Arnold";
    p.surname="Schwarzegger";
    return std::move(p);
}
movesamples::person get_person(){
    person p{"Tony", "Montana"};
    return p; // good practive RVO will be utilized
}

movesamples::person get_person2(){
    person p{"Tony", "Montana"};
    return std::move(p); //bad practice see get_person for correct action
                         //never use std::move on a local variable in returning it will spoil RVO optimization
}



void movesamples::drive_move_samples() {
    person me1{get_person()}; //single construction inside get_person function
                              // compiler does not use copy or move constructor whatsoever RVO optimization in place
    person me2=get_person();  //single construction inside get_person function
                              // compiler does not use copy or move constructor whatsoever RVO optimization in place

    person him1{get_person2()}; //single construction inside get_person function plus move constructor RVO optimization
                                //is spoiled due to std::move scheme employed on return value

    person him2=get_person2();  //single construction inside get_person function plus move constructor RVO optimization
                                //is spoiled due to std::move scheme employed on return value

    person me3{me1}; //copy constructor
    person me4=me1; //copy constructor
    me3=me1; //copy assignment



    person me5{std::move(me1)}; //move constructor
    person me6=std::move(me2);  //move constructor

    me6=std::move(me3); // move assignment


    person me7{reidentify_person1(get_person())}; //single construction inside get_person function
                                                  //move constructor used in constructing me7 after reidentify_person1
                                                  //returns (forward preservers rvalueness of its incoming parameter)

    person me8{reidentify_person1(me6)}; //copy constructor used in construction me8 after reidentify_person1
                                         //returns (forward preserves lvalueness of its incoming parameter)

    person me9{reidentify_person2(get_person())}; //single construction inside get_person function
                                                    //move constructor used in constructing me9 after reidentify_person2
                                                    //returns (move always casts its incoming parameter into a right value reference)
}