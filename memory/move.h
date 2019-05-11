//
// Created by egl on 4/14/19.
//

#ifndef WORKBENCH_MOVE_H
#define WORKBENCH_MOVE_H

#include <utility>
using namespace std;
namespace memory{
    /**
     *  @brief  Forward an lvalue.
     *  @return The parameter cast to the specified type.
     *
     *  This function is used to implement "perfect forwarding".
     */
    template<typename _Tp>
    constexpr _Tp&&
    my_forward(typename std::remove_reference<_Tp>::type& __t) noexcept
    { return static_cast<_Tp&&>(__t); }

    /**
     *  @brief  Forward an rvalue.
     *  @return The parameter cast to the specified type.
     *
     *  This function is used to implement "perfect forwarding".
     */
    template<typename _Tp>
    constexpr _Tp&&
    my_forward(typename std::remove_reference<_Tp>::type&& __t) noexcept
    {
        static_assert(!std::is_lvalue_reference<_Tp>::value, "templates argument"
                                                             " substituting _Tp is an lvalue reference type");
        return static_cast<_Tp&&>(__t);
    }

    template<typename T, typename In, typename Out>
    Out uninitialized_move(In b, In e, Out oo){
        for(;b!=e;++b,++oo){
            ::new(static_cast<void*>(&*oo)) T{std::move(*b)};
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
