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

#include "weapon.h"

const int NOT_FOUND_INDEX = -1;

// public members
Weapon::Weapon() {
    type = WeaponType::oneHanded;
    kind = WeaponKind::sword;
    minHitDamage = 0;
    maxHitDamage = 0;
}

Weapon::Weapon(WeaponType type, WeaponKind kind, int minHitDamage, int maxHitDamage, vector<Effect> &effects) {
    this->type = type;
    this->kind = kind;
    this->minHitDamage = minHitDamage;
    this->maxHitDamage = maxHitDamage;
    this->effects = effects;
}

bool Weapon::operator==(const Weapon &weapon) const {
    return this->type == weapon.type &&
           this->kind == weapon.kind &&
           this->minHitDamage == weapon.minHitDamage &&
           this->maxHitDamage == maxHitDamage &&
           this->getEffectsScore() == weapon.getEffectsScore() &&
           this->getScore() == weapon.getScore();

}

double Weapon::getScore() const {
    return (getHitDamage() + getEffectsScore()) * getEffectScoreMultiplier();
}

double Weapon::getHitDamage() const {
    return (maxHitDamage + minHitDamage) / 2;
}

WeaponKind Weapon::getKind() const {
    return kind;
}

void Weapon::changeKind(WeaponKind newKind) {
    this->kind = newKind;
    onWeaponKindChange();
}

WeaponType Weapon::getType() const {
    return type;
}

void Weapon::changeType(WeaponType newType) {
    if ((kind == dagger && newType != oneHanded) ||
        (kind == staff && newType != twoHanded)) {
        return;
    }

    type = newType;
}

void Weapon::addEffect(string &name, double score) {
    int index = getEffectIndex(name);

    if (index == -1) {
        effects.push_back(Effect(name, score));
    } else {
        Effect currentEffect = effects[index];
        changeEffectScore(index, currentEffect.second + score);
    }
}

bool Weapon::removeEffect(string &name) {
    int index = getEffectIndex(name);

    if (index == NOT_FOUND_INDEX) {
        return false;
    }

    effects.erase(effects.begin() + index);
    return true;
}

bool Weapon::changeEffectScore(string &name, double newScore) {
    int index = getEffectIndex(name);

    if (index == NOT_FOUND_INDEX) {
        return false;
    }

    changeEffectScore(index, newScore);
    return true;
}

double Weapon::getEffectsScore() const {
    double score = 0;
    for (const Effect &effect : effects) {
        score += effect.second;
    }
}

// private members
double Weapon::getEffectScoreMultiplier() const {
    return type == oneHanded ? 0.75 : 1.5;
}

int Weapon::getEffectIndex(string &name) const {
    // map data structure can be used to score the effects for faster solution
    // Currently the algorithm complexity is O(n)
    // If we use map the algorithm complexity will be O(1)
    for (int i = 0; i < effects.size(); ++i) {
        if (effects[i].first == name) {
            return i;
        }
    }

    return NOT_FOUND_INDEX;
}

void Weapon::changeEffectScore(int index, double newScore) {
    if (index < 0 || index >= this->effects.size()) {
        return;
    }

    Effect currentEffect = effects[index];
    effects[index] = Effect(currentEffect.first, newScore);
}

void Weapon::onWeaponKindChange() {
    if (kind == staff) {
        type = twoHanded;
    } else if (kind == dagger) {
        type = oneHanded;
    }
}
