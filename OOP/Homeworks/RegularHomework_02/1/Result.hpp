#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
private:
    Optional<T> element;
    Optional<Error> error;
    bool isInitialized;

public:
    Result();

    Result(const T &result);

    Result(const std::string &error_message);

    Optional<T> get_result() const;

    Optional<Error> get_error() const;

    bool operator==(const Error &other);

    bool operator==(const T &other);
};

template<typename T>
Result<T>::Result() {
    isInitialized = false;
}

template<typename T>
Result<T>::Result(const T &result) {
    isInitialized = true;
    element.set_value(result);
}

template<typename T>
Result<T>::Result(const std::string &error_message) {
    isInitialized = true;
    Error initError = Error(error_message);
    error.set_value(initError);
}

template<typename T>
bool Result<T>::operator==(const Error &other) {
    return !this->error.is_none();
}

template<typename T>
bool Result<T>::operator==(const T &other) {
    return !this->element.is_none();
}

template<typename T>
Optional<T> Result<T>::get_result() const {
    return element;
}

template<typename T>
Optional<Error> Result<T>::get_error() const {
    return error;
}
