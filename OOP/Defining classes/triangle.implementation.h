#include <iostream>
#include "triangle.h"

void Triangle::setPoints(const Point &a, const Point &b, const Point &c) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->sideA = a.getDist(b);
    this->sideB = b.getDist(c);
    this->sideC = c.getDist(a);
}

TriangleType Triangle::typeOfTriangle() const {
    if (sideA == sideB && sideB == sideC) {
        return Еquilateral;
    } else if (sideA == sideB || sideC == sideB || sideA == sideC) {
        return Isosceles;
    } else {
        return Versatile;
    }
}

bool Triangle::validTriangle() const {
    return (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA);
}
