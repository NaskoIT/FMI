#include "duelist.hpp"

int main() {
    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", CardType::spell);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", CardType::trap);
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, CardType::spell, 8);

    Duelist firstDuelist("Ivan Ivanov");
    firstDuelist.getDeck().setName("Magician Deck");
    firstDuelist.getDeck().addMonsterCard(dragon);
    firstDuelist.getDeck().addMagicalCard(swords);
    firstDuelist.getDeck().addMonsterCard(magician);
    firstDuelist.getDeck().addMagicalCard(cylinder);
    firstDuelist.getDeck().addPendulumCard(timegazer);
    //firstDuelist.display();
    //firstDuelist.saveDeck("magician_deck.txt");
    //firstDuelist.loadDeck("magician_deck.txt");
    firstDuelist.display();
    MagicCard box("Mystic Box", "Destroy one monster.", CardType::spell);
    firstDuelist.getDeck().setMagicalCard(1, box);

    //firstDuelist.saveDeck("test.txt");

    Duelist duelist("Atanas");
    duelist.loadDeck("test.txt");
    duelist.saveDeck("output.txt");
}
