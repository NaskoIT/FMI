#include "card.hpp"
#include "duelist.hpp"
#include <iostream>

using namespace std;

int main() {

    MonsterCard *dragon = new MonsterCard("Blue-Eyes White Dragon",
                                          "This legendary dragon is a powerful engine of destruction.", 3000, 2500, 10);
    MonsterCard *magician = new MonsterCard("Dark Magician", "The ultimate wizard.", 2500, 2100, 15);
    MagicCard *swords = new MagicCard("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.",
                                      CardType::spell, 20);
    MagicCard *cylinder = new MagicCard("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.",
                                        CardType::trap, 7);
    PendulumCard *timegazer = new PendulumCard("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards",
                                               1200, 600, CardType::spell, 8, 5);

    Duelist firstDuelist("Ivan Ivanov");
    firstDuelist.getDeck().setName("Magician Deck");
    firstDuelist.getDeck().addCard(dragon);
    firstDuelist.getDeck().addCard(swords);
    firstDuelist.getDeck().addCard(magician);
    firstDuelist.getDeck().addCard(cylinder);
    firstDuelist.getDeck().addCard(timegazer);

    cout << "Initial deck" << endl;
    firstDuelist.display();
    cout << endl;
    firstDuelist.loadDeck("magician_deck.txt");

    cout << "The deck after loading five new cards" << endl;
    firstDuelist.display();
    cout << endl;
    firstDuelist.saveDeck("double_deck.txt");


    Duelist duelist("Atanas");
    duelist.loadDeck("double_deck.txt");

    MagicCard *box = new MagicCard("Mystic Box", "Destroy one monster.", CardType::spell, 5);
    duelist.getDeck().setCard(5, box);
    cout << "Result after changing Swords of Revealing Light with Mystic Box" << endl;
    duelist.display();
    cout << endl;

    cout << firstDuelist.duel(duelist);
}
