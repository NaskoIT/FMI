#pragma once

#include <string>

using namespace std;

class Error {
private:
    string message;

public:
    Error(const std::string &message = "");

    std::string get_message() const;
};
