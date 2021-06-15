#include "Counter.hpp"

Counter::Counter() {
    value = 0;
    step = 1;
}

Counter::Counter(int initial) {
    value = initial;
    step = 1;
}

Counter::Counter(int initial, unsigned int step) {
    value = initial;
    this->step = step;
}

void Counter::increment() {
    value += step;
}

int Counter::getTotal() const {
    return value;
}

unsigned int Counter::getStep() const {
    return step;
}
