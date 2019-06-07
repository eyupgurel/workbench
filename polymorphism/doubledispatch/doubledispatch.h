//
// Created by egl on 6/7/19.
//

#ifndef WORKBENCH_DOUBLEDISPATCH_H
#define WORKBENCH_DOUBLEDISPATCH_H
#include <iostream>
#include <vector>
using namespace std;
namespace polymorphism{
    class Circle;
    class Triangle;
    class Shape{
    public:
        virtual bool intersect(const Shape&) const = 0;
        virtual bool intersect(const Circle&) const = 0;
        virtual bool intersect(const Triangle&) const = 0;
    };

    class Circle: public Shape{
        public:
        bool intersect(const Shape& s) const override{return s.intersect(*this);};
        bool intersect(const Circle& c) const override{cout <<"intersect(circle,circle)\n"; return true; };
        bool intersect(const Triangle&) const override{cout <<"intersect(circle,triangle)\n"; return true;};
    };

    class Triangle: public Shape{
    public:
        bool intersect(const Shape& s) const override{return s.intersect(*this);};
        bool intersect(const Circle& c) const override{cout <<"intersect(triangle,circle)\n"; return true; };
        bool intersect(const Triangle&) const override{cout <<"intersect(triangle,triangle)\n"; return true;};
    };

    void drive_doubledispatch();

}


#endif //WORKBENCH_DOUBLEDISPATCH_H
