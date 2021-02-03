// Atanas Vasilev - 62577
#include <iostream>

using namespace std;

const int NEW_NUMBER_DIGITS_COUNT = 2;

int getDigitsSum(int number);

int getNumberBuildFromNLastDigits(int number, int n);

int pow(int base, int degree);

int main() {
    int number;
    cin >> number;

    if (number > -10 && number < 10) {
        cout << "-1";
        return 0;
    }

    int digitsSum = getDigitsSum(number);
    int newNumber = getNumberBuildFromNLastDigits(number, NEW_NUMBER_DIGITS_COUNT);

    cout << (digitsSum == newNumber ? "true" : "false");
}

int getDigitsSum(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int getNumberBuildFromNLastDigits(int number, int n) {
    int newNumber = 0;
    for (int i = 0; i < n; i++) {
        int digit = number % 10;
        number /= 10;
        newNumber += pow(10, i) * digit;
    }

    return newNumber;
}

int pow(int base, int degree) {
    if(degree == 0) {
        return 1;
    }

    return base * pow(base, degree - 1);
}
