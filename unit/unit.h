//
// Created by egl on 6/15/19.
//

#ifndef WORKBENCH_UNIT_H
#define WORKBENCH_UNIT_H
#include<string>
using namespace std;
namespace unit{
    template<int M,int K,int S>
    struct Unit{
        enum{m=M,kg=K,s=S};
    };

    using M=Unit<1,0,0>;
    using Kg=Unit<0,1,0>;
    using S=Unit<0,0,1>;
    using MpS=Unit<1,0,-1>;
    using MpS2=Unit<1,0,-2>;

    template<typename U1, typename U2>
    struct Uplus{
        using type=Unit<U1::m+U2::m, U1::kg+U2::kg, U1::s+U2::s>;
    };

    template<typename U1,typename U2>
    using Unit_plus=typename Uplus<U1,U2>::type;

    template<typename U1, typename U2>
    struct Uminus{
        using type=Unit<U1::m-U2::m, U1::kg-U2::kg, U1::s-U2::s>;
    };

    template<typename U1,typename U2>
    using Unit_minus=typename Uminus<U1,U2>::type;

    template<typename U>
    struct Quantity{
        long double val;
        constexpr explicit Quantity(long double d):val{d}{}
    };

    template<typename U>
    Quantity<U> operator*(Quantity<U>q, long double s){
        return Quantity<U>{q.val*s};
    }

    template<typename U>
    Quantity<U> operator/(Quantity<U>q, long double s){
        return Quantity<U>{q.val/s};
    }



    template<typename U>
    Quantity<U> operator+(Quantity<U>q1,Quantity<U>q2){
        return Quantity<U>{q1.val+q2.val};
    }

    template<typename U>
    Quantity<U> operator-(Quantity<U>q1,Quantity<U>q2){
        return Quantity<U>{q1.val-q2.val};
    }

    template<typename U1,typename U2>
    Quantity<Unit_plus<U1,U2>> operator*(U1 u1, U2 u2){
        return Quantity<Unit_plus<U1,U2>>{u1.val*u2.val};
    }

    template<typename U1,typename U2>
    Quantity<Unit_minus<U1,U2>> operator/(U1 u1, U2 u2){
        return Quantity<Unit_minus<U1,U2>>{u1.val/u2.val};
    }

    template<typename U>
    auto square(Quantity<U> q){
        return Quantity<Unit_plus<U,U>>{q.val*q.val};
    }

    template<typename U>
    bool operator==(Quantity<U>q1,Quantity<U>q2){
        return q1.val==q2.val;
    }

    template<typename U>
    bool operator!=(Quantity<U>q1,Quantity<U>q2){
        return q1.val!=q2.val;
    }

    constexpr Quantity<M> operator"" _m(long double d){return Quantity<M>(d);}
    constexpr Quantity<Kg> operator"" _kg(long double d){return Quantity<Kg>(d);}
    constexpr Quantity<S> operator"" _s(long double d){return Quantity<S>(d);}
    constexpr Quantity<MpS>operator"" _mps(long double d){return Quantity<MpS>(d);}


    constexpr Quantity<M> operator"" _km(long double d){return Quantity<M>(1000.0*d);} //kilometer
    constexpr Quantity<Kg> operator"" _g(long double d){return Quantity<Kg>(d/1000.0);} //gram
    constexpr Quantity<Kg> operator"" _mg(long double d){return Quantity<Kg>(d/10000000.0);} //milligram
    constexpr Quantity<S> operator"" _ms(long double d){return Quantity<S>(d/1000.0);} //millisecond
    constexpr Quantity<S> operator"" _us(long double d){ return Quantity<S>(d/1000000.0);} //microsecond
    constexpr Quantity<S> operator"" _ns(long double d){ return Quantity<S>(d/1000000000.0);} //nanosecond
}


#endif //WORKBENCH_UNIT_H
