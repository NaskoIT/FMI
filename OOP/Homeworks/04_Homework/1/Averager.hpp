#pragma once

#include "Message.hpp"
#include "Subscriber.h"
#include <string>
#include <vector>

using namespace std;

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as 
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// Averager is a type of Subscriber, which saves data and
// returns the average of the data when `read()` is called.
// Data is provided with the `signal()` method.
// Average of N numbers = sum(all numbers) / N
class Averager : public Subscriber {
public:
    Averager(std::string id);

    // read calculates the average of all data points provided so far
    // returns 0 if there's no data points
    int read() const override;

    Subscriber *clone() const override;
};
