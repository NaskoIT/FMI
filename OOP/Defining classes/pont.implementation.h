#include "point.h"
#include <iostream>
#include <cmath>

using namespace std;

void Point::setXAndY() {
    std::cin >> x >> y;
}

void Point::print() const {
    std::cout << "(" << x << "," << y << ")";
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getDist(const Point &p) const {
    double result;
    result = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    return result;
}