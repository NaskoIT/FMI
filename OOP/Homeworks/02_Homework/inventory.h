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

#ifndef INC_02_HOMEWORK_INVENTORY_H
#define INC_02_HOMEWORK_INVENTORY_H

#include <iostream>
#include "weapon.h"
#include "backpack.h"
#include "armor.h"
#include "weapon.h"
#include "material.h"
#include "money.h"
#include "equipment.h"

template<class T>
class Inventory {
    T element;

public:
    Inventory(const T &element);

    Inventory(const Inventory &inventory);

    Inventory &operator=(const Inventory &inventory);

    T getInventory() const;

    bool operator==(const Inventory &to) const;

    bool operator!=(const Inventory &to) const;

    friend ostream &operator<<(ostream &os, const Inventory<Equipment<Armor>> &inventory);

    friend ostream &operator<<(ostream &os, const Inventory<Equipment<Weapon>> &inventory);

    friend ostream &operator<<(ostream &os, const Inventory<Backpack<Material>> &inventory);

    friend ostream &operator<<(ostream &os, const Inventory<Backpack<Money>> &inventory);
};

template<class T>
Inventory<T>::Inventory(const T &initialElement) {
    this->element = initialElement;
}

template<class T>
Inventory<T>::Inventory(const Inventory &from) {
    this->element = from.element;
}

template<class T>
Inventory<T> &Inventory<T>::operator=(const Inventory &inventory) {
    if (this != inventory) {
        this->element = inventory.element;
    }

    return *this;
}

template<class T>
bool Inventory<T>::operator==(const Inventory &to) const {
    return this->inventory.getSize() == to.inventory.getSize();
}

template<class T>
bool Inventory<T>::operator!=(const Inventory &to) const {
    return this != to;
}

ostream &operator<<(ostream &os, const Inventory<Equipment<Weapon>> &inventory) {
    int size = inventory.getInventory().getSize();
    os << "Equipment inventory with weapons" << endl;

    for (int i = 0; i < size; i++) {
        Weapon weapon = inventory.getInventory().getAt(i);
        os << "Type: " << weapon.getType() << endl;
        os << "Kind: " << weapon.getKind() << endl;
        os << "Average hit damage: " << weapon.getHitDamage() << endl;
        os << "Score: " << weapon.getScore() << endl;
    }

    return os;
}

ostream &operator<<(ostream &os, const Inventory<Equipment<Armor>> &inventory) {
    int size = inventory.getInventory().getSize();
    os << "Equipment inventory with armors" << endl;

    for (int i = 0; i < size; i++) {
        Armor armor = inventory.getInventory().getAt(i);
        os << "Type: " << armor.getType() << endl;
        os << "Defense: " << armor.getDefense() << endl;
        os << "Gear score: " << armor.getGearScore() << endl;
    }

    return os;
}

ostream &operator<<(ostream &os, const Inventory<Backpack<Material>> &inventory) {
    int size = inventory.getInventory().getSize();
    os << "Backpack inventory with materials" << endl;

    for (int i = 0; i < size; i++) {
        Material material = inventory.getInventory().getAt(i);
        os << "Quantity: " << material.getQuantity() << endl;
    }

    return os;
}

ostream &operator<<(ostream &os, const Inventory<Backpack<Money>> &inventory) {
    int size = inventory.getInventory().getSize();
    os << "Backpack inventory with money" << endl;

    for (int i = 0; i < size; ++i) {
        Money money = inventory.getInventory().getAt(i);
        os << "Money: gold - " << money.getGold() << ", silver - " << money.getSilver() << endl;
    }

    return os;
}

template<class T>
T Inventory<T>::getInventory() const {
    return this->element;
}

#endif //INC_02_HOMEWORK_INVENTORY_H
