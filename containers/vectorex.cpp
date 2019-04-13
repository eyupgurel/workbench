//
// Created by egl on 4/12/19.
//

#include "vectorex.h"
namespace containers {
    template<class T,class A>
    void vectorex<T,A>::destroy_elements(){
        for(T* p=b.elem;p!=b.space;++p)
            p->~T();
        b.space = b.elem;
    }

    template<class T, class A>
    vectorex<T,A>::vectorex(size_type n, const T& val, const A& a):b{a,n}{
        uninitialized_fill(b.elem,b.elem+n,val);
    }

    template<class T, class A>
    vectorex<T,A>::vectorex(const vectorex<T,A>& v):b{v.alloc,v.size()}{
        uninitialized_copy(v.begin(),v.end(),b.elem);
    }

}
