
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
#ifndef YUGIOH_DUELIST_HPP
#define YUGIOH_DUELIST_HPP

#include "deck.hpp"

class Duelist {
private:
    string name;
    Deck deck;
public:
    Duelist(string name);

    Duelist(string name, Deck &deck);

    void setDeck(Deck &newDeck);

    Deck &getDeck();

    bool saveDeck(string fileName);

    bool loadDeck(string fileName);

    void display();

    string duel(Duelist &duelist);
};

#endif