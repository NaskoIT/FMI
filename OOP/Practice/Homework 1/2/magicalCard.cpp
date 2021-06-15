/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 2
* @compiler GCC
*/

#include "magicalCard.hpp"

MagicalCard::MagicalCard(char *name, char *effect, MagicalCardType type) {
    this->name = name;
    this->effect = effect;
    this->type = type;
    this->isConfigured = true;
}

MagicalCard::MagicalCard() {
    this->isConfigured = false;
}

bool MagicalCard::getIsConfigured() const {
    return this->isConfigured;
}
