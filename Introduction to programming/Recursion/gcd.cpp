#include <iostream>

using namespace std;

int gcd(int firstNumber, int secondNumber);

int main() {
    int firstNumber;
    cin >> firstNumber;
    int secondNumber;
    cin >> secondNumber;

    cout << gcd(firstNumber, secondNumber);
}

int gcd(int firstNumber, int secondNumber) {
    if (firstNumber <= 1 || secondNumber <= 1) {
        return 1;
    } else if (firstNumber == secondNumber) {
        return firstNumber;
    } else if (firstNumber > secondNumber) {
        return gcd(firstNumber - secondNumber, secondNumber);
    } else {
        return gcd(firstNumber, secondNumber - firstNumber);
    }
}