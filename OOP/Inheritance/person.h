#pragma once;

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    char *name;
    char *egn;

    void copy(char *newName, char *newEgn);

public:
    Person(char * = "", char * = "");

    Person(const Person &);

    Person &operator=(const Person &person);

    void printPerson() const;

    ~Person();
};