/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Atanas Vasilev
* @idnumber 62577
* @task 1
* @compiler GCC
*/

#ifndef INC_02_HOMEWORK_BACKPACK_H
#define INC_02_HOMEWORK_BACKPACK_H

#include <vector>
#include "material.h"
#include "money.h"

using namespace std;

const int DEFAULT_MAX_BACKPACK_SLOTS = 16;

template<class T>
class Backpack {
private:
    vector<T> elements;
    const int maxSlots;

public:
    Backpack();

    bool isEmpty();

    bool isFull();

    void clear();

    bool add(const T &element);

    void remove(const T &element);

    int getSize() const;

    T getAt(int index) const;
};

template<class T>
Backpack<T>::Backpack() : maxSlots(DEFAULT_MAX_BACKPACK_SLOTS) {
}

template<class T>
bool Backpack<T>::isEmpty() {
    return elements.empty();
}

template<class T>
bool Backpack<T>::isFull() {
    elements.size() >= maxSlots;
}

template<>
bool Backpack<Money>::isFull() {
    return false;
}

template<>
bool Backpack<Material>::isFull() {
    if (elements.size() < maxSlots) {
        return false;
    }

    for (const Material &material : elements) {
        if (!material.isFull()) {
            return false;
        }
    }

    return true;
}

template<class T>
void Backpack<T>::clear() {
    elements.clear();
}

template<class T>
bool Backpack<T>::add(const T &element) {
    if (isFull()) {
        return false;
    }

    elements.push_back(element);
    return true;
}

template<class T>
void Backpack<T>::remove(const T &element) {
    for (int i = 0; i < element.size(); ++i) {
        if(elements[i] == element) {
            elements.erase(elements.begin() + i);
            return;
        }
    }
}

template<class T>
int Backpack<T>::getSize() const {
    return elements.size();
}

template<class T>
T Backpack<T>::getAt(int index) const {
    return this->elements[index];
}

#endif //INC_02_HOMEWORK_BACKPACK_H
