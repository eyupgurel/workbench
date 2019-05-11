//
// Created by egl on 3/3/19.
//

#include "myarray.h"
using namespace containers;

    template<typename T, size_t N>
    T* myarray<T,N>::begin() noexcept{
        return elem;
    }

    template<typename T, size_t N>
    const T* myarray<T, N>::begin()const noexcept{
        return elem;
    }

    template<typename T, size_t N>
    T* myarray<T,N>::end() noexcept{
        return elem + N;
    }
    template<typename T, size_t N>
    const T* myarray<T,N>::end()const noexcept{
        return elem + N;
    }
    template<typename T, size_t N>
    T& myarray<T,N>::operator[](int i){
        return elem[i];
    }
    template<typename T, size_t N>
    const T& myarray<T,N>::operator[](int i) const{
        return elem[i];
    }

    template<typename T, size_t N>
    T* myarray<T,N>::data() noexcept {return elem;}

    template<typename T, size_t N>
    const T* myarray<T,N>::data()const noexcept {return elem;}

    //templates class myarray<Point,3>;
