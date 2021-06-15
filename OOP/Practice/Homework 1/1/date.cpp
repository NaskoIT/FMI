/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 1
* @compiler GCC
*/

#include "date.hpp"

int Date::daysToMonth365[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int Date::daysToMonth366[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

Date::Date() {
    this->year = 2000;
    this->month = 1;
    this->day = 1;
    this->setTotalDays();
}

Date::Date(int day, int month, int year) {
    // TODO Validate the input data and throw exception if the parameters are invalid
    this->day = day;
    this->month = month;
    this->year = year;
    this->setTotalDays();
}

int Date::getYear() {
    return this->year;
}

int Date::getMonth() {
    return this->month;
}

int Date::getDay() {
    return this->day;
}

// Add addDays and removeDays could be merged if we allow passing negative values to addDays function
void Date::addDays(int n) {
    if(n <= 0) {
        return;
    }

    this->totalDays += n;
    this->onTotalDaysChange();
}

void Date::removeDays(int n) {
    if (this->totalDays - n < 0) {
        // TODO: throw an exception
        return;
    }

    this->totalDays -= n;
    this->onTotalDaysChange();
}

bool Date::isLeapYear() {
    if (this->year % 4 == 0) {
        if (this->year % 100 == 0) {
            return this->year % 400 == 0;
        }

        return true;
    }

    return false;
}

int Date::getDaysUntil(Date date) {
    if (this->totalDays > date.totalDays) {
        return -1;
    }

    return date.totalDays - this->totalDays;
}

int Date::daysToXmas() {
    Date christmas = Date(25, 12, this->year);
    if(!this->isEarlierThan(christmas)) {
        Date newYearChristmas = Date(25, 12, this-> year + 1);
        return this->getDaysUntil(newYearChristmas);
    }

    return this->getDaysUntil(christmas);
}

int Date::daysToNewYear() {
    Date newYear = Date(1, 1, this->year + 1);
    return this->getDaysUntil(newYear);
}

bool Date::isEarlierThan(Date date) {
    return date.totalDays > this->totalDays;
}

void Date::setTotalDays() {
    int *days = getDaysToMonth(this->isLeapYear());
    int y = this->year - 1;
    this->totalDays = y * 365 + y / 4 - y / 100 + y / 400 + days[this->month - 1] + this->day - 1;
}

void Date::onTotalDaysChange() {
    int n = this->totalDays;

    // y400 = number of whole 400-year periods since 1/1/0001
    int y400 = n / DAYS_PER_400_YEARS;
    // n = day number within 400-year period
    n -= y400 * DAYS_PER_400_YEARS;

    // y100 = number of whole 100-year periods within 400-year period
    int y100 = n / DAYS_PER_100_YEARS;
    // Last 100-year period has an extra day, so decrement result if 4
    if (y100 == 4) {
        y100 = 3;
    }

    // n = day number within 100-year period
    n -= y100 * DAYS_PER_100_YEARS;

    // y4 = number of whole 4-year periods within 100-year period
    int y4 = n / DAYS_PER_4_YEARS;
    // n = day number within 4-year period
    n -= y4 * DAYS_PER_4_YEARS;

    // y1 = number of whole years within 4-year period
    int y1 = n / DAYS_PER_YEAR;
    // Last year has an extra day, so decrement result if 4
    if (y1 == 4) {
        y1 = 3;
    }

    this->year = y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1;
    n -= y1 * DAYS_PER_YEAR;

    // Leap year calculation looks different from IsLeapYear since y1, y4 and y100 are relative to year 1, not year 0
    bool leapYear = y1 == 3 && (y4 != 24 || y100 == 3);
    int *daysToMonth = getDaysToMonth(leapYear);

    int m = 1;
    while (n >= daysToMonth[m]) {
        m++;
    }

    this->month = m;
    // calculate 1-based day-of-month
    this->day = n - daysToMonth[m - 1] + 1;
}

int *Date::getDaysToMonth(bool isLeapYear) {
    return isLeapYear ? daysToMonth366 : daysToMonth365;
}
