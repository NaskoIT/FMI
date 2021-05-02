#include <cstring>
#include "./person.h"

const int EGN_LENGTH = 11;

Person::Person(char *initName, char *initEgn) {
    cout << "Person constructor was invoked: " << "Name: " << initName << " EGN: " << initEgn << endl;
    copy(initName, initEgn);
}

Person::Person(const Person &person) {
    copy(person.name, person.egn);
}

void Person::printPerson() const {
    cout << "Name: " << name << endl;
    cout << "EGN: " << egn << endl;
}

Person::~Person() {
    cout << "~Person(): " << " Name: " << name << " EGN: " << egn << endl;
    delete[] name;
    delete[] egn;
}

Person &Person::operator=(const Person &person) {
    if (this != &person) {
        delete[] name;
        delete[] egn;
        copy(person.name, person.egn);
    }

    return *this;
}

void Person::copy(char *newName, char *newEgn) {
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
    egn = new char[EGN_LENGTH];
    strcpy(egn, newEgn);
}
