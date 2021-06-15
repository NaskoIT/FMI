#pragma once
#ifndef INC_04_HOMEWORK_SUBSCRIBER_H
#define INC_04_HOMEWORK_SUBSCRIBER_H

#include <string>
#include <vector>
#include "Message.hpp"

using namespace std;

class Subscriber {
protected:
    vector<Message> messages;

public:
    const string id;

    Subscriber(string id);

    void signal(Message message);

    virtual int read() const = 0;

    virtual Subscriber *clone() const = 0;

    virtual ~Subscriber() = default;
};


#endif //INC_04_HOMEWORK_SUBSCRIBER_H
