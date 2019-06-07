//
// Created by egl on 6/7/19.
//

#include "visitor.h"
using namespace polymorphism;

void Expr::accept(polymorphism::Visitor &v) {v.accept(*this);}
void Stmt::accept(polymorphism::Visitor &v) {v.accept(*this);}

void test(Expr& e, Stmt& s){
    Do1_visitor do1;
    Do2_visitor do2;
    vector<pair<Node*,Visitor*>> vn {{&e,&do1},{&s,&do1}, {&e,&do2}, {&s,&do2}};
    for (auto p : vn)
        p.first->accept(*p.second);
}

void polymorphism::drive_visitor(){
    Expr e;
    Stmt s;
    test(e,s);
}

