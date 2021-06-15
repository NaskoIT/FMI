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

#ifndef INC_02_HOMEWORK_EQUIPMENT_H
#define INC_02_HOMEWORK_EQUIPMENT_H

#include <vector>
#include "weapon.h"

using namespace std;

const int DEFAULT_MAX_EQUIPMENT_SLOTS = 24;

template<class T>
class Equipment {
private:
    vector<T> elements;
    const int maxSlots;

public:
    Equipment();

    bool isEmpty();

    bool isFull();

    bool clear();

    bool add(const T &element);

    int getSize() const;

    T getAt(int index);
};

template<class T>
bool Equipment<T>::isEmpty() {
    return elements.empty();
}

template<class T>
bool Equipment<T>::isFull() {
    elements.size() >= maxSlots;
}

template<>
bool Equipment<Weapon>::isFull() {
    int occupiedSlots = 0;
    for (const Weapon &weapon : elements) {
        occupiedSlots++;
        if (weapon.getType() == WeaponType::twoHanded) {
            occupiedSlots++;
        }
    }

    return occupiedSlots >= maxSlots;
}

template<class T>
bool Equipment<T>::clear() {
    elements.clear();
}

template<class T>
bool Equipment<T>::add(const T &element) {
    if (isFull()) {
        return false;
    }

    elements.push_back(element);
    return true;
}

template<class T>
Equipment<T>::Equipment() : maxSlots(DEFAULT_MAX_EQUIPMENT_SLOTS) {
}

template<class T>
int Equipment<T>::getSize() const {
    return this->elements.size();
}

template<class T>
T Equipment<T>::getAt(int index) {
    return this->elements[index];
}

#endif //INC_02_HOMEWORK_EQUIPMENT_H
