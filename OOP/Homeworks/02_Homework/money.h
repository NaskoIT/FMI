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

#ifndef HOMEWORK_02_MONEY_H
#define HOMEWORK_02_MONEY_H

class Money {
private:
    int quantity;

public:
    Money();

    Money(int initialQuantity);

    int getSilver() const;

    int getGold() const;

    void addMoney(int money);

    bool removeMoney(int money);
};

#endif //INC_02_HOMEWORK_MONEY_H
