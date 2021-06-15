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

#include "magicalCardType.hpp"

const int MAGICAL_CARD_NAME_MAX_LENGTH = 25;
const int MAGICAL_CARD_EFFECT_MAX_LENGTH = 100;

class MagicalCard {
private:
    char *name;
    char *effect;
    MagicalCardType type;
    bool isConfigured;

public:
    MagicalCard();

    MagicalCard(char *name, char *effect, MagicalCardType type);

    bool getIsConfigured() const;
};
