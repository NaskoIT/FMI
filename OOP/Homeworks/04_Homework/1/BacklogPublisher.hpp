#pragma once

#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "SimplePublisher.hpp"

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as 
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// BacklogPublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
// Also it keeps a backlog of previous messages so when a new
// Subscriber subscribes, the Publisher replays all
// backlogged messages to the new Subscriber
class BacklogPublisher : public SimplePublisher {
public:
    // subscribe registers a Subscriber to start receiving messages
    // The new subscriber should receive all previous messages
    void subscribe(Subscriber *);
};
