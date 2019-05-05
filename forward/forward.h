//
// Created by egl on 5/6/19.
//

#ifndef WORKBENCH_FORWARD_H
#define WORKBENCH_FORWARD_H
#include <utility>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

namespace forward{

    struct A {
        A(int&& n) { std::cout << "rvalue overload, n=" << n << "\n"; }
        A(int& n)  { std::cout << "lvalue overload, n=" << n << "\n"; }
        A(string&& s) { std::cout << "rvalue overload, s=" << s  << "\n"; }
        A(string& s)  { std::cout << "lvalue overload, s=" << s << "\n"; }
    };

    class B {
    public:
        template<class T1, class T2, class T3, class T4, class T5>
        B(T1&& t1, T2&& t2, T3&& t3, T4&& t4, T5&& t5) :
                a1_{std::forward<T1>(t1)},
                a2_{std::forward<T2>(t2)},
                a3_{std::forward<T3>(t3)},
                a4_{std::forward<T4>(t4)},
                a5_{std::forward<T5>(t5)}
        {
        }

    private:
        A a1_, a2_, a3_,a4_,a5_;
    };

    template<class T, class U>
    std::unique_ptr<T> make_unique1(U&& u)
    {
        return std::unique_ptr<T>(new T(std::forward<U>(u)));
    }

    template<class T, class... U>
    std::unique_ptr<T> make_unique2(U&&... u)
    {
        return std::unique_ptr<T>(new T(std::forward<U>(u)...));
    }

    void drive();

}


#endif //WORKBENCH_FORWARD_H
