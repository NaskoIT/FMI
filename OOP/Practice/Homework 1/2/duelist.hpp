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

#include "deck.hpp"

class Duelist {
private:
    char *name;
    Deck deck;
public:
    Duelist(char *name, Deck &deck);

    int getMagicalCardsCount() const;

    int getMonsterCardsCount() const;

    void addMagicalCard(char *name, char *effect, MagicalCardType type);

    void addMonsterCard(char *name, int attackingPoints, int protectivePoints);

    void addOrUpdateMagicalCard(int index, char *name, char *effect, MagicalCardType type);

    void addOrUpdateMonsterCard(int index, char *name, int attackingPoints, int protectivePoints);
};