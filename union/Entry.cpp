//
// Created by egl on 3/9/19.
//

#include "Entry.h"
namespace unions{

    int Entry::number() const {
        if(type!=Tag::number) throw Bad_entry();
        return i;
    }

    string Entry::text() const {
        if(type!= Tag::text) throw Bad_entry();
        return s;
    }

    void Entry::set_number(const int n) {
        if(type == Tag::text){
            s.~string();
        }
        type = Tag::number;
        i = n;
    }

    void Entry::set_text(const string &str) {
        if(type == Tag::text){
            s = str;
        } else {
            new (&s) string{str};
            type = Tag::text;
        }
    }

    Entry& Entry::operator=(const Entry& entry) {
        if(type == Tag::text && entry.type == Tag::text){
            s = entry.s;
            return *this;
        }

        if(type == Tag::text) s.~string();

        switch(entry.type){
            case Tag::number:
                i = entry.i;
                break;
            case Tag::text:
                new(&s)string{entry.s};
                type = entry.type;
        }
        type = entry.type;
        return *this;
    }

    Entry::~Entry() {
        if(type == Tag::text)s.~string();
    }

    Entry::Entry(const Entry& entry){
        this->operator=(entry);
    }


    Entry::Entry(string t) {
        set_text(t);
    }

    Entry::Entry(int i) {
        set_number(i);
    }

}