//
// Created by egl on 6/7/19.
//

#ifndef WORKBENCH_TRIPLEDISPATCH_H
#define WORKBENCH_TRIPLEDISPATCH_H

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
namespace polymorphism{
    namespace tripledispatch {
        class Circle;

        class Triangle;

        class Rectangle;

        class Shape {
        public:
            virtual bool intersect(const Shape &, const Shape &) const = 0;
            virtual bool intersect(const Circle &, const Shape &) const = 0;
            virtual bool intersect(const Triangle &, const Shape &) const = 0;
            virtual bool intersect(const Rectangle &, const Shape &) const = 0;

            virtual bool intersect(const Circle &, const Circle &) const = 0;

            virtual bool intersect(const Circle &, const Triangle &) const = 0;

            virtual bool intersect(const Circle &, const Rectangle &) const = 0;

            virtual bool intersect(const Triangle &, const Triangle &) const = 0;

            virtual bool intersect(const Triangle &, const Circle &) const = 0;

            virtual bool intersect(const Triangle &, const Rectangle &) const = 0;


            virtual bool intersect(const Rectangle &, const Rectangle &) const = 0;

            virtual bool intersect(const Rectangle &, const Circle &) const = 0;

            virtual bool intersect(const Rectangle &, const Triangle &) const = 0;

        };

        class Circle : public Shape {
        public:
            bool intersect(const Shape &s1, const Shape &s2) const override {
                return s1.intersect(*this, s2);
            };

            bool intersect(const Circle &c, const Shape &s) const override {
                return s.intersect(*this, c);
            };

            bool intersect(const Triangle &t, const Shape &s) const override {
                return s.intersect(*this, t);
            };

            bool intersect(const Rectangle &r, const Shape &s) const override {
                return s.intersect(*this, r);
            };



            bool intersect(const Circle &c1, const Circle &c2) const override {
                cout << "intersect(circle,circle,circle)\n";
                return true;
            };

            bool intersect(const Circle &c1, const Triangle &c2) const override {
                cout << "intersect(circle,circle,triangle)\n";
                return true;
            };

            bool intersect(const Circle &c1, const Rectangle &c2) const override {
                cout << "intersect(circle,circle,rectangle)\n";
                return true;
            };

            bool intersect(const Triangle &c1, const Triangle &c2) const override {
                cout << "intersect(circle,triangle,triangle)\n";
                return true;
            };

            bool intersect(const Triangle &c1, const Circle &c2) const override {
                cout << "intersect(circle,triangle,circle)\n";
                return true;
            };

            bool intersect(const Triangle &c1, const Rectangle &c2) const override {
                cout << "intersect(circle,triangle,rectangle)\n";
                return true;
            };

            bool intersect(const Rectangle &c1, const Rectangle &c2) const override {
                cout << "intersect(circle,rectangle,rectangle)\n";
                return true;
            };

            bool intersect(const Rectangle &c1, const Circle &c2) const override {
                cout << "intersect(circle,rectangle,circle)\n";
                return true;
            };

            bool intersect(const Rectangle &c1, const Triangle &c2) const override {
                cout << "intersect(circle,Rectangle,triangle)\n";
                return true;
            };
        };

        class Triangle : public Shape {
        public:
            bool intersect(const Shape &s1, const Shape &s2) const override {
                return s1.intersect(*this, s2);
            };

            bool intersect(const Circle &c, const Shape &s) const override {
                return s.intersect(*this, c);
            };

            bool intersect(const Triangle &t, const Shape &s) const override {
                return s.intersect(*this, t);
            };

            bool intersect(const Rectangle &r, const Shape &s) const override {
                return s.intersect(*this, r);
            };


            bool intersect(const Circle &c1, const Circle &c2) const override {
                cout << "intersect(triangle,circle,circle)\n";
                return true;
            };


            bool intersect(const Circle &c1, const Triangle &c2) const override {
                cout << "intersect(triangle,circle,triangle)\n";
                return true;
            };

            bool intersect(const Circle &c1, const Rectangle &c2) const override {
                cout << "intersect(triangle,circle,rectangle)\n";
                return true;
            };

            bool intersect(const Triangle &c1, const Triangle &c2) const override {
                cout << "intersect(triangle,triangle,triangle)\n";
                return true;
            };

            bool intersect(const Triangle &c1, const Circle &c2) const override {
                cout << "intersect(triangle,triangle,circle)\n";
                return true;
            };

            bool intersect(const Triangle &c1, const Rectangle &c2) const override {
                cout << "intersect(triangle,triangle,rectangle)\n";
                return true;
            };

            bool intersect(const Rectangle &c1, const Rectangle &c2) const override {
                cout << "intersect(triangle,rectangle,rectangle)\n";
                return true;
            };

            bool intersect(const Rectangle &c1, const Circle &c2) const override {
                cout << "intersect(triangle,rectangle,circle)\n";
                return true;
            };

            bool intersect(const Rectangle &c1, const Triangle &c2) const override {
                cout << "intersect(triangle,Rectangle,triangle)\n";
                return true;
            };
        };

        class Rectangle : public Shape {
        public:
            bool intersect(const Shape &s1, const Shape &s2) const override {
                return s1.intersect(*this, s2);
            };

            bool intersect(const Circle &c, const Shape &s) const override {
                return s.intersect(*this, c);
            };

            bool intersect(const Triangle &t, const Shape &s) const override {
                return s.intersect(*this, t);
            };

            bool intersect(const Rectangle &r, const Shape &s) const override {
                return s.intersect(*this, r);
            };

            bool intersect(const Circle &c1, const Circle &c2) const override {
                cout << "intersect(rectangle,circle,circle)\n";
                return true;
            };

            bool intersect(const Circle &c1, const Triangle &c2) const override {
                cout << "intersect(rectangle,circle,triangle)\n";
                return true;
            };

            bool intersect(const Circle &c1, const Rectangle &c2) const override {
                cout << "intersect(rectangle,circle,rectangle)\n";
                return true;
            };

            bool intersect(const Triangle &c1, const Triangle &c2) const override {
                cout << "intersect(rectangle,triangle,triangle)\n";
                return true;
            };

            bool intersect(const Triangle &c1, const Circle &c2) const override {
                cout << "intersect(rectangle,triangle,circle)\n";
                return true;
            };

            bool intersect(const Triangle &c1, const Rectangle &c2) const override {
                cout << "intersect(rectangle,triangle,rectangle)\n";
                return true;
            };

            bool intersect(const Rectangle &c1, const Rectangle &c2) const override {
                cout << "intersect(rectangle,rectangle,rectangle)\n";
                return true;
            };

            bool intersect(const Rectangle &c1, const Circle &c2) const override {
                cout << "intersect(rectangle,rectangle,circle)\n";
                return true;
            };

            bool intersect(const Rectangle &c1, const Triangle &c2) const override {
                cout << "intersect(rectangle,Rectangle,triangle)\n";
                return true;
            };
        };


        void drive_tripledispatch();
    }
}


#endif //WORKBENCH_TRIPLEDISPATCH_H
