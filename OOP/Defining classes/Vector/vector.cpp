#include <iostream>

using namespace std;

#include "vector.h"

Vector::Vector(Point a, Point b)
{
    start = a;
    end = b;
}

void Vector::print() const
{
    start.print();
    cout << " -> ";
    end.print();
}

double Vector::length() const
{
    return start.distance(end);
}

void Vector::offset(double offsetX, double offsetY)
{
    start.offset(offsetX, offsetY);
    end.offset(offsetX, offsetY);
}
