#include "car.h"

using namespace std;

Car::Car(double newPrice) {
    this->setPrice(newPrice);
}

double Car::getPrice() const {
    return this->price;
}

void Car::setPrice(double newPrice) {
    if(price < 0) {
        // TODO: throw exception
    }

    this->price = newPrice;
}

Car* Car::clone() {
    return new Car(this->getPrice());
}

Car::Car() {}
