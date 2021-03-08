class Point {
private:
    double x;
    double y;
public:
    void setXAndY();

    void print() const;

    double getX() const;

    double getY() const;

    double getDist(const Point &p) const;
};
