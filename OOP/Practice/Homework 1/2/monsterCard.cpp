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

#include "monsterCard.hpp"

MonsterCard::MonsterCard(char *name, int attackingPoints, int protectivePoints) {
    this->name = name;
    this->attackingPoints = attackingPoints;
    this->attackingPoints = protectivePoints;
    this->isConfigured = true;
}

MonsterCard::MonsterCard() {
    this->isConfigured = false;
}

bool MonsterCard::getIsConfigured() const {
    return this->isConfigured;
}

