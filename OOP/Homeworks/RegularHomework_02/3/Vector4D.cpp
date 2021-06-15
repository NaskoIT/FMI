#include <iostream>
#include "Vector4D.hpp"

using namespace std;

Vector4D::Vector4D(double a, double b, double c, double d) {
    coordinates[0] = a;
    coordinates[1] = b;
    coordinates[2] = c;
    coordinates[3] = d;
}

Vector4D &Vector4D::operator=(const Vector4D &other) {
    if (*this == other) {
        return *this;
    }

    for (int i = 0; i < COORDINATES_COUNT; i++) {
        this->coordinates[i] = other.coordinates[i];
    }

    return *this;
}

double &Vector4D::operator[](int index) {
    return coordinates[index];
}

Vector4D Vector4D::operator+(const Vector4D &vector) const {
    return Vector4D(
            this->coordinates[0] + vector.coordinates[0],
            this->coordinates[1] + vector.coordinates[1],
            this->coordinates[2] + vector.coordinates[2],
            this->coordinates[3] + vector.coordinates[3]);
}

Vector4D &Vector4D::operator+=(const Vector4D &vector) {
    for (int i = 0; i < COORDINATES_COUNT; ++i) {
        this->coordinates[i] += vector.coordinates[i];
    }

    return *this;
}

Vector4D Vector4D::operator-(const Vector4D &vector) const {
    return Vector4D(
            this->coordinates[0] - vector.coordinates[0],
            this->coordinates[1] - vector.coordinates[1],
            this->coordinates[2] - vector.coordinates[2],
            this->coordinates[3] - vector.coordinates[3]);
}

Vector4D &Vector4D::operator-=(const Vector4D &vector) {
    for (int i = 0; i < COORDINATES_COUNT; ++i) {
        this->coordinates[i] -= vector.coordinates[i];
    }

    return *this;
}

Vector4D Vector4D::operator*(const Vector4D &vector) const {
    return Vector4D(
            this->coordinates[0] * vector.coordinates[0],
            this->coordinates[1] * vector.coordinates[1],
            this->coordinates[2] * vector.coordinates[2],
            this->coordinates[3] * vector.coordinates[3]);
}

Vector4D &Vector4D::operator*=(const Vector4D &vector) {
    for (int i = 0; i < COORDINATES_COUNT; ++i) {
        this->coordinates[i] *= vector.coordinates[i];
    }

    return *this;
}

Vector4D Vector4D::operator*(const double scalar) const {
    return Vector4D(
            this->coordinates[0] * scalar,
            this->coordinates[1] * scalar,
            this->coordinates[2] * scalar,
            this->coordinates[3] * scalar);
}

Vector4D &Vector4D::operator*=(const double scalar) {
    for (int i = 0; i < COORDINATES_COUNT; ++i) {
        this->coordinates[i] *= scalar;
    }

    return *this;
}

Vector4D Vector4D::operator/(const Vector4D &vector) const {
    return Vector4D(
            this->coordinates[0] / vector.coordinates[0],
            this->coordinates[1] / vector.coordinates[1],
            this->coordinates[2] / vector.coordinates[2],
            this->coordinates[3] / vector.coordinates[3]);
}

Vector4D &Vector4D::operator/=(const Vector4D &vector) {
    for (int i = 0; i < COORDINATES_COUNT; ++i) {
        if (vector.coordinates[i] == 0) {
            continue;
        }

        this->coordinates[i] /= vector.coordinates[i];
    }

    return *this;
}

bool Vector4D::operator==(const Vector4D &vector) const {
    for (int i = 0; i < COORDINATES_COUNT; ++i) {
        if (this->coordinates[i] != vector.coordinates[i]) {
            return false;
        }
    }

    return true;
}

bool Vector4D::operator!=(const Vector4D &vector) const {
    return !(*this == vector);
}

bool Vector4D::operator<(const Vector4D &vector) const {
    for (int i = 0; i < COORDINATES_COUNT; ++i) {
        if (this->coordinates[i] < vector.coordinates[i]) {
            return true;
        } else if (this->coordinates[i] > vector.coordinates[i]) {
            return false;
        }
    }

    return false;
}

bool Vector4D::operator<=(const Vector4D &vector) const {
    return *this < vector || *this == vector;
}

bool Vector4D::operator>(const Vector4D &vector) const {
    for (int i = 0; i < COORDINATES_COUNT; ++i) {
        if (this->coordinates[i] > vector.coordinates[i]) {
            return true;
        } else if (this->coordinates[i] < vector.coordinates[i]) {
            return false;
        }
    }

    return false;
}

bool Vector4D::operator>=(const Vector4D &vector) const {
    return *this > vector || *this == vector;
}

bool Vector4D::operator!() const {
    for (int i = 0; i < COORDINATES_COUNT; ++i) {
        if (coordinates[i] != 0) {
            return false;
        }
    }

    return true;
}

Vector4D Vector4D::operator-() const {
    return Vector4D(
            -this->coordinates[0],
            -this->coordinates[1],
            -this->coordinates[2],
            -this->coordinates[3]);
}

void Vector4D::print() const {

    for (int i = 0; i < COORDINATES_COUNT; i++) {
        cout << this->coordinates[i] << " ";
    }

    cout << std::endl;
}
