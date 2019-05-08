//
// Created by egl on 5/6/19.
//

#include "forward.h"
using namespace forward;

void forward::drive() {
    auto p1 = make_unique1<A>(2); // rvalue
    int i = 1;
    auto p2 = make_unique1<A>(i); // lvalue

    std::cout << "B\n";
    string s{"Hello baby kiss me! I will give you my address"};

    auto t = make_unique2<B>(2, i, 3, s, string{"I am beautiful but I have no address"});

    A ar{string{"I'am a right value"}};
    string vs{"I can be varied"};

    const string cs{"I am constant!"};
    A ars{move(vs)};
    A acs{move(cs)}; //here it calls lvalue overload because if move is applied to "const string" type
                     //it will become const string&& and the A(const string& s) constructor will
                     //win over A(string&& s) because  the compiler respects constantness and it should!

    string& rvs{vs};
    A fs{std::forward<string>(vs)}; //will call A(const string&& s) constructor because forward deems vs as a rvalue (actually inside the template, template paremeter T reduces to string)
    A frs{std::forward<string&>(rvs)}; //will call A(const string& s) constructor because forward deems rvs as a lvalue (actually inside the template, template paremeter T reduces to string&)


}