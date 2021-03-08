#include <iostream>
#include "rational.h"

using namespace std;

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

void Rational::print() {
    cout << this->numerator << "/" << this->denominator << endl;
}

int Rational::getNumerator() const {
    return this->numerator;
}

int Rational::getDenominator() const {
    return this->denominator;
}

Rational Rational::add(Rational r) {
    return Rational(this->getNumerator() * r.getDenominator()
                    + this->getDenominator() * r.getNumerator(),
                    this->getDenominator() * r.getDenominator());
}

int main() {
    Rational r = Rational();
    r.print();

    Rational s = Rational(1, 2);
    s.print();

    cout << s.getNumerator() << "/" << s.getDenominator() << endl;

    Rational result = s.add(Rational(1, 3));
    result.print();
}
