/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 1
* @compiler GCC
*/

#include <iostream>
using namespace std;

#include "Duelist.cpp"

int main()
{
    MonsterCard dragon("Blue-Eyes White Dragon", "A powerful engine of destruction", 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard", 2500, 2100);

    MagicCard swords("Swords of Light", "Your opponent's monsters cannot attack", CardType::SPELL);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent", CardType::TRAP);

    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Cards", 1200, 600, 8, CardType::TRAP);

    Deck d1("Almighty Deck");
    d1.addMonsterCard(dragon);
    d1.addMonsterCard(magician);
    d1.addMagicCard(swords);
    d1.addMagicCard(cylinder);
    d1.addPendulumCard(timegazer);
    d1.printDeck();
    std::cout<<"Monster cards number:"<<d1.getMonstersCount()<<std::endl;
    std::cout<<"Magic cards number:"<<d1.getMagicsCount()<<std::endl;
    std::cout<<"Pendulum cards number:"<<d1.getPendulumsCount()<<std::endl<<std::endl;

    d1.setDeckname("New Deck");
    MonsterCard m1("SubZero", "Very strong", 4000, 2000);
    d1.setMonsterCard(1, m1);
    MagicCard w1("Avada Kedavra", "Killing Curse", CardType::BUFF);
    d1.setMagicCard(0, w1);
    PendulumCard p1("King Kong", "Defeats Godzilla easily", 5500, 6050, 12, CardType::BUFF);
    d1.setPendulumCard(0, p1);
    d1.printDeck();
    std::cout<<std::endl;

    d1.clearDeck();
    d1.printDeck();
    std::cout<<"Monster cards number:"<<d1.getMonstersCount()<<std::endl;
    std::cout<<"Magic cards number:"<<d1.getMagicsCount()<<std::endl;
    std::cout<<"Pendulum cards number:"<<d1.getPendulumsCount()<<std::endl<<std::endl<<std::endl;

    Duelist firstDuelist("Ivan Ivanov");

    firstDuelist.getDeck().setDeckname("Magician Deck");

    firstDuelist.getDeck().addMonsterCard(dragon);
    firstDuelist.getDeck().addMagicCard(swords);
    firstDuelist.getDeck().addMonsterCard(magician);
    firstDuelist.getDeck().addMagicCard(cylinder);
    firstDuelist.getDeck().addPendulumCard(timegazer);
    firstDuelist.display();
    std::cout<<std::endl;

    MagicCard box("Mystic Box", "Destroys one monster", CardType::SPELL);
    firstDuelist.setName("Nasakoto Yakata");
    firstDuelist.getDeck().setMagicCard(1, box);
    firstDuelist.getDeck().setPendulumCard(0, p1);
    firstDuelist.display();
    std::cout<<std::endl;

    firstDuelist.saveDeck("magician_deck.txt");

    Duelist secondDuelist("Georgi Georgiev");
    secondDuelist.loadDeck("magician_deck.txt");
    secondDuelist.display();
    std::cout<<"Monster cards number:"<<secondDuelist.getDeck().getMonstersCount()<<std::endl;
    std::cout<<"Magic cards number:"<<secondDuelist.getDeck().getMagicsCount()<<std::endl;
    std::cout<<"Pendulum cards number:"<<secondDuelist.getDeck().getPendulumsCount()<<std::endl<<std::endl<<std::endl;


    return 0;
}



