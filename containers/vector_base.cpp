//
// Created by egl on 4/13/19.
//

#include "vector_base.h"
namespace containers {
    template<class T,class A>
    vector_base<T,A>::vector_base(vector_base&& b):alloc_{b.alloc},
    elem{b.elem},space{b.space},last{b.last}{b.space = b.last = b.elem = nullptr;}



    template<class T,class A>
    vector_base<T,A>& vector_base<T,A>::operator=(vector_base&& b)noexcept {
        swap(*this,b);
        return *this;
    }


}