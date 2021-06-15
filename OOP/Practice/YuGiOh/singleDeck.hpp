
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
#pragma once
#ifndef YUGIOH_SINGLEDECK_HPP
#define YUGIOH_SINGLEDECK_HPP

#include <vector>

using namespace std;

template <typename T>
class SingleDeck {
private:
    vector<T> cards;

public:
    int getCardsCount() const {
        return cards.size();
    }

    void addCard(T& card) {
        cards.push_back(card);
    }

    bool setCard(int index, T& card) {
        if(index < 0 || index >= cards.size()) {
            return false;
        }

        cards[index] = card;

        return true;
    }

    void clear() {
        cards.clear();
    }

    vector<T> getCards() const {
        return cards;
    }
};

#endif