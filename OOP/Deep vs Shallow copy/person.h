#include "string"
#include "car.implementation.h"

using namespace std;

class Person {
private:
    string name;
    Car *car;

public:
    Person(string &, Car *);

    string getName();

    void setName(string &);

    Car *getCar();

    void setCar(Car *);

    Person *deepCopy();

    Person *shallowCopy();

    string toString();
};