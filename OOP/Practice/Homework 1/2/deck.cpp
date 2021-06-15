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

#include "deck.hpp"
#include "helperFunctions.hpp"

Deck::Deck() {
    this->magicalCardsCount = 0;
    this->monsterCardsCount = 0;
}

int Deck::getMagicalCardsCount() const {
    return this->magicalCardsCount;
}

int Deck::getMonsterCardsCount() const {
    return this->monsterCardsCount;
}

void Deck::addMagicalCard(char *name, char *effect, MagicalCardType type) {
    if (this->magicalCardsCount >= DECK_MAGICAL_CARDS_MAX_LENGTH) {
        return;
    }

    MagicalCard magicalCard(name, effect, type);
    for (int i = 0; i < DECK_MAGICAL_CARDS_MAX_LENGTH; ++i) {
        if (!this->magicalCards[i].getIsConfigured()) {
            this->magicalCards[i] = magicalCard;
            this->magicalCardsCount++;
            break;
        }
    }
}

void Deck::addMonsterCard(char *name, int attackingPoints, int protectivePoints) {
    if (this->monsterCardsCount >= DECK_MONSTER_CARDS_MAX_LENGTH) {
        return;
    }

    MonsterCard monsterCard(name, attackingPoints, protectivePoints);
    for (int i = 0; i < DECK_MONSTER_CARDS_MAX_LENGTH; ++i) {
        if (!this->monsterCards[i].getIsConfigured()) {
            this->monsterCards[i] = monsterCard;
            this->monsterCardsCount++;
            break;
        }
    }
}

void Deck::addOrUpdateMagicalCard(int index, char *name, char *effect, MagicalCardType type) {
    if (!isValidIndex(0, DECK_MAGICAL_CARDS_MAX_LENGTH - 1, index)) {
        return;
    }

    if (!this->magicalCards[index].getIsConfigured()) {
        this->magicalCardsCount++;
    }

    MagicalCard card(name, effect, type);
    this->magicalCards[index] = card;
}

void Deck::addOrUpdateMonsterCard(int index, char *name, int attackingPoints, int protectivePoints) {
    if (!isValidIndex(0, DECK_MONSTER_CARDS_MAX_LENGTH - 1, index)) {
        return;
    }

    if (!this->monsterCards[index].getIsConfigured()) {
        this->monsterCardsCount++;
    }

    MonsterCard card(name, attackingPoints, protectivePoints);
    this->monsterCards[index] = card;
}
