//
// Created by egl on 5/27/19.
//

#ifndef WORKBENCH_ALGORITHMS_H
#define WORKBENCH_ALGORITHMS_H
#include <functional>
using namespace std;
namespace templates {

    template<typename Iter, typename Val>
    Val add(Iter begin, Iter end){
        Val v{};
       for(Iter b{begin};b!=end;++b)
           v+=*b;
       return v;
    }

    template<typename Iter, typename Val, typename Oper>
    Val accumulate(Iter begin, Iter end, Val vin, Oper op){
        for(Iter b{begin};b!=end;++b)
            vin=op(vin,*b);
        return vin;
    }

    void drive_template_algorithms();

}


#endif //WORKBENCH_ALGORITHMS_H
