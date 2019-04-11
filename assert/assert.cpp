//
// Created by egl on 4/11/19.
//



#include "assert.h"

namespace Assert {
    string compose(const char *file, const int line, const string &message) {
        ostringstream oss;
        oss << "file: " << file << " line: " << line << " assertion: " << message;
        return oss.str();
    }

    template<bool condition = level(default_level), class Except=Error>
    void dynamic(bool assertion, const string &message = "Assert::dynamic failed") {
        if (assertion)
            return;
        switch (current_mode) {
            case Mode::throw_:
                throw Except{message};
            case Mode::terminate_:
                terminate();
            default:
                break;
        }
    }

    template<>
    void dynamic<false, Error>(bool, const string &) {

    }

    //void dynamic(bool b, const string& s){
    //    dynamic<true,Error>(b,s);
    //}

    //  void dynamic(bool b){
    //     dynamic<true,Error>(b);
    //}

    void test_dynamic1(int n) {
        Assert::dynamic<Assert::level(2), Assert::Error>(
                (n >= 0 && n < 10), Assert::compose(__FILE__, __LINE__, "invalid range!"));
    }

    void test_dynamic2(int n) {
        Assert::dynamic<Assert::level(4), Assert::Error>(
                (n >= 0 && n < 10), Assert::compose(__FILE__, __LINE__, "invalid range!"));

    }

    void test_dynamic3(int n) {

        Assert::dynamic(n < -10 || n > 10, Assert::compose(__FILE__, __LINE__, "invalid range!"));
    }

    void test_dynamic4(int n) {
        Assert::dynamic(n < -10 || n > 10);
    }

    void run_test(){
        Assert::test_dynamic2(-3);

        Assert::test_dynamic4(-3);

        Assert::test_dynamic3(-3);



        Assert::test_dynamic1(-3);
    }
}
