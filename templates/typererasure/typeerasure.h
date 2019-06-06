//
// Created by egl on 6/3/19.
//

#ifndef WORKBENCH_TYPEERASURE_H
#define WORKBENCH_TYPEERASURE_H
#include <memory>
namespace templates{
    struct var {
        var() : _inner(new inner<int>{0}){} //default construct to an integer

        var(const var& src) : _inner{src._inner->clone()} {} //copy constructor calls clone method of concrete type

        template <typename _Ty> var(_Ty&& src) : _inner{new inner<_Ty>(std::forward<_Ty>(src))} {}

        template <typename _Ty> var& operator = (_Ty&& src) { //assign to a concrete type
            _inner = std::make_unique<inner<_Ty>>(std::forward<_Ty>(src));
            return *this;
        }

        var& operator=(const var& src) { //assign to another var type
            var oTmp{src};
            std::swap(oTmp, *this);
            return *this;
        }

        //interrogate the underlying type through the inner_base interface
        const std::type_info& Type() const { return _inner->Type(); }
        bool IsPOD() const { return _inner->IsPOD(); }
        size_t Size() const { return _inner->Size(); }

        //cast the underlying type at run-time
        template <typename _Ty> _Ty& cast() {
            return *dynamic_cast<inner<_Ty>&>(*_inner);
        }

        template <typename _Ty> const _Ty& cast() const {
            return *dynamic_cast<inner<_Ty>&>(*_inner);
        }

        struct inner_base {
            using Pointer = std::unique_ptr <inner_base> ;
            virtual ~inner_base() {}
            virtual inner_base * clone() const = 0;
            virtual const std::type_info& Type() const = 0;
            virtual bool IsPOD() const = 0;
            virtual size_t Size() const = 0;
        };

        template <typename _Ty> struct inner : inner_base {
            inner(_Ty newval) : _value{std::move(newval)} {}
            virtual inner_base * clone() const override { return new inner(_value); }
            virtual const std::type_info& Type() const override { return typeid(_Ty); }
            _Ty & operator * () { return _value; }
            const _Ty & operator * () const { return _value; }
            virtual bool IsPOD() const { return std::is_pod<_Ty>::value; }
            virtual size_t Size() const { return sizeof(_Ty); }
        private:
            _Ty _value;
        };

        inner_base::Pointer _inner;
    };

//this is a specialization of an erased std::wstring
    template <>
    struct var::inner<std::wstring> : var::inner_base{
        inner(std::wstring newval) : _value(std::move(newval)) {}
        virtual inner_base * clone() const override { return new inner(_value); }
        virtual const std::type_info& Type() const override { return typeid(std::wstring); }
        std::wstring & operator * () { return _value; }
        const std::wstring & operator * () const { return _value; }
        virtual bool IsPOD() const { return false; }
        virtual size_t Size() const { return _value.size(); }
    private:
        std::wstring _value;
    };

    void drive_var();
}

#endif //WORKBENCH_TYPEERASURE_H
