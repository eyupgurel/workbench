//
// Created by egl on 4/14/19.
//

#ifndef WORKBENCH_MOVE_H
#define WORKBENCH_MOVE_H

#include <utility>
using namespace std;
namespace memory{
    template<typename T, typename In, typename Out>
    Out uninitialized_move(In b, In e, Out oo){
        for(;b!=e;++b,++oo){
            ::new(static_cast<void*>(&*oo)) T{move(*b)};
            b->~T();
        }
        return b;
    }

    template<typename T, typename In>
    void destroy(In b, In e)
    {
        for(;b!=e;++b) //destroy [b:e)
            b->~T();

    }


}


#endif //WORKBENCH_MOVE_H
