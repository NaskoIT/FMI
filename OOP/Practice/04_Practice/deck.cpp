
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

#include "deck.hpp"
#include <cstdlib>

const int SHUFFLE_MULTIPLIER = 4;

int getIndex(int size);

Deck::Deck() {
    name = "";
}

Deck::Deck(string initName) {
    this->name = initName;
}

Deck::Deck(const Deck &deck) {
    this->name = deck.name;
    setCards(deck);
}

Deck &Deck::operator=(const Deck &deck) {
    if (this != &deck) {
        this->name = deck.name;
        this->clear();
        this->setCards(deck);
    }

    return * this;
}

Deck::~Deck() {
    this->clear();
}

void Deck::setName(string newName) {
    name = newName;
}

string Deck::getName() const {
    return name;
}

int Deck::getMagicalCardsCount() const {
    return countCards("magicCard.hpp");
}

int Deck::getMonsterCardsCount() const {
    return countCards("monsterCard.hpp");
}

int Deck::getPendulumCardsCount() const {
    return countCards("pendulumCard.hpp");
}

int Deck::getCardsCount() const {
    return cards.size();
}

void Deck::addCard(Card *card) {
    cards.push_back(card);
}

void Deck::setCard(int index, Card *card) {
    if (index < 0 || index >= cards.size()) {
        return;
    }

    // Only cards from the same type can be changed
    if (cards[index]->getObjectType() != card->getObjectType()) {
        return;
    }

    cards[index] = card;
}

void Deck::clear() {
    for (Card *&card : cards) {
        delete card;
    }

    cards.clear();
}

int Deck::countCards(string objectTypeName) const {
    int counter = 0;
    for (const Card *card : cards) {
        if (card->getObjectType() == objectTypeName) {
            counter++;
        }
    }

    return counter;
}

void Deck::shuffle() {
    int cardsCount = cards.size();
    for (int i = 0; i < cardsCount * SHUFFLE_MULTIPLIER; ++i) {
        int sourceIndex = getIndex(cardsCount);
        int destinationIndex = getIndex(cardsCount);

        Card *temp = cards[sourceIndex];
        cards[sourceIndex] = cards[destinationIndex];
        cards[destinationIndex] = temp;
    }
}

istream &operator>>(istream &is, Deck &deck) {
    string name;
    getline(is, name, '|');
    deck.setName(name);

    string tempInput;
    getline(is, tempInput, '|');
    int monsterCardsCount = stoi(tempInput);

    getline(is, tempInput, '|');
    int magicalCardsCount = stoi(tempInput);

    getline(is, tempInput, '\n');
    int pendulumCardsCount = stoi(tempInput);

    for (int i = 0; i < monsterCardsCount; i++) {
        MonsterCard *monsterCard = new MonsterCard();
        monsterCard->operator>>(is);
        deck.addCard(monsterCard);
    }

    for (int i = 0; i < magicalCardsCount; i++) {
        MagicCard *magicalCard = new MagicCard;
        magicalCard->operator>>(is);
        deck.addCard(magicalCard);
    }

    for (int i = 0; i < pendulumCardsCount; i++) {
        PendulumCard *pendulumCard = new PendulumCard();
        pendulumCard->operator>>(is);
        deck.addCard(pendulumCard);
    }

    return is;
}

ostream &Deck::operator<<(ostream &os) const {
    os << (getName() + "|" + to_string(getMonsterCardsCount()) + "|" +
           to_string(getMagicalCardsCount()) + "|" + to_string(getPendulumCardsCount()) + "\n");

    string cardObjectTypes[] = {"monsterCard.hpp", "magicCard.hpp", "pendulumCard.hpp"};
    for (const string objectTypeName : cardObjectTypes) {
        appendCardsToStream(objectTypeName, os);
    }

    return os;
}

vector<Card *> Deck::getCards() const {
    return cards;
}

void Deck::appendCardsToStream(string objectTypeName, ostream &os) const {
    for (const Card *card : cards) {
        if (card->getObjectType() == objectTypeName) {
            card->operator<<(os);
        }
    }
}

void Deck::setCards(const Deck& deck) {
    for(Card* card : deck.getCards()) {
        this->cards.push_back(card->clone());
    }
}

int getIndex(int size) {
    return rand() % size;
}
