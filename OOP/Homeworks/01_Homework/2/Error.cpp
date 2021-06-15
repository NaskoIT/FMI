#include <cstring>
#include "Error.hpp"

bool Error::hasMessage() const {
    return message != nullptr;
}

const char *Error::getMessage() const {
    return message;
}

ErrorType Error::getType() const {
    return type;
}

Error::Error(ErrorType type, const char *newMessage) {
    setFields(type, newMessage);
}

void Error::setFields(const ErrorType &type, const char *newMessage) {
    if (newMessage != nullptr) {
        message = new char[strlen(newMessage) + 1];
        strcpy(message, newMessage);
    } else {
        message = nullptr;
    }

    Error::type = type;
}

Error Error::newNone() {
    return Error(ErrorType::None, nullptr);
}

Error Error::newBuildFailed(const char *message) {
    return Error(ErrorType::BuildFailed, message);
}

Error Error::newWarning(const char *message) {
    return Error(ErrorType::Warning, message);
}

Error Error::newFailedAssertion(const char *message) {
    return Error(ErrorType::FailedAssertion, message);
}

Error::~Error() {
    if (message != nullptr) {
        delete[] message;
    }
}

Error &Error::operator=(const Error &error) {
    if (this != &error) {
        if (this->message != nullptr) {
            delete[] this->message;
        }

        setFields(error.type, error.message);
    }

    return *this;
}

Error::Error() {
    message = nullptr;
    type = ErrorType::None;
}

Error::Error(const Error &error) {
    setFields(error.type, error.message);
}

