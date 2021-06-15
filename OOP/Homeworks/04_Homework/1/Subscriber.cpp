#include "Subscriber.h"

Subscriber::Subscriber(string id) : id(id) {
}

void Subscriber::signal(Message message) {
    this->messages.push_back(message);
}
