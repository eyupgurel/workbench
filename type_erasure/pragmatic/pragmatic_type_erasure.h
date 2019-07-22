//
// Created by egl on 7/22/19.
//

#ifndef WORKBENCH_PRAGMATIC_TYPE_ERASURE_H
#define WORKBENCH_PRAGMATIC_TYPE_ERASURE_H

#include <memory>
#include <utility>
namespace type_erasure::pragmatic{
    struct anything{
        anything()=default;
        anything(const anything& rhs);
        anything& operator=(const anything& rhs);
        template<typename T> anything(T&& t):handle_{new handle<std::remove_reference_t<T>>(std::forward<T>(t))} {
            std::cout << "anything::anything" << std::endl;
        }
        template<typename T,typename = std::enable_if_t<!std::is_base_of<anything, std::decay_t<T>>::value>> anything& operator=(T&& t){
            handle_.reset(new handle<std::remove_reference_t<T>>(std::forward<T>(t)));
            return *this;
        };

        struct handle_base
        {
            virtual ~handle_base(){}
            virtual handle_base* clone() const=0;
        };

        template<typename T>
        struct handle:handle_base{
            using type=T;
            template<typename V>
            handle(V&& value):value_{std::forward<V>(value)}{};
            //handle(T value);
            handle_base* clone() const override{return new anything::handle<T>{value_};};
            T value_;
        };

        std::unique_ptr<handle_base> handle_;
    };

    void drive_pragmatic_type_erasure();
}


#endif //WORKBENCH_PRAGMATIC_TYPE_ERASURE_H