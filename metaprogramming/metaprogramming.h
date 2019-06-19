//
// Created by egl on 6/10/19.
//

#ifndef WORKBENCH_METAPROGRAMMING_H
#define WORKBENCH_METAPROGRAMMING_H
#include <type_traits>
#include <string>
#include <vector>
#include <array>
#include <tuple>
#include <iostream>


using namespace std;
namespace metaprogramming{

    template<typename T1, typename T2>
    using Common_type = typename common_type<T1,T2>::type;


    template<typename T>
    using Add_const=typename add_const<T>::type;

    template<typename T>
    using Add_lvalue_reference=typename add_lvalue_reference<T>::type;
    template<typename T>
    using Add_rvalue_reference=typename add_rvalue_reference<T>::type;
    template<typename T>
    using Add_const_reference=Add_const<Add_lvalue_reference<T>>;


    template<typename T>
    struct On_Heap{
      On_Heap():p{new T}{}; //allocate
      ~On_Heap(){delete p;} //deallocate

      T& operator*(){return *p;}
      T* operator->(){return p;}

      On_Heap(const On_Heap&)=delete;
      On_Heap& operator=(const On_Heap&)=delete;

    private:
        T* p;
    };

    template<typename T>
    struct Scoped{
        Scoped(){};
        Scoped(T oo):o{oo}{};
        T& operator*(){return o;}
        T* operator->(){return &o;}

        Scoped(const Scoped&)=delete;
        Scoped& operator=(const Scoped&)=delete;
    private:
        T o;
    };

    constexpr int on_stack_max = sizeof(string);
    template<typename T>
    struct Obj_Holder{
        using type=typename conditional<(sizeof(T)<=on_stack_max),Scoped<T>,On_Heap<T>>::type;
    };


    template<typename T>
    using Holder=typename Obj_Holder<T>::type;

    template<typename T, int N>
    struct Array_type{
        using type=T;
        static constexpr int dim=N;
    };



    template<typename T>
    void copy(T* p, const T* q, int n)
    {
    if (is_pod<T>())
        memcpy(p,q,n);
    else
        for (int i=0; i!=n; ++i)
            p[i] = q[i];
    }

    template<bool B, typename T, typename F>
    using Conditional = typename std::conditional<B,T,F>::type;


    class Nil {};
    template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil,
                    typename T5 =Nil, typename T6 =Nil, typename T7 =Nil, typename T8 =Nil,
                    typename T9 =Nil, typename T10 =Nil, typename T11=Nil, typename T12 =Nil>
    struct select;
    template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil,
            typename T5 =Nil, typename T6 =Nil, typename T7 =Nil, typename T8 =Nil,
            typename T9 =Nil, typename T10 =Nil, typename T11=Nil, typename T12 =Nil>
    using Select = typename select<I,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12>::type;
// Specializations for 0-3:
    template<typename T1, typename T2, typename T3, typename T4,
             typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T1; }; // specialize for N==0

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<1,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T2; }; // specialize for N==1

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<2,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T3; }; // specialize for N==2

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<3,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T4; }; // specialize for N==3


    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<4,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T5; }; // specialize for N==4

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<5,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T6; }; // specialize for N==5

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<6,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T7; }; // specialize for N==6

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<7,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T8; }; // specialize for N==7

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<8,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T9; }; // specialize for N==8

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<9,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T10; }; // specialize for N==9

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<10,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T11; }; // specialize for N==10

    template<typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    struct select<11,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> { using type = T12; }; // specialize for N==11

    template<int N>
        struct Integer {
        using Error = void;
        using type = Select<N,Error,signed char,short,Error,int,Error,Error,Error,long>;
    };

    template<int N, typename T1, typename T2, typename T3=Nil, typename T4=Nil,
            typename T5=Nil, typename T6=Nil, typename T7=Nil, typename T8=Nil, typename T9=Nil, typename T10=Nil, typename T11=Nil, typename T12=Nil>
    Select<N,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12> get(tuple<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12>& t);


    template<int N>
    constexpr int fac(){
        return N*fac<N-1>();
    }

    template<>
    constexpr int fac<1>(){
            return 1;
    }

    constexpr int fac2(int i)
    {
        return (i<2)?1:i*fac2(i-1);
    }

    template<int N>
    struct fac3 {
        static constexpr int value = N*fac3<N-1>::value;
    };
    template<>
    struct fac3<1> {
        static constexpr int value = 1;
    };

    template<bool B,typename T=void>
    using Enable_if=typename enable_if<B,T>::type;

    template<typename T>
    constexpr bool Is_class(){
        return is_class<T>::value;
    }

    void f(int x);
    void f(double y);

    struct substitution_failure{};

    template<typename T>
    struct substitution_succeeded: true_type{};

    template<>
    struct substitution_succeeded<substitution_failure>: false_type{};

    template<typename T>
    struct get_f_result{
    private:
        template<typename X>
        static auto check(X const& x)->decltype(f(x));

        static substitution_failure check(...);

    public:
        using type=decltype(check(declval<T>()));
    };

    template<typename T>
    struct has_f
            :substitution_succeeded<typename get_f_result<T>::type>{};


    template<typename T>
    constexpr bool Has_f(){
        return has_f<T>::value;
    }

    template<typename T>
    class X{
    public:
        Enable_if<Has_f<T>()>use_f(const T& t){
            f(t);
        }
    };

    template <typename From, typename To>
    constexpr bool Convertible(){
        return is_convertible<From,To>::value;
    }


    template<typename T, typename U>
    constexpr bool Is_same(){
        return is_same<T,U>::value;
    }




    void drive_metaprogramming();
}


#endif //WORKBENCH_METAPROGRAMMING_H
