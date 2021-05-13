#include <iostream>
#include <stdexcept>

int FEBRUARY = 2;
int YEAR_OF_THE_BEGINNING = 1970;
int YEAR_OF_THE_END = 2099;
int NUMBER_OF_MONTH = 12;
int NUMBER_OF_DAYS = 365;
int LAST_DAY = 31;
int FEBRUARY_DAYS = 28;
int LEAP_YEAR_PERIOD = 4;
int DAYS[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date{
public:
    explicit Date(int day, int month, int year) {
        day_ = day;
        month_ = month;
        year_ = year;
        if (year > YEAR_OF_THE_END || year < YEAR_OF_THE_BEGINNING) {
            throw std::invalid_argument("Invalid year");
        }
        if (month_ > NUMBER_OF_MONTH || month_ < 1 ){
            throw std::invalid_argument("Invalid month");
        }
        if (day_ < 1 || day_ > getNumberOfDays(month_, year_)) {
            throw std::invalid_argument("Invalid number of days");
        }
    }
    static int getNumberOfDays(int month, int year) {

        if (year % LEAP_YEAR_PERIOD == 0) {
            if (month == FEBRUARY) {return FEBRUARY_DAYS + 1;}
        }
        return DAYS[month];
    }
    static int number_of_leap_days(int year1, int month1, int year2) {
        if (month1 <= FEBRUARY) {
            year1 -= 1;
        }
        int leap_days = 0;
        while (year2 < year1) {
            if (year1 % LEAP_YEAR_PERIOD == 0) {
                leap_days += 1;
            }
            year1 -= 1;
        }
        return leap_days;
    }

    explicit Date (const int days) {
        int full_years = days / NUMBER_OF_DAYS;
        int year = YEAR_OF_THE_BEGINNING + full_years;
        int leap_days = number_of_leap_days(year, NUMBER_OF_MONTH, YEAR_OF_THE_BEGINNING);
        int day = days % NUMBER_OF_DAYS - leap_days;
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
                day_ ++;
        } else {
            day_ = 1;
            if (month_ == NUMBER_OF_MONTH) {
                month_ = 1;
                year_ ++;
                } else {
                month_ ++;
            }
            }

        return *this;

    };
    Date& operator--(){
        if (day_ != 1) {
            day_ --;
        } else {
            if (month_ != 1) {
                month_ --;
                day_ = getNumberOfDays(month_, year_);
            } else {
                day_ = LAST_DAY;
                month_ = NUMBER_OF_MONTH;
                year_ --;
            }
        }
        return *this;
    }

    static int daysFromTheBeginningOfTime(const Date date){
        int full_years = date.year_ - YEAR_OF_THE_BEGINNING;

        int leap_years = number_of_leap_days(date.year_, date.month_, YEAR_OF_THE_BEGINNING);

        int days = NUMBER_OF_DAYS * full_years + leap_years;
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
