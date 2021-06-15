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
#ifndef YUGIOH_MAGICCARD_HPP
#define YUGIOH_MAGICCARD_HPP

#include "card.hpp"
#include "cardType.hpp"

class MagicCard : public Card {
private:
    CardType type;

public:
    MagicCard();

    MagicCard(string name, string effect, CardType type);

    void setType(CardType cardType);

    CardType getType() const;

    ostream &operator<<(ostream &os) const;

    istream &operator>>(istream &is);
};

#endif