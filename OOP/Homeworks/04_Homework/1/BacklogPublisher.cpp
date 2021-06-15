#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber * subscriber) {
    SimplePublisher::subscribe(subscriber);

    for (const Message & message : sentMessages) {
        subscriber->signal(message);
    }
}

