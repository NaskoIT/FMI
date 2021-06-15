#pragma once

// Add all other required methods and fields of the class.
using namespace std;

const int COORDINATES_COUNT = 4;

class Vector4D {
private:
    double coordinates[COORDINATES_COUNT];
public:

    Vector4D(double, double, double, double);

    double &operator[](int index);

    Vector4D &operator=(const Vector4D &);

    Vector4D operator+(const Vector4D &vector) const;

    Vector4D &operator+=(const Vector4D &vector);

    Vector4D operator-(const Vector4D &vector) const;

    Vector4D &operator-=(const Vector4D &vector);

    Vector4D operator*(const Vector4D &vector) const;

    Vector4D &operator*=(const Vector4D &vector);

    Vector4D operator*(const double scalar) const;

    Vector4D &operator*=(const double scalar);

    Vector4D operator/(const Vector4D &vector) const;

    Vector4D &operator/=(const Vector4D &vector);

    bool operator==(const Vector4D &vector) const;

    bool operator!=(const Vector4D &vector) const;

    bool operator<(const Vector4D &vector) const;

    bool operator<=(const Vector4D &vector) const;

    bool operator>(const Vector4D &vector) const;

    bool operator>=(const Vector4D &vector) const;

    bool operator!() const;

    Vector4D operator-() const;

    void print() const;
};
