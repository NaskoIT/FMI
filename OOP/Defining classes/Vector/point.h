#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y;

public:
    Point() {
        x = y = 0;
    };

    Point(double, double);

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void print() const;

    double distance(Point) const;

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    void offset(double, double);

};

#endif // POINT_H