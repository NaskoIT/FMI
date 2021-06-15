#pragma once

#include <iostream>

using namespace std;

class Serializable {
public:
    virtual string to_string() const = 0;

    virtual void from_string(const string &input) = 0;
};