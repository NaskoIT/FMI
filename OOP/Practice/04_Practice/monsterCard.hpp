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
#ifndef YUGIOH_MONSTERCARD_HPP
#define YUGIOH_MONSTERCARD_HPP

#include "card.hpp"

class MonsterCard : public virtual Card {
private:
    unsigned int attackingPoints;
    unsigned int protectivePoints;

public:
    MonsterCard();

    MonsterCard(string name, string effect, int attackingPoints, int protectivePoints);

    MonsterCard(string name, string effect, int attackingPoints, int protectivePoints, unsigned int rarity);

    virtual ~MonsterCard() override = default;

    unsigned int getAttackingPoints() const;

    void setAttackingPoints(unsigned int points);

    unsigned int getProtectivePoints() const;

    void setProtectivePoints(unsigned int points);

    string getObjectType() const override;

    Card * clone() override;

    ostream &operator<<(ostream &os) const override;

    istream &operator>>(istream &is) override;
};

#endif