#include "Averager.hpp"

Averager::Averager(std::string id) : Subscriber(id) {
}

int Averager::read() const {
    if (messages.size() == 0) {
        return 0;
    }

    int points = 0;
    int readMessages = 0;
    for (const Message &message : messages) {
        points += message.data;
        readMessages++;
    }

    int result = points / readMessages;
    return result;
}

Subscriber *Averager::clone() const {
    return new Averager(*this);
}

