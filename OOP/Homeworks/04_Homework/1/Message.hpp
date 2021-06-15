#pragma once

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as 
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// Message is an abstraction over a simple data point, which
// is sent from a Publisher to a Subscriber
class Message {
public:
    Message(int data);

    // data is the data point encapsulated in the message
    // Should never be changed once initialized
    const int data;
};
