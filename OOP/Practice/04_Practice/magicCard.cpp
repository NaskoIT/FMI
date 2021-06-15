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

#include "magicCard.hpp"

MagicCard::MagicCard() : Card() {
    type = CardType::none;
}

MagicCard::MagicCard(string name, string effect, CardType type) : Card(name, effect) {
    this->type = type;
}

MagicCard::MagicCard(string name, string effect, CardType type, unsigned int rarity) : Card(name, effect, rarity) {
    this->type = type;
}

void MagicCard::setType(CardType cardType) {
    this->type = cardType;
}

CardType MagicCard::getType() const {
    return type;
}

string getMagicCardTypeAsString(CardType type) {
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

ostream &MagicCard::operator<<(ostream &os) const {
    Card::operator<<(os);

    os << OUTPUT_DELIMITER + getMagicCardTypeAsString(this->getType()) + NEW_LINE;

    return os;
}

CardType parseCardType(string input) {
    if (input == "SPELL") {
        return CardType::spell;
    } else if (input == "TRAP") {
        return CardType::trap;
    } else if (input == "BUFF") {
        return CardType::buff;
    }

    return CardType::none;
}

istream &MagicCard::operator>>(istream &is) {
    Card::operator>>(is);

    string temp;
    getline(is, temp, NEW_LINE);
    this->type = parseCardType(temp);
}

string MagicCard::getObjectType() const {
    return "magicCard.hpp";
}

Card *MagicCard::clone() {
    return new MagicCard(this->getName(), this->getEffect(), this->getType(), this->getRarity());
}
