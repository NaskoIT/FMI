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

#ifndef INC_02_HOMEWORK_WEAPON_H
#define INC_02_HOMEWORK_WEAPON_H

#include <vector>
#include <utility>
#include <string>
#include "weaponType.h"
#include "weaponKind.h"

using namespace std;

typedef pair<string, double> Effect;

class Weapon {
private:
    WeaponType type;
    WeaponKind kind;
    double maxHitDamage;
    double minHitDamage;
    vector<Effect> effects;

    double getEffectScoreMultiplier() const;

    void onWeaponKindChange();

    int getEffectIndex(string &name) const;

    void changeEffectScore(int index, double score);

public:
    Weapon();

    Weapon(WeaponType type, WeaponKind kind, int minHitDamage, int maxHitDamage, vector<Effect> &effects);

    bool operator==(const Weapon &weapon) const;

    double getScore() const;

    double getEffectsScore() const;

    double getHitDamage() const;

    WeaponKind getKind() const;

    void changeKind(WeaponKind kind);

    WeaponType getType() const;

    void changeType(WeaponType type);

    void addEffect(string &name, double score);

    bool removeEffect(string &name);

    bool changeEffectScore(string &name, double newScore);
};

#endif //INC_02_HOMEWORK_WEAPON_H
