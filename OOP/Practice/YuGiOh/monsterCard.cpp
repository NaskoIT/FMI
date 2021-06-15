
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
#include "monsterCard.hpp"

using namespace std;

MonsterCard::MonsterCard() : Card() {
    attackingPoints = 0;
    protectivePoints = 0;
}

MonsterCard::MonsterCard(string name, string effect, int attackingPoints, int protectivePoints)
        : Card(name, effect) {
    this->attackingPoints = attackingPoints;
    this->protectivePoints = protectivePoints;
}

unsigned int MonsterCard::getAttackingPoints() const {
    return attackingPoints;
}

unsigned int MonsterCard::getProtectivePoints() const {
    return protectivePoints;
}

int readInteger(istream& is, char delimiter) {
    string temp;
    getline(is, temp, delimiter);
    return stoi(temp);
}

istream &MonsterCard::operator>>(istream &is) {
    Card::operator>>(is);
    this->attackingPoints = readInteger(is, INPUT_DELIMITER);
    this->protectivePoints = readInteger(is, NEW_LINE);

    return is;
}

ostream &MonsterCard::operator<<(ostream &os) const {
    Card::operator<<(os);
    os << OUTPUT_DELIMITER + to_string(this->attackingPoints) + OUTPUT_DELIMITER;
    os << to_string(this->protectivePoints);

    return os;
}

void MonsterCard::getAttackingPoints(unsigned int points) {
    this->attackingPoints = points;
}

void MonsterCard::setProtectivePoints(unsigned int points) {
    this->protectivePoints = points;
}


