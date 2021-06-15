
#include "Request.hpp"

int Request::counter = 0;

Request::Request(const string &message, const string &sender) {
    counter++;

    id = counter;
    this->message = message;
    this->sender = sender;
}

string Request::getMessage() const {
    return message;
}

string Request::getSender() const {
    return sender;
}

int Request::getCount() {
    return counter;
}

int Request::getID() const {
    return id;
}


