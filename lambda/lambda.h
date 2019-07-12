//
// Created by egl on 7/10/19.
//

#ifndef WORKBENCH_LAMBDA_H
#define WORKBENCH_LAMBDA_H

#include <vector>
#include <functional>
namespace lambda {
    using FilterContainer = std::vector<std::function<bool(int)>>;

    void drive_lambda_samples();
}


#endif //WORKBENCH_LAMBDA_H
