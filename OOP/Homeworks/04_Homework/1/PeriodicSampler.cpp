#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) : Subscriber(id) {
    this->period = period;
}

int PeriodicSampler::read() const {
    if (messages.empty()) {
        return 0;
    }

    for (int i = messages.size() - 1; i >= 0; i--) {
        if (i % period == 0) {
            return messages[i].data;
        }
    }

    return 0;
}

Subscriber *PeriodicSampler::clone() const {
    return new PeriodicSampler(*this);
}

