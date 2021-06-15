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

#include <fstream>
#include "duelist.hpp"
#include <iostream>

using namespace std;

Duelist::Duelist(string name, Deck &deck) {
    this->name = name;
    this->deck = deck;
}

Duelist::Duelist(string name) {
    this->name = name;
}

void Duelist::setDeck(Deck& newDeck) {
    deck = newDeck;
}

Deck& Duelist::getDeck() {
    return this->deck;
}

bool Duelist::loadDeck(string fileName) {
    ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return false;
    }

    file >> deck;
    file.close();

    return true;
}

bool Duelist::saveDeck(string fileName) {
    ofstream file(fileName);

    if(!file.is_open()) {
        return false;
    }

    deck.operator<<(file);

    file.close();
    return true;
}

void Duelist::display() {
    deck.operator<<(cout);
}


