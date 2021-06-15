#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscriber *subscriber) {
    subscribers.push_back(subscriber);
}

void SimplePublisher::unsubscribe(Subscriber *subscriber) {
    for (int i = 0; i < subscribers.size(); ++i) {
        if (subscribers[i]->id == subscriber->id) {
            this->subscribers.erase(this->subscribers.begin() + i);
            return;
        }
    }
}

void SimplePublisher::signal(Message message) {
    for (Subscriber *subscriber : subscribers) {
        subscriber->signal(message);
    }

    sentMessages.push_back(message);
}

