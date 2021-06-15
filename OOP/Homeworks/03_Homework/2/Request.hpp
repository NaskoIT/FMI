#ifndef INC_03_HOMEWORK_REQUEST_HPP
#define INC_03_HOMEWORK_REQUEST_HPP

#include <string>

using namespace std;

class Request {
private:
    string message;
    string sender;
    int id;
    static int counter;

public:
    Request(const string &message, const string &sender);

    string getMessage() const;

    string getSender() const;

    static int getCount();

    int getID() const;
};

#endif //INC_03_HOMEWORK_REQUEST_HPP
