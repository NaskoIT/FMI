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

#include "money.h"

const int SILVER_MAX_VALUE = 100;

Money::Money() {
    quantity = 0;
}

Money::Money(int initialQuantity) {
    quantity = initialQuantity;
}

int Money::getSilver() const {
    this->quantity % SILVER_MAX_VALUE;
}

int Money::getGold() const {
    return this->quantity / SILVER_MAX_VALUE;
}

void Money::addMoney(int money) {
    quantity += money;
}

bool Money::removeMoney(int money) {
    if (quantity - money < 0) {
        return false;
    }

    quantity -= money;
    return true;
}

