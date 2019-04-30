//
// Created by egl on 4/30/19.
//

#ifndef WORKBENCH_CHRONO_H
#define WORKBENCH_CHRONO_H
#include <string>
using namespace std;
namespace chrono{
    enum class Month{jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};
    class Date{
    public:
        class bad_date:exception{};
        explicit Date(int dd={}, Month mm={}, int yy={});

        int day() const;
        Month month() const;
        int year() const;

        string string_rep() const;
        void char_rep(char s[], int max) const;

        Date& add_year(int n);
        Date& add_month(int n);
        Date& add_day(int n);
    private:
        bool is_valid();
        int d,y;
        Month m;
    };

    bool is_date(int d, Month m, int y);
    bool is_leapyear(int y);
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);


    Date& operator++(Date& d);
    Date& operator--(Date& d);

    Date& operator+=(Date& d, int n);
    Date& operator-=(Date& d, int n);

    Date operator+(Date d, int n);
    Date operator-(Date d, int n);


    const Date& default_date();

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, const Date& d);

}
#endif //WORKBENCH_CHRONO_H
