#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max) : Counter() {
    maxValue = max;
}

LimitedCounter::LimitedCounter(int max, int initial) : Counter(initial) {
    maxValue = max;
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned int step) : Counter(initial, step) {
    maxValue = max;
}

void LimitedCounter::increment() {
    int newValue = step + value;
    if (newValue > maxValue) {
        return;
    }

    Counter::increment();
}

int LimitedCounter::getMax() const {
    return maxValue;
}

