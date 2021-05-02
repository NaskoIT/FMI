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

    void printPerson() const;

    ~Person();
};