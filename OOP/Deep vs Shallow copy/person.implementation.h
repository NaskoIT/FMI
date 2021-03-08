#include "string"
#include "person.h"

using namespace std;

Person::Person(string &name, Car *car) {
    this->setName(name);
    this->setCar(car);
}


void Person::setName(string &newName) {
    this->name = newName;
}

string Person::getName() {
    return this->name;
}

Car *Person::getCar() {
    return this->car;
}

void Person::setCar(Car *newCar) {
    this->car = newCar;
}

Person* Person::deepCopy() {
    Car* copiedCar = this->car->clone();
    return new Person(this->name, copiedCar);
}

Person* Person::shallowCopy() {
    return new Person(this->name, this->car);
}

string Person::toString() {
    double carPrice = this->getCar()->getPrice();
    return "My name is: " + this->name + " and my car costs: " + to_string(carPrice);
}
