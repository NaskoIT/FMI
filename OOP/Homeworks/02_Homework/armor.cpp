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

#include "armor.h"

const int NOT_FOUND_INDEX = -1;

Armor::Armor() {
    type = ArmorType::leather;
    defense = 0;
}

double Armor::getGearScore() const {
    double score = 0;
    for (const Effect &effect : effects) {
        score += effect.second;
    }

    return score;
}

Armor::Armor(ArmorType type, int defense, vector<Effect> &effects) {
    this->type = type;
    this->defense = defense;
    this->effects = effects;
}

Armor::Armor(const Armor &from) {
    type = from.type;
    defense = from.defense;
    effects = from.effects;
}

bool Armor::operator==(const Armor &armor) {
    return this->type == armor.type &&
           this->defense == armor.defense &&
           this->getGearScore() == armor.getGearScore();
}

ArmorType Armor::getType() const {
    return this->type;
}

void Armor::setType(const ArmorType &armorType) {
    this->type = armorType;
}

int Armor::getDefense() const {
    return this->defense;
}

void Armor::setDefense(int newDefense) {
    this->defense = newDefense;
}

void Armor::addEffect(string &name, int score) {
    int index = getEffectIndex(name);

    if (index == -1) {
        effects.push_back(Effect(name, score));
    } else {
        Effect currentEffect = effects[index];
        changeEffectScore(index, currentEffect.second + score);
    }
}

bool Armor::removeEffect(string &name) {
    int index = getEffectIndex(name);
    if (index == NOT_FOUND_INDEX) {
        return false;
    }

    effects.erase(effects.begin() + index);
    return true;
}

bool Armor::changeEffectScore(string &name, double newScore) {
    int index = getEffectIndex(name);
    if (index == NOT_FOUND_INDEX) {
        return false;
    }

    changeEffectScore(index, newScore);
    return true;
}

bool Armor::changeEffectScore(int index, double newScore) {
    if (index < 0 || index >= this->effects.size()) {
        return false;
    }

    Effect currentEffect = effects[index];
    effects[index] = Effect(currentEffect.first, newScore);
    return true;
}

int Armor::getEffectIndex(string &effectName) const {
    for (int i = 0; i < effects.size(); ++i) {
        if (effects[i].first == effectName) {
            return i;
        }
    }

    return NOT_FOUND_INDEX;
}

