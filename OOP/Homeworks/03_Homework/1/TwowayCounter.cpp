#include "TwowayCounter.hpp"

void TwowayCounter::decrement() {
    value -= step;
}

TwowayCounter::TwowayCounter() : Counter() {}

TwowayCounter::TwowayCounter(int initial) : Counter(initial) {}

TwowayCounter::TwowayCounter(int initial, unsigned int step) : Counter(initial, step) {}

