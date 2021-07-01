/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 4
* @compiler GCC
*/

#include <iostream>
using namespace std;
#include "Duelist.hpp"

int main()
{
    MonsterCard dragon("Blue-Eyes White Dragon", "A powerful engine of destruction", 43, 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard", 53, 2500, 2100);
    dragon.printCard();
    magician.printCard();
    MagicCard swords("Swords of Revealing Light", "Your opponent cannot attack", 123, CardType::SPELL);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent", 9, CardType::TRAP);
    swords.printCard();
    cylinder.printCard();
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate trap cards", 3, 1200, 600, 8, CardType::BUFF);
    PendulumCard p2("PenMonster", "Very strong", 375, 1050, 750, 5, CardType::TRAP);
    timegazer.printCard();
    p2.printCard();
    std::cout<<std::endl;

    Deck d1("Winning Deck");
    d1.addCard(&dragon);
    d1.addCard(&cylinder);
    d1.addCard(&swords);
    d1.addCard(&timegazer);
    d1.printDeck();
    std::cout<<std::endl;
    MagicCard box("Mystic Box", "Destroys one monster", 0, CardType::SPELL);
    d1.setDeckname("Magician Deck");
    d1.setCard(1, &box);
    d1.printDeck();
    std::cout<<std::endl;
    d1.shuffle();
    d1.shuffle();
    d1.printDeck();
    std::cout<<std::endl;

    Duelist firstDuelist("Ivan Ivanov");
    firstDuelist.getDeck().setDeckname("Magician Deck");
    firstDuelist.getDeck().addCard(&dragon);
    firstDuelist.getDeck().addCard(&swords);
    firstDuelist.getDeck().addCard(&magician);
    firstDuelist.getDeck().addCard(&cylinder);
    firstDuelist.getDeck().addCard(&timegazer);
    firstDuelist.display();
    firstDuelist.getDeck().setCard(1, &box);
    firstDuelist.getDeck().shuffle();

    Duelist secondDuelist("Gosho Goshev");
    secondDuelist.getDeck().setDeckname("Goshko's Deck");
    secondDuelist.getDeck().addCard(&dragon);
    secondDuelist.getDeck().addCard(&swords);
    secondDuelist.getDeck().addCard(&magician);
    secondDuelist.getDeck().addCard(&cylinder);
    secondDuelist.getDeck().addCard(&timegazer);
    secondDuelist.getDeck().shuffle();

    firstDuelist.display();
    secondDuelist.display();

    firstDuelist.saveDeck("magician_deck.txt");

    firstDuelist.duel(secondDuelist);
    std::cout<<std::endl;

    MonsterCard m1("R", "E", 35, 134, 431);
    MagicCard ma1("O", "R", 30, CardType::SPELL);
    PendulumCard p1("P", "T", 40, 345, 543, 4, CardType::TRAP);
    MagicCard ma2("Ty", "R", 38, CardType::SPELL);
    Duelist commander("Commander"), azeez("Azeez");
    commander.getDeck().setDeckname("Commander's deck");
    azeez.getDeck().setDeckname("Azeez's deck");

    commander.getDeck().addCard(&p1);
    commander.getDeck().addCard(&ma2);
    azeez.getDeck().addCard(&m1);
    azeez.getDeck().addCard(&ma1);
    azeez.duel(commander);


    return 0;
}




