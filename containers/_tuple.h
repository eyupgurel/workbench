//
// Created by egl on 6/13/19.
//

#ifndef WORKBENCH__TUPLE_H
#define WORKBENCH__TUPLE_H
#include <iostream>
#include "../metaprogramming/metaprogramming.h"
using namespace std;
using namespace metaprogramming;
namespace containers{

    class Nil{};

    template<typename T1=Nil,typename T2=Nil,typename T3=Nil,typename T4=Nil>
    struct Tuple:Tuple<T2,T3,T4>{
        T1 elem;
        using Base=Tuple<T2,T3,T4>;
        Base* base(){return static_cast<Base*>(this);}
        const Base* base()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1,const T2& t2,const T3& t3,const T4& t4):Base{t2,t3,t4},elem{t1}{}
    };

    template<>
    struct Tuple<>{
        Tuple(){}
    };

    template<typename T1>
    struct Tuple<T1>:Tuple<>{
        T1 elem;
        using Base=Tuple<>;
        Base* base(){return static_cast<Base*>(this);}
        const Base* base()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1):Base{},elem{t1}{}
    };

    template<typename T1,typename T2>
    struct Tuple<T1,T2>:Tuple<T2>{
        T1 elem;
        using Base=Tuple<T2>;
        Base* base(){return static_cast<Base*>(this);}
        const Base* base()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1,const T2& t2):Base{t2},elem{t1}{}
    };

    template<typename T1,typename T2,typename T3>
    struct Tuple<T1,T2,T3>:Tuple<T2,T3>{
        T1 elem;
        using Base=Tuple<T2,T3>;
        Base* base(){return static_cast<Base*>(this);}
        const Base* base()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1,const T2& t2,const T3& t3):Base{t2,t3},elem{t1}{}
    };

    template<typename Ret, int N>
    struct getNth{
        template<typename T>
        static Ret& get(T&t){
            return getNth<Ret,N-1>::get(*t.base());
        }

        template<typename T>
        static const Ret& get(const T&t){
            return getNth<Ret,N-1>::get(*t.base());
        }
    };

    template<typename Ret>
    struct getNth<Ret,0>{
        template<typename T>
        static Ret& get(T&t){
            return t.elem;
        }

        template<typename T>
        static const Ret& get(const T&t){
            return t.elem;
        }
    };

    template<int N, typename T1, typename T2, typename T3, typename T4>
    Select<N, T1, T2, T3, T4>& get(Tuple<T1, T2, T3, T4>& t)
    {
        return getNth<Select<N, T1, T2, T3, T4>,N>::get(t);
    }

    template<int N, typename T1, typename T2, typename T3, typename T4>
    const Select<N, T1, T2, T3, T4>& get(const Tuple<T1, T2, T3, T4>& t)
    {
        return getNth<Select<N, T1, T2, T3, T4>,N>::get(t);
    }


    template<typename T1, typename T2, typename T3, typename T4>
    void print_elements(ostream& os, const Tuple<T1,T2,T3,T4>& t)
    {
        os << t.elem << ", ";
        print_elements(os,*t.base());
    }
    template<typename T1, typename T2, typename T3>
    void print_elements(ostream& os, const Tuple<T1,T2,T3>& t)
    {
        os << t.elem << ", ";
        print_elements(os,*t.base());
    }
    template<typename T1, typename T2>
    void print_elements(ostream& os, const Tuple<T1,T2>& t)
    {
        os << t.elem << ", ";
        print_elements(os,*t.base());
    }
    template<typename T1>
    void print_elements(ostream& os, const Tuple<T1>& t)
    {
        os << t.elem;
        print_elements(os,*t.base());
    }
    template<>
    void print_elements(ostream& os, const Tuple<>& t)
    {
        os << "";
    }

    template<typename T1, typename T2, typename T3, typename T4>
    ostream& operator<<(ostream& os, const Tuple<T1,T2,T3,T4>& t)
    {
        os << "{ ";
        print_elements(os,t);
        os << " }";
        return os;
    }


}
#endif //WORKBENCH__TUPLE_H
