
#include "Semaphore.hpp"

Semaphore::Semaphore() : LimitedTwowayCounter(0, 1, 0, 1) {}

Semaphore::Semaphore(int isAvailable) : LimitedTwowayCounter(0, 1, (int) isAvailable, 1) {}

bool Semaphore::isAvailable() const {
    return value > 0;
}

void Semaphore::wait() {
    LimitedTwowayCounter::decrement();
}

void Semaphore::signal() {
    LimitedTwowayCounter::increment();
}

