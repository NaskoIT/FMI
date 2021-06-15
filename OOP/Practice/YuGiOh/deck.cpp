
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

#include "deck.hpp"

Deck::Deck() {
    name = "";
}

void Deck::setName(string newName) {
    name = newName;
}

string Deck::getName() const {
    return name;
}

int Deck::getMagicalCardsCount() const {
    return magicalCardsDeck.getCardsCount();
}

int Deck::getMonsterCardsCount() const {
    return monsterCardsDeck.getCardsCount();
}

int Deck::getPendulumCardsCount() const {
    return pendulumCardsDeck.getCardsCount();
}

void Deck::addMagicalCard(MagicCard &magicalCard) {
    magicalCardsDeck.addCard(magicalCard);
}

void Deck::addMonsterCard(MonsterCard &monsterCard) {
    monsterCardsDeck.addCard(monsterCard);
}

void Deck::addPendulumCard(PendulumCard &pendulumCard) {
    pendulumCardsDeck.addCard(pendulumCard);
}

void Deck::setMagicalCard(int index, MagicCard &magicalCard) {
    magicalCardsDeck.setCard(index, magicalCard);
}

void Deck::setMonsterCard(int index, MonsterCard &monsterCard) {
    monsterCardsDeck.setCard(index, monsterCard);
}

void Deck::setPendulumCard(int index, PendulumCard &pendulumCard) {
    pendulumCardsDeck.setCard(index, pendulumCard);
}

void Deck::clear() {
    monsterCardsDeck.clear();
    magicalCardsDeck.clear();
    pendulumCardsDeck.clear();
}

istream &operator>>(istream &is, Deck &deck) {
    string name;
    getline(is, name, '|');
    deck.setName(name);

    string tempInput;
    getline(is, tempInput, '|');
    int monsterCardsCount = stoi(tempInput);

    getline(is, tempInput, '|');
    int magicalCardsCount = stoi(tempInput);

    getline(is, tempInput, '\n');
    int pendulumCardsCount = stoi(tempInput);

    for (int i = 0; i < monsterCardsCount; i++) {
        MonsterCard monsterCard;
        monsterCard.operator>>(is);
        deck.addMonsterCard(monsterCard);
    }

    for (int i = 0; i < magicalCardsCount; i++) {
        MagicCard magicalCard;
        magicalCard.operator>>(is);
        deck.addMagicalCard(magicalCard);
    }

    for (int i = 0; i < pendulumCardsCount; i++) {
        PendulumCard pendulumCard;
        is >> pendulumCard;
        deck.addPendulumCard(pendulumCard);
    }

    return is;
}

void appendNameAndEffectOstream(ostream& os, const string& name, const string& effect) {
    os << name + "|" + effect + "|";
}

void appendAttackingAndProtectivePointsToOstream(ostream& os, unsigned int attackingPoints, unsigned int protectivePoints, string ending = "") {
    os << to_string(attackingPoints) + "|" + to_string(protectivePoints) + ending;
}

string getCardTypeAsString(CardType type) {
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

ostream &Deck::operator<<(ostream &os) const {
    // TODO: use the << operators of the cards classes
    os << (getName() + "|" + to_string(getMonsterCardsCount()) + "|" +
           to_string(getMagicalCardsCount()) + "|" + to_string(getPendulumCardsCount()) + "\n");

    vector<MonsterCard> monsterCards = monsterCardsDeck.getCards();
    for (int i = 0; i < monsterCards.size(); ++i) {
        appendNameAndEffectOstream(os, monsterCards[i].getName(), monsterCards[i].getEffect());
        appendAttackingAndProtectivePointsToOstream(os, monsterCards[i].getAttackingPoints(),
                                                    monsterCards[i].getProtectivePoints(), "\n");
    }

    vector<MagicCard> magicalCards = magicalCardsDeck.getCards();
    for (int i = 0; i < magicalCards.size(); ++i) {
        appendNameAndEffectOstream(os, magicalCards[i].getName(), magicalCards[i].getEffect());
        os << getCardTypeAsString(magicalCards[i].getType()) + "\n";
    }

    vector<PendulumCard> pendulumCards = pendulumCardsDeck.getCards();
    for (int i = 0; i < pendulumCards.size(); ++i) {
        appendNameAndEffectOstream(os, pendulumCards[i].MonsterCard::getName(), pendulumCards[i].MonsterCard::getEffect());
        appendAttackingAndProtectivePointsToOstream(os, pendulumCards[i].getAttackingPoints(),
                                                    pendulumCards[i].getProtectivePoints());
        os << "|" + to_string(pendulumCards[i].getScale()) + "|" + getCardTypeAsString(pendulumCards[i].getType()) +
              "\n";
    }

    return os;
}
