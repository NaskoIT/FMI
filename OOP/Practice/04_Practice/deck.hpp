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
#include <vector>

using namespace std;

class Deck {
private:
    string name;
    vector<Card *> cards;

    int countCards(string objectTypeName) const;

    void appendCardsToStream(string objectTypeName, ostream &os) const;

    void setCards(const Deck& deck);

public:
    Deck();

    Deck(string initName);

    Deck(const Deck& deck);

    ~Deck();

    Deck &operator=(const Deck& deck);

    void setName(string newName);

    string getName() const;

    vector<Card *> getCards() const;

    int getMagicalCardsCount() const;

    int getMonsterCardsCount() const;

    int getPendulumCardsCount() const;

    int getCardsCount() const;

    void addCard(Card *card);

    void setCard(int index, Card *card);

    void clear();

    void shuffle();

    ostream &operator<<(ostream &os) const;

    friend istream &operator>>(istream &is, Deck &deck);
};

#endif