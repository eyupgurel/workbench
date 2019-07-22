//
// Created by egl on 7/22/19.
//

#ifndef WORKBENCH_BASIC_TYPE_ERASURE_H
#define WORKBENCH_BASIC_TYPE_ERASURE_H
#include <memory>
#include <iostream>
namespace type_erasure::basic{
    struct TypeErased{
        template<typename T>
        TypeErased(T&& value){*this=std::forward<T>(value);}
        template<typename T>
        TypeErased& operator=(T&& value){
            m_value.reset(new Model<T>{std::forward<T>(value)});
            return *this;
        }
        void printName() const
        {m_value->printName();}
    private:
        struct Concept{
            virtual ~Concept()=default;
            virtual void printName() const=0;
        };
        template<typename T>
        struct Model:Concept{
            template<typename V>
            Model(V&& value):m_val{std::forward<V>(value)}{
                std::cout << "value imparted" << std::endl;
            }
            void printName() const override{m_val.printName();}
            T m_val;
        };
        std::unique_ptr<Concept> m_value;
    };

    void drive_basic_type_erasure();


}

#endif //WORKBENCH_BASIC_TYPE_ERASURE_H
