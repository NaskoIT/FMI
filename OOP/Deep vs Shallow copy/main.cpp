#include <iostream>
#include "person.implementation.h"

using namespace std;

void deepCopyDemo() {
    Car car = Car(10000);

    string name = "Peter";
    Person dude = Person(name, &car);
    Person* copiedDude = dude.deepCopy();

    cout << dude.toString() << endl;
    cout << copiedDude->toString() << endl;

    string newName = "Ivan";
    dude.setName(newName);
    dude.getCar()->setPrice(5000);

    cout << "First object was modified!" << endl;

    cout << dude.toString() << endl;
    cout << copiedDude->toString() << endl;
}

void shallowCopyDemo() {
    Car car = Car(10000);

    string name = "Peter";
    Person dude = Person(name, &car);
    Person* copiedDude = dude.shallowCopy();

    cout << dude.toString() << endl;
    cout << copiedDude->toString() << endl;

    string newName = "Ivan";
    dude.setName(newName);
    dude.getCar()->setPrice(5000);

    cout << "First object was modified!" << endl;

    cout << dude.toString() << endl;
    cout << copiedDude->toString() << endl;
}

void printPersonCarPrice(Person person) {
    cout << person.getCar()->getPrice() << endl;
    cout << "modify person car price" << endl;
    person.getCar()->setPrice(7500);
}

void methodCopyDemo() {
    Car car = Car(10000);

    string name = "Peter";
    Person dude = Person(name, &car);

    cout << "Car price before execute printPersonCarPrice " << dude.getCar()->getPrice() << endl;
    printPersonCarPrice(dude);
    cout << "Car price after execute printPersonCarPrice " << dude.getCar()->getPrice() << endl;
}

void printPersonName(Person person) {
    cout << person.getName() << endl;
    cout << "modify person name" << endl;
    string newName = "Test";
    person.setName(newName);
}

void passClassToMethodDemo() {
    Car car = Car(10000);

    string name = "Peter";
    Person dude = Person(name, &car);

    cout << "Person name before execute printPersonName " << dude.getName() << endl;
    printPersonName(dude);
    cout << "Person name after execute printPersonName " << dude.getName() << endl;
}

int main() {
    passClassToMethodDemo();
}
