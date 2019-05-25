//
// Created by egl on 5/23/19.
//

#include "typeid.h"
using namespace typeid_;

void f(Non_poly& npr, Poly& pr)
{
    try{
        cout << typeid(npr).name() << '\n'; // writes something like "Non_poly"
        cout << typeid(pr).name() << '\n';// name of Poly or a class derived from Poly
    } catch(...){
        cout<< "bad typeid";
    }

}

void g()
{
    D1 d1;
    D2 d2;
    f(d2,d1); // writes "Non_poly D1"
    //f(*static_cast<Non_poly*>(nullptr),*static_cast<Poly*>(nullptr)); // oops!
}

void typeid_::drive_typeid() {
    g();
    int myint = 50;
    std::string mystr = "string";
    double *mydoubleptr = nullptr;

    std::cout << "myint has type: " << typeid(myint).name() << '\n'
              << "mystr has type: " << typeid(mystr).name() << '\n'
              << "mydoubleptr has type: " << typeid(mydoubleptr).name() << '\n';

    // std::cout << myint is a glvalue expression of polymorphic type; it is evaluated
    const std::type_info& r1 = typeid(std::cout << myint);
    std::cout << '\n' << "std::cout<<myint has type : " << r1.name() << '\n';

    // std::printf() is not a glvalue expression of polymorphic type; NOT evaluated
    const std::type_info& r2 = typeid(std::printf("%d\n", myint));
    std::cout << "printf(\"%d\\n\",myint) has type : " << r2.name() << '\n';

    // Non-polymorphic lvalue is a static type
    Derived d1;
    Base& b1 = d1;
    std::cout << "reference to non-polymorphic base: " << typeid(b1).name() << '\n';

    Derived2 d2;
    Base2& b2 = d2;
    std::cout << "reference to polymorphic base: " << typeid(b2).name() << '\n';

    try {
        // dereferencing a null pointer: okay for a non-polymorphic expression
        std::cout << "mydoubleptr points to " << typeid(*mydoubleptr).name() << '\n';
        // dereferencing a null pointer: not okay for a polymorphic lvalue
        Derived2* bad_ptr = nullptr;
        std::cout << "bad_ptr points to... ";
        std::cout << typeid(*bad_ptr).name() << '\n';
    } catch (const std::bad_typeid& e) {
        std::cout << " caught " << e.what() << '\n';
    }
}