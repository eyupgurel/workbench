//
// Created by egl on 6/13/19.
//

#ifndef WORKBENCH_PRINTF_H
#define WORKBENCH_PRINTF_H
#include <stdexcept>
#include <iostream>
using namespace std;
namespace io{

    void printf(const char* s){
        if(s== nullptr) return;
        while(*s){
            if(*s=='%'&& *++s!='%')
                throw runtime_error("invalid format: missing arguments");
            cout << *s++;
        }
    }

    template<typename T, typename... Args>
    void printf(const char* s, T value, Args... args){
        while(s&&*s){
            if(*s=='%'&& *++s!='%')
            {
                cout << value;
                return printf(++s,args...);
            }
            cout<<*s++;
        }
        throw runtime_error("extra arguments provided to printf");
    }



}
#endif //WORKBENCH_PRINTF_H
