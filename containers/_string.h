//
// Created by egl on 5/15/19.
//

#ifndef WORKBENCH__STRING_H
#define WORKBENCH__STRING_H
#include <stdexcept>
#include <cstring>
#include <iostream>

using namespace std;
namespace containers{
    class _string {

    public:
        _string();
        _string(const char * p);
        template<size_t N>
        _string(const char(&p)[N]);
        _string(const _string&);
        _string& operator=(const _string&);
        _string(_string&&)noexcept;
        _string& operator=(_string &&)noexcept;
        ~_string(){if(sz>short_max) delete[] ptr;};

        char& operator[](int n){return ptr[n];}
        char operator[](int n)const{return ptr[n];}
        char& at(int n){check(n); return ptr[n];}
        char at(int n)const{check(n); return ptr[n];}

        _string& operator+=(char c);
        char* c_str(){return ptr;}
        const char* c_str()const{return ptr;}

        int size()const{ return sz;}
        int capacity()const{return sz<=short_max ? short_max : sz+space;}


    private:
        static constexpr int short_max{15};
        void check(int n)const {if(n<0||n>=sz)throw range_error("bad range");}
        void copy_from(const _string& s);
        void move_from(_string& s);
        size_t sz;
        union{
            int space;
            char ch[short_max+1];
        };
        char * ptr;
    };
    char * expand(const char* ptr, int n);
    ostream& operator<<(ostream& os, const _string& s);
    istream& operator>>(istream& is, _string&s);
    bool operator==(const _string& lhs, const _string& rhs);
    bool operator!=(const _string& lhs, const _string& rhs);
    char* begin(_string& s);
    char* end(_string& s);
    const char* begin(const _string& s);
    const char* end(const _string& s);
    _string& operator+=(_string& lhs, const _string& rhs);
    _string operator+(const _string& lhs, const _string& rhs);
    _string operator"" _s(const char* p,size_t);

    void drive_string();
}




#endif //WORKBENCH__STRING_H
