//
// Created by egl on 3/3/19.
//

#ifndef WORKBENCH_MYARRAY_H
#define WORKBENCH_MYARRAY_H

#include <cstddef>
#include "../common.h"

namespace containers{
    template<typename T, size_t N>
    class myarray {
        public:
            T elem[N];
            T* begin() noexcept;
            const T* begin() const noexcept;
            T* end() noexcept;
            const T* end() const noexcept;
            constexpr size_t size() noexcept{return N;};

            T& operator[](int i);
            const T& operator[](int i) const;

            T* data() noexcept;
            const T* data() const noexcept;

    };



}



#endif //WORKBENCH_MYARRAY_H
