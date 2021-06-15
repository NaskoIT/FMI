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

Card::Card() {
    name = "";
    effect = "";
    rarity = 0;
}

Card::Card(string initName, string initEffect) {
    name = initName;
    effect = initEffect;
    rarity = 0;
}

Card::Card(string initName, string initEffect, unsigned int initRarity) {
    name = initName;
    effect = initEffect;
    rarity = initRarity;
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

void Card::setRarity(unsigned int newRarity) {
    this->rarity = newRarity;
}

unsigned int Card::getRarity() const {
    return this->rarity;
}

ostream &Card::operator<<(ostream &os) const {
    os << this->getName() + "|" + this->getEffect() + "|" + to_string(this->getRarity());
    return os;
}

istream &Card::operator>>(istream &is) {
    getline(is, this->name, INPUT_DELIMITER);
    getline(is, this->effect, INPUT_DELIMITER);

    string inputRarity;
    getline(is, inputRarity, INPUT_DELIMITER);
    rarity = stoi(inputRarity);

    return is;
}

bool Card::operator<(const Card &card) const {
    return this->rarity < card.rarity;
}

bool Card::operator>(const Card &card) const {
    return this->rarity > card.rarity;
}
