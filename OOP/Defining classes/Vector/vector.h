#include "point.h"

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    Point start;
    Point end;
public:
    Vector(Point, Point);

    Point getStart() const {
        return start;
    }

    Point getEnd() const {
        return end;
    }

    void print() const;

    double length() const;

    void setStart(Point a) {
        start = a;
    }

    void setEnd(Point b) {
        end = b;
    }

    void offset(double, double);
};

#endif // VECTOR_H