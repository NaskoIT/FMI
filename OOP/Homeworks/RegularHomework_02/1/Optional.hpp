#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template<typename T>

class Optional {
    T element;
    bool isInitialized;
public:
    Optional();

    Optional(const T &value);

    bool is_none() const;

    void set_value(const T &value);

    T get_value() const;
};

template<typename T>
Optional<T>::Optional() {
    isInitialized = false;
    element = T();
}

template<typename T>
Optional<T>::Optional(const T &value) {
    set_value(value);
}

template<typename T>
bool Optional<T>::is_none() const {
    return !isInitialized;
}

template<typename T>
T Optional<T>::get_value() const {
    return element;
}

template<typename T>
void Optional<T>::set_value(const T &value) {
    isInitialized = true;
    element = value;
}
