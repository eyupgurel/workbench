//
// Created by egl on 4/12/19.
//

#include "vectorex.h"
using namespace containers;
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

template<class T, class A>
vectorex<T,A>::vectorex(vectorex<T,A> &&v):b{move(v.b)} {

}

template<class T, class A>
vectorex<T,A>& vectorex<T,A>::operator=(vectorex<T, A> &&v)noexcept {
    clear();
    std::swap(*this,v);
    return *this;
}

template<class T, class A>
vectorex<T,A>& vectorex<T,A>::operator=(const vectorex<T, A> &v) noexcept {
    if(capacity()<v.size()){
        auto temp{v};
        std::swap(*this,temp);
        return *this;
    }
    if(this==&v)
        return *this;

    b.space = b.end();
    size_type sz = size();
    size_type asz = v.size();
    b.alloc = v.b.alloc;

    if(asz<=sz){
        copy(v.begin(),v.begin()+asz,b.elem);
        for(T* p = b.elem+asz;p!=b.space;++p)
            p->~T();
    } else{
        copy(v.begin(),v.begin()+sz,b.elem);
        uninitialized_copy(v.begin()+sz,v.end(),b.space);
    }
    b.space = b.end = b.elem+asz;
    return *this;
   }

   template<typename T, typename A>
   void vectorex<T,A>::reserve(vectorex<T,A>::size_type n) {
       if(n<=capacity()) return; //never decrease allocation
       vector_base<T,A>nb{b.alloc,n};
       memory::uninitialized_move<T>(b.elem,b.elem+size(),nb.elem);
       swap(b,nb);
   }

   template<typename T, typename A>
   void vectorex<T,A>::resize(size_type n, const T& val){
       reserve(n);
       if(size()<n)
           uninitialized_fill(b.elem+size(), b.elem+n, val);
       else
           memory::destroy<T>(b.elem+size(),b.elem+n);
       b.space = b.last = b.elem+n;
   }

   template<typename T, typename A>
   void vectorex<T,A>::push_back(const T& val){
       if(capacity()==size())
           reserve(size()?size()*2:8);
       b.alloc.construct(&b.elem[size()],val);
       ++b.last;
       ++b.space;
   }


   void containers::drive_vectorex() {
       //vectorex<int,std::allocator<int>>vx(3);
       //vx.push_back(1);
       //vx.push_back(2);
       //vx.push_back(3);
       //auto vx2{vx};
       //auto vx1{move(vx)};
    }
