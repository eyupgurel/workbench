//
// Created by egl on 4/13/19.
//

#ifndef WORKBENCH_VECTOR_BASE_H
#define WORKBENCH_VECTOR_BASE_H


#include <memory>
using namespace std;

namespace containers {
    template<class T, class A=allocator<T>>
    struct vector_base {
        A alloc;
        T *elem;
        T *space;
        T *last;

        vector_base(const A &a, typename A::size_type n)
                : alloc{a}, elem{alloc.allocate(n)}, space{elem + n}, last{elem + n} {}

        ~vector_base() { alloc.deallocate(elem, last - elem); }

        vector_base(const vector_base &) = delete;

        vector_base &operator=(const vector_base &) = delete;

        vector_base(vector_base &&);

        vector_base& operator=(vector_base &&)noexcept;
    };

}


#endif //WORKBENCH_VECTOR_BASE_H
