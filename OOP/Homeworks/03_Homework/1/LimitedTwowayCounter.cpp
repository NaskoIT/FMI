#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max)
        : Counter(),
          TwowayCounter(),
          LimitedCounter(max) {
    minValue = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial)
        : Counter(initial),
          TwowayCounter(initial),
          LimitedCounter(max, initial) {
    minValue = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned int step)
        : Counter(initial, step),
          TwowayCounter(initial, step),
          LimitedCounter(max, initial, step) {
    minValue = min;
}

void LimitedTwowayCounter::decrement() {
    int newValue = value - step;
    if (newValue < minValue) {
        return;
    }

    TwowayCounter::decrement();
}

int LimitedTwowayCounter::getMin() const {
    return minValue;
}

