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

void Person::printPerson() const {
    cout << "Name: " << name << endl;
    cout << "EGN: " << egn << endl;
}

Person::~Person() {
    cout << "~Person(): " << " Name: " << name << " EGN: " << egn << endl;
    delete[] name;
    delete[] egn;
}