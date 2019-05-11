//
// Created by egl on 5/11/19.
//

#include "array.h"
using namespace templates;

void templates::test_template_array() {
    int keys[]{1,3,5,6,7,34};
    int values[array_size(keys)];
    for(auto i=0; i<array_size(keys);++i){
        values[i]=keys[i]*keys[i];
    }
}
