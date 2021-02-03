#include <iostream>
#include "01_sqrt.h"
#include "02_revertString.h"
#include "03_dateTime.h"

using namespace std;

void test_sqrt_a() {
    double result = sqrt_a(15656.265625, 0.0001);
    cout << result;
}

void testRevert() {
    char str[] = "qweASD123zZ90GFAa";
    revert(str);
    cout << str;
}

void testCheckDate() {
    char date1[] = "123";
    char date2[] = "12/02";
    char date3[] = "32.01";
    char date4[] = "A2.12";
    char date5[] = "01.&1";
    char date6[] = "31.04";
    char date7[] = "12.12";
    char date8[] = "01.01";
    char date9[] = "31.12";
    char date10[] = "30.06";

    cout << date1 << " " << checkDate(date1) << endl;
    cout << date2 << " " << checkDate(date2) << endl;
    cout << date3 << " " << checkDate(date3) << endl;
    cout << date4 << " " << checkDate(date4) << endl;
    cout << date5 << " " << checkDate(date5) << endl;
    cout << date6 << " " << checkDate(date6) << endl;
    cout << date7 << " " << checkDate(date7) << endl;
    cout << date8 << " " << checkDate(date8) << endl;
    cout << date9 << " " << checkDate(date9) << endl;
    cout << date10 << " " << checkDate(date10) << endl;
}

int main() {
    testCheckDate();
}
