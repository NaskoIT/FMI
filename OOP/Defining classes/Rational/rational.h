#pragma once

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
    int numerator, denominator;

    int gcd(int, int);

public:
    Rational();

    Rational(int, int);

    int getNumerator() const;

    int getDenominator() const;

    void print() const;
};

Rational add(Rational, Rational);

Rational subtract(Rational, Rational);

Rational multiply(Rational, Rational);

Rational divide(Rational, Rational);

#endif
