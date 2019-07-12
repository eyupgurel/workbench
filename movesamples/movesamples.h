//
// Created by egl on 7/12/19.
//

#ifndef WORKBENCH_MOVESAMPLES_H
#define WORKBENCH_MOVESAMPLES_H
#include <string>
#include <iostream>
#include <memory>

namespace movesamples{
    class person {
    public:
        template<typename U, typename V>
        person(U&& nm, V&& snm):name(std::forward<U>(nm)),surname(std::forward<V>(snm)){
            std::cout << "At constructor template:person(U&& nm, V&& snm)" << std::endl;
            std::cout << "person name:" << name << " " << "person surname:" << surname << std::endl;
        }
        person(person& p):name{p.name},surname{p.surname}{
            std::cout << "At person(person& p)" << std::endl;
            std::cout << "person name:" << name << " " << "person surname:" << surname << std::endl;
        };
        person& operator=(const person& p){
            std::cout << "At person& operator=(const person& p)" << std::endl;
            name=p.name;
            surname=p.surname;
            std::cout << "person name:" << name << " " << "person surname:" << surname << std::endl;
            return *this;
        }
        person(person&& p) noexcept:name{move(p.name)},surname{move(p.surname)} {
          std::cout << "At person(person&& p) noexcept" << std::endl;
          std::cout << "person name:" << name << " " << "person surname:" << surname << std::endl;
        }
        person& operator=(person&& p) noexcept{
            std::cout << "At person& operator=(person&& p) noexcept" << std::endl;
            name=move(p.name);
            surname=move(p.surname);
            std::cout << "person name:" << name << " " << "person surname:" << surname << std::endl;
            return *this;
        }

        ~person()=default;

        std::string name;
        std::string surname;
    };
    void drive_move_samples();

}



#endif //WORKBENCH_MOVESAMPLES_H
