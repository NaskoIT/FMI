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
#ifndef YUGIOH_PENDULUMCARD_HPP
#define YUGIOH_PENDULUMCARD_HPP

#include "magicCard.hpp"
#include "monsterCard.hpp"

class PendulumCard : public MonsterCard, public MagicCard {
private:
    int scale;

public:
    PendulumCard();

    int getScale() const;

    PendulumCard(string name, string effect, int attackingPoints, int protectivePoints, CardType type, int scale);

    ostream &operator<<(ostream &os) const;

    friend istream &operator>>(istream &is, PendulumCard& pendulumCard);
};

#endif
