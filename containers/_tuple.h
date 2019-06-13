//
// Created by egl on 6/13/19.
//

#ifndef WORKBENCH__TUPLE_H
#define WORKBENCH__TUPLE_H

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

    template<typename T1,typename T2,typename T3>
    struct Tuple<T1,T2,T3>:Tuple<T2,T3>{
        T1 elem;
        using Base=Tuple<T2,T3>;
        Base* base(){return static_cast<Base*>(this);}
        const Base* base()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1,const T2& t2,const T3& t3):Base{t2,t3},elem{t1}{}
    };

    template<typename T1,typename T2>
    struct Tuple<T1,T2>:Tuple<T2>{
        T1 elem;
        using Base=Tuple<T2>;
        Base* base(){return static_cast<Base*>(this);}
        const Base* base()const{return static_cast<const Base*>(this);}
        Tuple(const T1& t1,const T2& t2):Base{t2},elem{t1}{}
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

    void drive_tuple();
}
#endif //WORKBENCH__TUPLE_H
