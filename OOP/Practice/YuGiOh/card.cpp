/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 1
* @compiler GCC
*/


#include "card.hpp"

Card::Card(string initName, string initEffect) {
    name = initName;
    effect = initEffect;
}

Card::Card() {
    name = "";
    effect = "";
}

void Card::setName(string newName) {
    name = newName;
}

string Card::getName() const {
    return name;
}

void Card::setEffect(string newEffect) {
    effect = newEffect;
}

string Card::getEffect() const {
    return effect;
}

ostream &Card::operator<<(ostream &os) const {
    os << this->getName() + "|" + this->getEffect();
    return os;
}

istream &Card::operator>>(istream &is) {
    getline(is, this->name, INPUT_DELIMITER);
    getline(is, this->effect, INPUT_DELIMITER);
    return is;
}
