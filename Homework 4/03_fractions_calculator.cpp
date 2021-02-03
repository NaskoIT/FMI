/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 3
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

const int FRACTION_ARRAY_LENGTH = 2;
const char PLUS = '+';
const char MINUS = '-';
const char STAR = '*';
const char SLASH = '/';
const int FRACTION_MAX_NUMBER = 100000000;
const int FRACTION_MIN_NUMBER = -100000000;
const int SUCCESS_EXIT_CODE = 0;
const int ERROR_EXIT_CODE = -1;

long* calculate(long firstNumerator, long firstDenominator, long secondNumerator, long secondDenominator, char operand);

void sumFractions(
        long firstFraction[FRACTION_ARRAY_LENGTH],
        long secondFraction[FRACTION_ARRAY_LENGTH],
        int sign,
        long resultFraction[FRACTION_ARRAY_LENGTH]);

void multiplyFractions(
        long firstFraction[FRACTION_ARRAY_LENGTH],
        long secondFraction[FRACTION_ARRAY_LENGTH],
        long resultFraction[FRACTION_ARRAY_LENGTH]);

void divideFractions(
        long firstFraction[FRACTION_ARRAY_LENGTH],
        long secondFraction[FRACTION_ARRAY_LENGTH],
        long resultFraction[FRACTION_ARRAY_LENGTH]);

void printFraction(long fraction[FRACTION_ARRAY_LENGTH]);

void simplifyFraction(long fraction[FRACTION_ARRAY_LENGTH]);

long greatestCommonDivisor(long a, long b);

long leastCommonMultiple(long a, long b);

long getAbsoluteValue(long number);

void swap(long fraction[FRACTION_ARRAY_LENGTH]);

bool isInRange(long number);

bool isValidDenominator(long number);

int main() {
    long firstNumerator;
    cin >> firstNumerator;
    if(!isInRange(firstNumerator)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    long firstDenominator;
    cin >> firstDenominator;
    if(!isInRange(firstDenominator) || !isValidDenominator(firstDenominator)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    char operand;
    cin >> operand;
    if(!(operand == PLUS || operand == MINUS || operand == STAR || operand == SLASH)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    long secondNumerator;
    cin >> secondNumerator;
    if(!isInRange(secondNumerator)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    long secondDenominator;
    cin >> secondDenominator;
    if(!isInRange(secondDenominator) || !isValidDenominator(secondDenominator)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    if(operand == SLASH && (secondNumerator == 0 || secondDenominator == 0)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    long* result = calculate(firstNumerator, firstDenominator, secondNumerator, secondDenominator, operand);
    cout << result[0] << " " << result[1] << endl;
    delete[] result;

    return SUCCESS_EXIT_CODE;
}

long* calculate(long firstNumerator, long firstDenominator, long secondNumerator, long secondDenominator, char operand) {
    long firstFraction[FRACTION_ARRAY_LENGTH] = {firstNumerator, firstDenominator};
    long secondFraction[FRACTION_ARRAY_LENGTH] = {secondNumerator, secondDenominator};
    long* resultFraction = new long[FRACTION_ARRAY_LENGTH];

    simplifyFraction(firstFraction);
    simplifyFraction(secondFraction);

    switch (operand) {
        case PLUS:
            sumFractions(firstFraction, secondFraction, 1, resultFraction);
            break;
        case MINUS:
            sumFractions(firstFraction, secondFraction, -1, resultFraction);
            break;
        case STAR:
            multiplyFractions(firstFraction, secondFraction, resultFraction);
            break;
        case SLASH:
            divideFractions(firstFraction, secondFraction, resultFraction);
            break;
        default:
            break;
    }

    simplifyFraction(resultFraction);
    return resultFraction;
}

void sumFractions(
        long firstFraction[FRACTION_ARRAY_LENGTH],
        long secondFraction[FRACTION_ARRAY_LENGTH], int sign,
        long resultFraction[FRACTION_ARRAY_LENGTH]) {
    long lcm = leastCommonMultiple(firstFraction[1], secondFraction[1]);
    long firstMultiplier = lcm / firstFraction[1];
    long secondMultiplier = lcm / secondFraction[1];

    resultFraction[0] = firstFraction[0] * firstMultiplier + sign * secondFraction[0] * secondMultiplier;
    resultFraction[1] = lcm;
}

void multiplyFractions(
        long firstFraction[FRACTION_ARRAY_LENGTH],
        long secondFraction[FRACTION_ARRAY_LENGTH],
        long resultFraction[FRACTION_ARRAY_LENGTH]) {
    long firstNumeratorSecondDenominator[FRACTION_ARRAY_LENGTH] = {firstFraction[0], secondFraction[1]};
    simplifyFraction(firstNumeratorSecondDenominator);

    long firstDenominatorSecondNumerator[FRACTION_ARRAY_LENGTH] = {firstFraction[1], secondFraction[0]};
    simplifyFraction(firstDenominatorSecondNumerator);

    resultFraction[0] = firstNumeratorSecondDenominator[0] * firstDenominatorSecondNumerator[1];
    resultFraction[1] = firstDenominatorSecondNumerator[0] * firstNumeratorSecondDenominator[1];
}

void divideFractions(
        long firstFraction[FRACTION_ARRAY_LENGTH],
        long secondFraction[FRACTION_ARRAY_LENGTH],
        long resultFraction[FRACTION_ARRAY_LENGTH]) {
    swap(secondFraction);
    multiplyFractions(firstFraction, secondFraction, resultFraction);
}

void printFraction(long fraction[FRACTION_ARRAY_LENGTH]) {
    cout << fraction[0] << " " << fraction[1] << endl;
}

void simplifyFraction(long fraction[FRACTION_ARRAY_LENGTH]) {
    long gcd = getAbsoluteValue(greatestCommonDivisor(fraction[0], fraction[1]));
    fraction[0] /= gcd;
    fraction[1] /= gcd;

    if(fraction[0] < 0 && fraction[1] < 0) {
        fraction[0] = getAbsoluteValue(fraction[0]);
        fraction[1] = getAbsoluteValue(fraction[1]);
    }
    else if(fraction[0] >= 0 && fraction[1] < 0) {
        fraction[0] *= -1;
        fraction[1] *= -1;
    }
}

long greatestCommonDivisor(long a, long b) {
    if (b == 0) {
        return a;
    }

    return greatestCommonDivisor(b, a % b);

}

long leastCommonMultiple(long a, long b) {
    return (getAbsoluteValue(a * b)) / greatestCommonDivisor(a, b);
}

void swap(long fraction[FRACTION_ARRAY_LENGTH]) {
    long temp = fraction[0];
    fraction[0] = fraction[1];
    fraction[1] = temp;
}

long getAbsoluteValue(long number) {
    return number >= 0 ? number : -number;
}

bool isInRange(long number) {
    return number >= FRACTION_MIN_NUMBER && number <= FRACTION_MAX_NUMBER;
}

bool isValidDenominator(long number) {
    return number != 0;
}