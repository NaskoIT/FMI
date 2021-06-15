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

#include "magicalCard.hpp"
#include "monsterCard.hpp"

const int DECK_MONSTER_CARDS_MAX_LENGTH = 20;
const int DECK_MAGICAL_CARDS_MAX_LENGTH = 20;

class Deck {
private:
    MagicalCard magicalCards[DECK_MAGICAL_CARDS_MAX_LENGTH];
    MonsterCard monsterCards[DECK_MONSTER_CARDS_MAX_LENGTH];
    int magicalCardsCount;
    int monsterCardsCount;

public:
    Deck();

    int getMagicalCardsCount() const;

    int getMonsterCardsCount() const;

    void addMagicalCard(char *name, char *effect, MagicalCardType type);

    void addMonsterCard(char *name, int attackingPoints, int protectivePoints);

    void addOrUpdateMagicalCard(int index, char *name, char *effect, MagicalCardType type);

    void addOrUpdateMonsterCard(int index, char *name, int attackingPoints, int protectivePoints);
};