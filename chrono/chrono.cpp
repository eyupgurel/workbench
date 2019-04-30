//
// Created by egl on 4/30/19.
//

#include "chrono.h"

using namespace chrono;

const Date& chrono::default_date(){
    static Date dd{1,Month::jan,1970};
    return dd;
}

bool chrono::is_leapyear(int y) {
    return y%4==0;
}

bool chrono::is_date(int d, Month m, int y)
{
    int ndays;
    switch (m) {
        case Month::feb:
            ndays = 28+is_leapyear(y);
            break;
        case Month::apr: case Month::jun: case Month::sep: case Month::nov:
            ndays = 30;
            break;
        case Month::jan: case Month::mar: case Month::may: case Month::jul:
        case Month::aug: case Month::oct: case Month::dec:
            ndays = 31;
            break;
        default:
            return false;
    }
    return 1<=d && d<=ndays;
}


Date::Date(int dd, Month mm, int yy):d{dd},m{mm},y{yy}{
    if(y==0) y=default_date().year();
    if(m==Month{}) m=default_date().month();
    if(d==0)d=default_date().day();
    if(!is_valid())throw bad_date();
}

bool Date::is_valid() {
    return is_date(d,m,y);
}

int Date::day() const {
    return d;
}

Month Date::month() const {
    return m;
}

int Date::year() const {
    return y;
}

Date& Date::add_month(int n)
{
    if (n==0) return *this;
    if (n>0) {
        int delta_y = n/12; // number of whole years
        int mm = static_cast<int>(m)+n%12;  // number of months ahead
        if (12 < mm) {  // note: dec is represented by 12
            ++delta_y;
            mm -= 12;
        }
        // ... handle the cases where the month mm doesn’t have day d ...

        y += delta_y;
        m = static_cast<Month>(mm);
        return *this;
    }
    // ... handle negative n ...
    return *this;
}


inline bool chrono::operator==(const chrono::Date &a, const chrono::Date &b) {
    return a.day()==b.day()&&a.month()==b.month()&&a.year()==b.year();
}



//Date& chrono::operator++(Date& d) { return d.add_day(1); }
//Date& chrono::operator--(Date& d) { return d.add_day(-1); }

//Date& chrono::operator+=(Date& d, int n) { return d.add_day(n); }
//Date& chrono::operator-=(Date& d, int n) { return d.add_day(-n); }

//Date chrono::operator+(Date d, int n) { return d+=n; }
//Date chrono::operator-(Date d, int n) { return d-=n; }
