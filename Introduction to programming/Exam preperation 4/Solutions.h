#include <cmath>

using namespace std;

// task 1
struct Point {
    int x;
    int y;
};

int getSideLength(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool CheckRectangular(const Point &a, const Point &b, const Point &c) {
    if ((a.x == b.x && b.x == c.x) || (a.y == b.y && b.y == c.y)) {
        return false;
    }

    int sideA = getSideLength(c, b);
    int sideB = getSideLength(a, c);
    int sideC = getSideLength(a, b);

    if (((sideA + sideB) == sideC) || ((sideA + sideC) == sideB) || ((sideB + sideC) == sideA)) {
        return true;
    }

    return false;
}

// task 2
int parseDigit(char digit) {
    return digit - '0';
}

// equation = а*х^2+b*x+c=0
double Solve(const char *const equation) {
    int a = parseDigit(equation[0]);
    int b = parseDigit(equation[7]);
    int c = parseDigit(equation[11]);

    int d = b * b - 4 * a * c;
    double sqrtD = sqrt(d);
    double x = (-b + sqrtD) / (2 * a);
    return x;
}

// task 3
const int DIGITS_COUNT = 10;

int *Extract(const int number) {
    int digitsOccurrences[DIGITS_COUNT] = {};
    int tempNumber = number >= 0 ? number : -number;
    int mostFrequentDigitCount = 0;

    while (tempNumber != 0) {
        int digit = tempNumber % 10;
        digitsOccurrences[digit]++;
        if (digitsOccurrences[digit] > mostFrequentDigitCount) {
            mostFrequentDigitCount = digitsOccurrences[digit];
        }

        tempNumber /= 10;
    }

    int targetDigitsCount = 0;
    for (int i = 0; i < DIGITS_COUNT; ++i) {
        if (digitsOccurrences[i] == mostFrequentDigitCount) {
            targetDigitsCount++;
        }
    }

    int *targetDigits = new int[targetDigitsCount + 1];
    int index = 0;
    for (int i = 0; i < DIGITS_COUNT; ++i) {
        if (digitsOccurrences[i] == mostFrequentDigitCount) {
            targetDigits[index++] = i;
        }
    }

    targetDigits[targetDigitsCount] = -1;
    return targetDigits;
}