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

PendulumCard::PendulumCard() : MonsterCard(), MagicCard() {
    scale = 0;
}

PendulumCard::PendulumCard(string name, string effect, int attackingPoints, int protectivePoints, CardType type, int scale)
        : MonsterCard(name, effect, attackingPoints, protectivePoints),
          MagicCard(name, effect, type) {
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
    MonsterCard::operator<<(os);

    os << "|" + to_string(scale) + OUTPUT_DELIMITER;
    os << getPendulumCardTypeAsString(getType()) + NEW_LINE;

    return os;
}

int parseInteger(istream& is, char delimiter) {
    string temp;
    getline(is, temp, delimiter);
    return stoi(temp);
}

CardType parsePendulumCardType(string input) {
    if(input == "SPELL") {
        return CardType::spell;
    }
    else if (input == "TRAP") {
        return CardType::trap;
    }
    else if(input == "BUFF") {
        return CardType::buff;
    }

    return CardType::none;
}

istream &operator>>(istream &is, PendulumCard &pendulumCard) {
    string name;
    getline(is, name, INPUT_DELIMITER);
    pendulumCard.MonsterCard::setName(name);
    string effect;
    getline(is, effect, INPUT_DELIMITER);
    pendulumCard.MonsterCard::setEffect(effect);

    // TODO set the points
    string temp;
    getline(is, temp, INPUT_DELIMITER);

    getline(is, temp, INPUT_DELIMITER);

    pendulumCard.scale = parseInteger(is, INPUT_DELIMITER);
    getline(is, temp, NEW_LINE);
    pendulumCard.setType(parsePendulumCardType(temp));

    return is;
}
