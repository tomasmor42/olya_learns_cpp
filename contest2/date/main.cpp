#include <iostream>
#include <stdexcept>

int getNumberOfDays(int month, int year) {
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (year % 4 == 0) {
        if (month == 2) {return 29;}
    }
    return days[month];
}

int number_of_leap_days(int year1, int month1, int year2) {
    if (month1 <= 2) {
        year1 -= 1;
    }
    int leap_days = 0;
    while (year2 < year1) {
        if (year1 % 4 == 0) {
            leap_days += 1;
        }
        year1 -= 1;
    }
    return leap_days;
}

class Date{
public:
    explicit Date(int day, int month, int year) {
        day_ = day;
        month_ = month;
        year_ = year;
        if (year > 2099 || year < 1970) {
            throw std::invalid_argument("Invalid year");
        }
        if (month_ > 12 || month_ <1 ){
            throw std::invalid_argument("Invalid month");
        }
        if (day_ < 1 || day_ > getNumberOfDays(month_, year_)) {
            throw std::invalid_argument("Invalid number of days");
        }
    }

    explicit Date (const int days) {
        int full_years = days / 365;
        int year = 1970 + full_years;
        int leap_days = number_of_leap_days(year, 12, 1970);
        int day = days % 365 - leap_days;
        int month = 0;
        while (day > getNumberOfDays(month, year)) {
            day -= getNumberOfDays(month, year);
            month += 1;
        }
        day_ = day;
        month_ = month;
        year_ = year;
    }

    int GetDay() const {
        return day_;
    }

    int GetMonth() const {
        return month_;
    }

    int GetYear() const {
        return year_;
    }

    Date& operator++() {
        if (day_ != getNumberOfDays(month_, year_)) {
                day_ += 1;
            } else {
            day_ = 1;
            if (month_ == 12) {
                month_ = 1;
                year_ += 1;
                } else {
                month_ +=1;
            }
            }

        return *this;

    };
    Date& operator--(){
        if (day_ != 1) {
            day_ -= 1;
        } else {
            if (month_ != 1) {
                month_ -= 1;
                day_ = getNumberOfDays(month_, year_);
            } else {
                day_ = 31;
                month_ = 12;
                year_ -= 1;
            }
        }
        return *this;
    }

    static int daysFromTheBeginningOfTime(const Date date){
        int full_years = date.year_ - 1970;

        int leap_years = number_of_leap_days(date.year_, date.month_, 1970);

        int days = 365 * full_years + leap_years;
        int month = date.month_;
        while (--month)
        {
            days += getNumberOfDays(month, date.year_);
        }
        days += date.day_;
        return days;
    }

    Date operator+(int days){
        int days_from_beginning = daysFromTheBeginningOfTime(*this);
        Date date = Date(days_from_beginning + days);
        return date;
    }

    int day_;
    int month_;
    int year_;

};

Date operator-(const Date& lhs, int days) {

    int res_days = Date::daysFromTheBeginningOfTime(lhs) - days;
    return Date(res_days);
}

Date operator+(const Date& lhs, int days) {

    int res_days = Date::daysFromTheBeginningOfTime(lhs) + days;
    return Date(res_days);
}

int operator-(const Date& lhs, const Date& rhs) {

    int res_days = Date::daysFromTheBeginningOfTime(lhs) - Date::daysFromTheBeginningOfTime(rhs);
    return res_days;
}

std::ostream& operator<<(std::ostream& os, const Date & c)
{
    os << c.day_ << "-" << c.month_ << "-" << c.year_;
    return os;
}


int main() {
    Date d1 = Date(28, 2, 1973);
    Date d2 = d1 - 366;
    std::cout << d2 << std::endl;
    return 0;
}
