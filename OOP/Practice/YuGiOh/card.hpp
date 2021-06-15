
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

public:
    Card();

    Card(string initName, string initEffect);

    void setName(string newName);

    string getName() const;

    void setEffect(string newEffect);

    string getEffect() const;

    ostream &operator<<(ostream &os) const;

    istream &operator>>(istream &is);
};

#endif
