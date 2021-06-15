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
#ifndef YUGIOH_CARD_HPP
#define YUGIOH_CARD_HPP

#include <string>
#include "cardType.hpp"

using namespace std;

const char INPUT_DELIMITER = '|';
const char OUTPUT_DELIMITER = '|';
const char NEW_LINE = '\n';

class Card {
private:
    string name;
    string effect;
    unsigned int rarity;

public:
    Card();

    Card(string initName, string initEffect);

    Card(string initName, string initEffect, unsigned int initRarity);

    virtual ~Card() = default;

    void setName(string newName);

    string getName() const;

    void setEffect(string newEffect);

    string getEffect() const;

    void setRarity(unsigned int newRarity);

    unsigned int getRarity() const;

    virtual string getObjectType() const = 0;

    virtual Card* clone() = 0;

    virtual ostream &operator<<(ostream &os) const;

    virtual istream &operator>>(istream &is);

    bool operator<(const Card &card) const;

    bool operator>(const Card &card) const;
};

#endif
