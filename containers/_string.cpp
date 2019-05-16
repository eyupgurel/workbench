//
// Created by egl on 5/15/19.
//

#include "_string.h"

using namespace containers;
_string::_string():sz{0},ptr{ch}{
    ch[0]=0;
}

_string::_string(const char* p):sz{strlen(p)},
                                ptr{sz<=short_max?ch:new char[sz+1]},
                                space{0}{
    strcpy(ptr,p);
}

template<size_t N>
_string::_string(const char(&p)[N]):sz{N},ptr{sz<=short_max?ch:new char[sz+1]},space{0}{
    strcpy(ptr,p);
}

_string::_string(const _string& s){
   copy_from(s);
}

_string::_string(_string&& s)noexcept {
    move_from(s);
}

_string& _string::operator=(const _string& s){
    if(&s==this) return *this; //deal with self assignment
    char* p= sz>short_max ? ptr : nullptr;
    copy_from(s);
    delete[] p;
    return *this;
}

_string& _string::operator=(_string&& s) noexcept {
    if(&s==this) return *this; // deal with self-assignment (x = move(x) is insanity)
    if(sz>short_max) delete[]ptr;
    move_from(s);
    return *this;
}

void _string::copy_from(const _string& s){
    if(s.sz<=short_max){
        memcpy(this,&s,sizeof(s));
        ptr=ch;
    } else{
        ptr=expand(s.ptr,s.sz+1);
        sz=s.sz;
        space=0;
    }
}

void _string::move_from(_string &s) {
    if(s.sz<=short_max){
        memcpy(this,&s,sizeof(s));
        ptr=ch;
    } else{
        ptr=s.ptr;
        sz=s.sz;
        space=s.space;
        s.ptr=s.ch;
        s.sz=0;
        s.ch[0]=0;
    }
}

_string& _string::operator+=(char ch){
    if(sz==short_max){ //expand to long string
        int n = sz+sz+2; // double the allocation (+2 because of the terminating 0)
        ptr=expand(ptr,n); //old ptr points to char ch[short_max+1] new ptr is allocated on the heap
        space = n-sz-2;
    } else if(sz>short_max){
        if(space==0){ // expand in free store
            int n = sz+sz+2; // double the allocation (+2 because of the terminating 0)
            char* p=expand(ptr,n);
            delete[]ptr;
            ptr=p;
            space=n-sz-2;
        }
        else
            --space;
    }
    ptr[sz]=ch;
    ptr[++sz]=0;
    return *this;
}


char * containers::expand(const char* ptr, int n)
{
    char* p{new char[n]};
    strcpy(p,ptr);
    return p;
}

ostream& containers::operator<<(ostream &os, const _string &s) {
    return os << s.c_str();
}

istream& containers::operator>>(istream &is, containers::_string &s) {
    s=""; //clear the target string
    is>>ws; //skip whitespace
    char ch{0};
    while(is.get(ch)&&!isspace(ch))
        s+=ch;
    return is;
}

bool containers::operator==(const containers::_string &lhs, const containers::_string &rhs) {
    if(lhs.size()!=rhs.size()) return false;
    for(auto i=0;i<lhs.size();++i)
        if(lhs[i]!=rhs[i])
            return false;
    return true;
}
bool containers::operator!=(const containers::_string &lhs, const containers::_string &rhs) {
    return !(lhs==rhs);
}

char* containers::begin(_string& s){
    return s.c_str();
}
char* containers::end(_string& s){
    return s.c_str()+s.size();
}
const char* containers::begin(const _string& s){
    return s.c_str();
}
const char* containers::end(const _string& s){
    return s.c_str()+s.size();
}

_string& containers::operator+=(containers::_string &lhs, const containers::_string &rhs) {
    for(auto ch:rhs)
        lhs+=ch;
    return lhs;
}
_string containers::operator+(const containers::_string &lhs, const containers::_string &rhs) {
    _string sum{lhs};
    sum+=rhs;
    return sum;
}

_string containers::operator ""_s(const char *p, size_t) {
    return _string{p};
}

_string f(const _string& s){
    cout << s << endl;
    _string d=s+s;
    return d;
}

void containers::drive_string() {
    _string r{f("print me!")};
    char animal[8]{"Mammoth"};
    _string sa{animal};

    _string s{"abcdefghij"};
    cout << s << '\n';
    s+='k';
    s+='l';
    s+='m';
    s+='n';
    cout << s << '\n';

    _string s2="Hell";
    s2 += " and high water";
    cout << s2 << '\n';
    _string s3 = "qwerty";
    s3 = s3;
    _string s4 ="the quick brown fox jumped over the lazy dog";
    s4 = s4;
    cout << s3 << " " << s4 << "\n";
    cout << s + ". " + s3 + _string(". ") + "Horsefeathers\n";
    _string buf;
    while (cin>>buf && buf!="quit")
        cout << buf << " " << buf.size() << " " << buf.capacity() << '\n';
}