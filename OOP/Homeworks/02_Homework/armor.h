/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Atanas Vasilev
* @idnumber 62577
* @task 1
* @compiler GCC
*/

#ifndef INC_02_HOMEWORK_ARMOR_H
#define INC_02_HOMEWORK_ARMOR_H

#include <vector>
#include <utility>
#include <string>
#include "armorType.h"

using namespace std;

typedef pair<string, double> Effect;

class Armor {
private:
    ArmorType type;
    int defense;
    vector<Effect> effects;

    int getEffectIndex(string &name) const;

    bool changeEffectScore(int index, double newScore);

public:
    Armor();

    Armor(ArmorType type, int defense, vector<Effect> &effects);

    Armor(const Armor &from);

    bool operator==(const Armor &armor);

    double getGearScore() const;

    ArmorType getType() const;

    void setType(const ArmorType &armorType);

    int getDefense() const;

    void setDefense(int defense);

    void addEffect(string &name, int score);

    bool removeEffect(string &name);

    bool changeEffectScore(string &name, double newScore);
};

#endif //INC_02_HOMEWORK_ARMOR_H
