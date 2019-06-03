//
// Created by egl on 5/28/19.
//

#ifndef WORKBENCH_CONCEPTS_H
#define WORKBENCH_CONCEPTS_H
#include<type_traits>
using namespace std;
namespace concepts {

    //template<typename T>
    //constexpr bool Equality_comparable(){
    //    return
   // }


    template<typename T>
    constexpr bool Semiregular(){
        return is_destructible<T>()&&
               is_default_constructible<T>()&&
               is_move_constructible<T>()&&
               is_move_assignable<T>()&&
               is_copy_constructible<T>()&&
               is_copy_assignable<T>();
    }

    template<typename T>
    constexpr bool Regular(){
        return Semiregular<T>();// && is_
    }



}


#endif //WORKBENCH_CONCEPTS_H
