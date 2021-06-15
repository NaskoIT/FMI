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

class Date {
private:
    const int MONTHS_COUNT = 12;
    const int DAYS_PER_YEAR = 365;
    const int DAYS_PER_4_YEARS = DAYS_PER_YEAR * 4 + 1; // 1461
    const int DAYS_PER_100_YEARS = DAYS_PER_4_YEARS * 25 - 1;  // 36524
    const int DAYS_PER_400_YEARS = DAYS_PER_100_YEARS * 4 + 1; // 146097

    static int daysToMonth365[];
    static int daysToMonth366[];

    int year;
    int month;
    int day;
    int totalDays;

public:
    Date();

    Date(int day, int month, int year);

    int getYear();

    int getMonth();

    int getDay();

    void addDays(int n);

    void removeDays(int n);

    bool isLeapYear();

    int daysToXmas();

    int daysToNewYear();

    int getDaysUntil(Date date);

    bool isEarlierThan(Date date);

private:
    static int *getDaysToMonth(bool isLeapYear);

    void setTotalDays();

    void onTotalDaysChange();
};
