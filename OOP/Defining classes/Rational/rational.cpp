#include "rational.h"

#include <iostream>

using namespace std;

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int n, int d) {
    if (n == 0 || d == 0) {
        numerator = 0;
        denominator = 1;
    }
    else {
        int g = gcd(abs(n), abs(d));
        if (n > 0 && d > 0 || n < 0 && d < 0) {
            numerator = abs(n) / g;
            denominator = abs(d) / g;
        }
        else {
            numerator = -abs(n) / g;
            denominator = abs(d) / g;
        }
    }
}

int Rational::getNumerator() const {
    return numerator;
}

int Rational::getDenominator() const {
    return denominator;
}

void Rational::print() const {
    cout << getNumerator() << '/' << getDenominator();
}

int Rational::gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

Rational add(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getDenominator()
                    + p.getDenominator() * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

Rational subtract(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getDenominator()
                    - p.getDenominator() * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

Rational multiply(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

Rational divide(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getDenominator(),
                    p.getDenominator() * q.getNumerator());
}