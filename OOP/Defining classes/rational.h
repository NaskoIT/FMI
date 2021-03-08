struct Rational {
private:
    int numerator;
    int denominator;

public:
    Rational();

    Rational(int, int);

    void print();

    int getNumerator() const;

    int getDenominator() const;

    Rational add(Rational);
};
