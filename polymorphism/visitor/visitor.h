//
// Created by egl on 6/7/19.
//

#ifndef WORKBENCH_VISITOR_H
#define WORKBENCH_VISITOR_H
#include <iostream>
#include <vector>
using namespace std;
namespace polymorphism{

    class Visitor;

    class Node{
    public:
        virtual void accept(Visitor&)=0;
    };

    class Expr: public Node{
    public:
        void accept(Visitor&) override;
    };

    class Stmt: public Node{
    public:
        void accept(Visitor&) override;
    };

    class Visitor{
    public:
        virtual void accept(Expr&)=0;
        virtual void accept(Stmt&)=0;
    };

    class Do1_visitor : public Visitor {
        void accept(Expr&)override { cout << "do1 to Expr\n"; }
        void accept(Stmt&)override { cout << "do1 to Stmt\n"; }
    };
    class Do2_visitor : public Visitor {
        void accept(Expr&)override { cout << "do2 to Expr\n"; }
        void accept(Stmt&)override { cout << "do2 to Stmt\n"; }
    };

    void drive_visitor();
}



#endif //WORKBENCH_VISITOR_H
