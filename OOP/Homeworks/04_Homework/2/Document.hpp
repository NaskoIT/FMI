#pragma once

#include "Object.hpp"
#include <vector>
#include <iostream>

using namespace std;

const int START_LINE = 0;

class Document : public Object {
private:
    vector<string> lines;
    unsigned int currentLine;

public:
    Document(const string &name, const string &location, const string &extension);

    void write_line(const string &line);

    std::string read_line();

    std::string read_line(const unsigned line);

    bool operator==(const Comparable *comparable) const override;

    bool operator!=(const Comparable *comparable) const override;

    string to_string() const override;

    void from_string(const string &input) override;

    string debug_print() const override;
};
