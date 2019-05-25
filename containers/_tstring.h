//
// Created by egl on 5/24/19.
//

#ifndef WORKBENCH__TSTRING_H
#define WORKBENCH__TSTRING_H

namespace containers {

    template<typename C>
    class _tstring {
    public:
        _tstring();

        explicit _tstring(const C *);

        _tstring(const _tstring &);

        _tstring operator=(const _tstring &);

        C &operator[](int n) { return ptr[n]; };

        _tstring &operator+=(C c);

    private:
        static constexpr int short_max = 15;
        int sz;
        C *ptr;
        C ch[short_max];

    };
}

#endif //WORKBENCH__TSTRING_H
