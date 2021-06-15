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

const int DRAGON_CARD_NAME_MAX_LENGTH = 25;

class MonsterCard {
private:
    char *name;
    unsigned int attackingPoints;
    unsigned int protectivePoints;
    bool isConfigured;

public:
    MonsterCard();

    MonsterCard(char *name, int attackingPoints, int protectivePoints);

    bool getIsConfigured() const;
};