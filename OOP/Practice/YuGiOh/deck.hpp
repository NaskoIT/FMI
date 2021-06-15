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

#pragma once
#ifndef YUGIOH_DECK_HPP
#define YUGIOH_DECK_HPP

#include "pendulumCard.hpp"
#include "singleDeck.hpp"

using namespace std;

class Deck {
private:
    string name;
    SingleDeck<MonsterCard> monsterCardsDeck;
    SingleDeck<MagicCard> magicalCardsDeck;
    SingleDeck<PendulumCard> pendulumCardsDeck;

public:
    Deck();

    void setName(string newName);

    string getName() const;

    int getMagicalCardsCount() const;

    int getMonsterCardsCount() const;

    int getPendulumCardsCount() const;

    void addMagicalCard(MagicCard& magicalCard);

    void addMonsterCard(MonsterCard& monsterCard);

    void addPendulumCard(PendulumCard& pendulumCard);

    void setMagicalCard(int index, MagicCard& magicalCard);

    void setMonsterCard(int index, MonsterCard& monsterCard);

    void setPendulumCard(int index, PendulumCard& pendulumCard);

    void clear();

    ostream &operator<<(ostream &os) const;

    friend istream &operator>>(istream &is, Deck& deck);
};

#endif