#include <cstring>
#include "./person.h"

const int EGN_LENGTH = 11;

Person::Person(char *initName, char *initEgn) {
    cout << "Person constructor was invoked: " << "Name: " << initName << " EGN: " << initEgn << endl;
    name = new char[strlen(initName) + 1];
    strcpy(name, initName);
    egn = new char[EGN_LENGTH];
    strcpy(egn, initEgn);
}

Person::Person(const Person &person) {
    name = new char[strlen(person.name) + 1];
    strcpy(name, person.name);
    egn = new char[EGN_LENGTH];
    strcpy(egn, person.egn);
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
