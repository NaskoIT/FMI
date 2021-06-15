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

#include "duelist.hpp"

Duelist::Duelist(char *name, Deck &deck) {
    this->name = name;
    this->deck = deck;
}

int Duelist::getMagicalCardsCount() const {
    return this->deck.getMagicalCardsCount();
}

int Duelist::getMonsterCardsCount() const {
    return this->deck.getMonsterCardsCount();
}

void Duelist::addMagicalCard(char *cardName, char *effect, MagicalCardType type) {
    this->deck.addMagicalCard(cardName, effect, type);
}

void Duelist::addMonsterCard(char *cardName, int attackingPoints, int protectivePoints) {
    this->deck.addMonsterCard(cardName, attackingPoints, protectivePoints);
}

void Duelist::addOrUpdateMagicalCard(int index, char *cardName, char *effect, MagicalCardType type) {
    this->deck.addOrUpdateMagicalCard(index, cardName, effect, type);
}

void Duelist::addOrUpdateMonsterCard(int index, char *cardName, int attackingPoints, int protectivePoints) {
    this->deck.addOrUpdateMonsterCard(index, cardName, attackingPoints, protectivePoints);
}



