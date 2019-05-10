//
// Created by egl on 5/10/19.
//

#ifndef WORKBENCH_SFINAE_H
#define WORKBENCH_SFINAE_H
#include <vector>
using namespace std;
namespace SFINAE{

    // When looking for a best match for a set of arguments for a function template, the compiler considers
    // whether the argument can be used in the way required by the complete function template declaration
    // (including the return type).
    // For example:

    template<typename Iter>
    typename Iter::value_type mean(Iter first, Iter last){
        typename Iter::value_type t{};
        for(auto iter=first;iter!=last;iter++){
            t+=*iter;
        }
        return t/(last-first);
    }
    template<typename T>
    T mean(T* first,T* last){
        T t{};
        for(auto iter=first;iter!=last;iter++){
            t+=*iter;
        }
        return t/(last-first);
    }
    void f(vector<int>&v, int* p,int n){
        //Here, the initialization of x succeeds because the arguments match and vector<int>::iterator has a
        //member called value_type.
        //The initialization of y would have failed had T "mean(T* first,T* last);" not defined because even though the arguments match,
        //int∗ does not have a member called value_type , so we cannot say:
        //int∗::value_type mean(int∗,int∗);
        //obviously int* does not have a member called value_type


        //This works: both initializations succeed. But why didn’t we get an error when trying to match
        //mean(p,p+n) with the first template definition? The arguments match perfectly, but by substituting
        //in the actual template argument ( int∗ ), we get the function declaration:
        //int∗::value_type mean(int∗,int∗); int* does not have a member called value_type
        //That is garbage, of course: a pointer does not have a member value_type . Fortunately, considering
        //this possible declaration is not by itself an error. There is a language rule (§iso.14.8.2) that says
        //that such a substitution failure is not an error. It simply causes the template to be ignored; that is,
        //the template does not contribute a specialization to the overload set. That done, mean(p,p+n)
        //matches declaration #2, which is called.

        auto x=mean(v.begin(),v.end());
        auto y=mean(p,p+n);
    }



}


#endif //WORKBENCH_SFINAE_H
