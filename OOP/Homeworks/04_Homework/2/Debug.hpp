#pragma once

#include <string>

using namespace std;

class Debug {
public:
    virtual string debug_print() const = 0;
};