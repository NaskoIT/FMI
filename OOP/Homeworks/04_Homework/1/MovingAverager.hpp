#pragma once

#include "Message.hpp"
#include "Averager.hpp"
#include <string>

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// MovingAverager is a type of Subscriber, which saves data
// and returns the average of the last `windowSize` number of
// data points when `read()` is called.
// Data is provided with the `signal()` method.
// Average of N numbers = sum(all numbers) / N
class MovingAverager : public Subscriber {
public:
    MovingAverager(std::string id, size_t windowSize);

    // windowSize specifies how many most-recent data points
    // should be saved
    // Should never be changed once initialized
    size_t windowSize;

    // signal adds a new data point
    // Remember, you only need the last windowSize number of
    // data points added, older data points should be ignored
    int read() const override;

    Subscriber *clone() const override;
};
