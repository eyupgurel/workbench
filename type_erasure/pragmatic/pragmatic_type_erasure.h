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
        anything(const anything& rhs):handle_{rhs.handle_->clone()}{};
        anything& operator=(const anything& rhs){
            anything temp{rhs};
            std::swap(temp,*this);
            return *this;
        };

        anything(anything&& rhs) noexcept :handle_{std::move(rhs.handle_)}{
            std::cout << "anything(anything&& rhs) noexcept" << std::endl;
        }

        anything& operator=(anything&& rhs) noexcept{
            handle_.swap(rhs.handle_);
            return *this;
        }

        template<typename T,typename = std::enable_if_t<!std::is_base_of<anything, std::decay_t<T>>::value>> anything(T&& t):handle_{new handle<std::remove_reference_t<T>>(std::forward<T>(t))} {
            std::cout << "template<typename T,typename = std::enable_if_t<!std::is_base_of<anything, std::decay_t<T>>::value>> anything(T&& t)" << std::endl;
        }
        template<typename T,typename = std::enable_if_t<!std::is_base_of<anything, std::decay_t<T>>::value>> anything& operator=(T&& t){
            handle_.reset(new handle<std::remove_reference_t<T>>{std::forward<T>(t)});
            return *this;
        };

        struct handle_base
        {
            virtual ~handle_base()=default;
            virtual handle_base* clone() const=0;
        };

        template<typename T>
        struct handle:handle_base{
            using type=T;
            template<typename V,typename = std::enable_if_t<!std::is_base_of<handle, std::decay_t<V>>::value>>
            explicit handle(V&& value):value_{std::forward<V>(value)}{};

            handle(const handle& rhs)= default;
            handle& operator=(const handle& rhs)=default;
            handle(handle&& rhs)noexcept=default;
            handle& operator=(handle&& rhs) noexcept =default;

            handle_base* clone() const override{return new anything::handle<T>{value_};};
            T value_;
        };

        std::unique_ptr<handle_base> handle_;
    };

    void drive_pragmatic_type_erasure();
}


#endif //WORKBENCH_PRAGMATIC_TYPE_ERASURE_H
