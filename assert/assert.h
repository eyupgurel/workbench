//
// Created by egl on 4/11/19.
//

#ifndef WORKBENCH_ASSERT_H
#define WORKBENCH_ASSERT_H
#include <string>
#include <sstream>
using namespace std;
namespace Assert{
    enum class Mode{throw_,terminate_,ignore_};
    constexpr auto CURRENT_MODE{Mode::throw_};
    constexpr auto CURRENT_LEVEL{3};

    constexpr auto current_mode{CURRENT_MODE};
    constexpr auto current_level = CURRENT_LEVEL;
    constexpr auto default_level{1};

    constexpr bool level(int n){return n<=current_level;}

    struct Error:runtime_error{
        Error(const string& error):runtime_error(error){}
    };

    void run_test();
}

#endif //WORKBENCH_ASSERT_H
