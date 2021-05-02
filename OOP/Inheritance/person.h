#pragma once;

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    char *name;
    char *egn;

public:
    Person(char * = "", char * = "");

    Person(const Person &);

    void printPerson() const;

    ~Person();
};