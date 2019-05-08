//
// Created by egl on 5/6/19.
//

#ifndef WORKBENCH_XREF_H
#define WORKBENCH_XREF_H
#include <utility>
#include <string>
#include <iostream>
#include <memory>
using namespace std;
namespace forward{
    template<typename TT, typename A>
    unique_ptr<TT> make_unique(int i, A&& a)
    {
        return unique_ptr<TT>{new TT{i, std::forward<A>(a)}};
    }


    template<typename T>
    class Xref {
    public:
        Xref(int i, T* p)// store a pointer: Xref is the owner
        :index{i}, elem{p}, owned{true}
        {
            std::cout << "ran Xref(int i, T* p)\n";
        }
        Xref(int i, T& r)// store a pointer to r, owned by someone else
               :index{i}, elem{&r}, owned{false}
        {
            std::cout << "ran Xref(int i, T& r)\n";
        }
        Xref(int i, T&& r)// move r into Xref, Xref is the owner
                :index{i}, elem{new T{move(r)}}, owned{true}
        {
            std::cout << "ran Xref(int i, T&& r)\n";
        }
        ~Xref()
        {
            if(owned) delete elem;
        }
// ...
    private:
        int index;
        T* elem;
        bool owned;
    };

    void driveXref();
}



#endif //WORKBENCH_XREF_H
