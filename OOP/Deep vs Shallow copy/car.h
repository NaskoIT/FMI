class Car {
private:
    double price;

public:
    Car(double);

    Car();

    double getPrice() const;

    void setPrice(double);

    Car* clone();
};
