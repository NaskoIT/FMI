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

#include "pendulumCard.hpp"

PendulumCard::PendulumCard() : Card(), MonsterCard(), MagicCard() {
    scale = 0;
}

PendulumCard::PendulumCard(string name, string effect, unsigned int attackingPoints, unsigned int protectivePoints, CardType type, int scale)
        : Card(name, effect),
          MonsterCard(name, effect, attackingPoints, protectivePoints),
          MagicCard(name, effect, type) {
    this->scale = scale;
}

PendulumCard::PendulumCard(string name, string effect, unsigned int attackingPoints, unsigned int protectivePoints, CardType type, int scale, unsigned int rarity)
        : Card(name, effect, rarity),
          MonsterCard(name, effect, attackingPoints, protectivePoints, rarity),
          MagicCard(name, effect, type, rarity) {
    this->scale = scale;
}

int PendulumCard::getScale() const {
    return scale;
}

string getPendulumCardTypeAsString(CardType type) {
    switch (type) {
        case spell:
            return "SPELL";
        case trap:
            return "TRAP";
        case buff:
            return "BUFF";
        default:
            return "";
    }
}

ostream &PendulumCard::operator<<(ostream &os) const {
    Card::operator<<(os);
    os << OUTPUT_DELIMITER + to_string(this->getAttackingPoints()) + OUTPUT_DELIMITER;
    os << to_string(this->getProtectivePoints()) + OUTPUT_DELIMITER;

    os << to_string(scale) + OUTPUT_DELIMITER;
    os << getPendulumCardTypeAsString(getType()) + NEW_LINE;

    return os;
}

int parseInteger(istream &is, char delimiter) {
    string temp;
    getline(is, temp, delimiter);
    return stoi(temp);
}

CardType parsePendulumCardType(string input) {
    if (input == "SPELL") {
        return CardType::spell;
    } else if (input == "TRAP") {
        return CardType::trap;
    } else if (input == "BUFF") {
        return CardType::buff;
    }

    return CardType::none;
}

string PendulumCard::getObjectType() const {
    return "pendulumCard.hpp";
}

istream &PendulumCard::operator>>(istream &is) {
    Card::operator>>(is);

    string temp;
    getline(is, temp, INPUT_DELIMITER);
    this->setAttackingPoints(stoi(temp));

    getline(is, temp, INPUT_DELIMITER);
    this->setProtectivePoints(stoi(temp));

    this->scale = parseInteger(is, INPUT_DELIMITER);
    getline(is, temp, NEW_LINE);
    this->setType(parsePendulumCardType(temp));

    return is;
}

Card *PendulumCard::clone() {
    return new PendulumCard(
            this->getName(),
            this->getEffect(),
            this->getAttackingPoints(),
            this->getProtectivePoints(),
            this->getType(),
            this->getScale(),
            this->getRarity());
}
