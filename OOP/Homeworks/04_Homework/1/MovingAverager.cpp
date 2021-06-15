#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize) : Subscriber(id) {
    this->windowSize = windowSize;
}

int MovingAverager::read() const {
    if (messages.size() == 0) {
        return 0;
    } else if (messages.size() < windowSize) {
        int points = 0;
        for (int i = 0; i < messages.size(); i++) {
            points += messages[i].data;
        }

        return points / messages.size();
    }

    int totalPoints = 0;
    int startIndex = messages.size() - 1;
    int endIndex = messages.size() - windowSize;
    for (int i = startIndex; i >= endIndex; i--) {
        totalPoints += messages[i].data;
    }

    return totalPoints / windowSize;
}

Subscriber *MovingAverager::clone() const {
    return new MovingAverager(*this);
}

