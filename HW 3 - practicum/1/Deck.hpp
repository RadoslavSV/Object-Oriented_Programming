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

#pragma once
using namespace std;
#include <vector>
#include "MonsterCard.cpp"
#include "MagicCard.cpp"
#include "PendulumCard.cpp"

class Deck{
private:
    string name;
public:
    vector<MonsterCard> monsterCards;
    vector<MagicCard> magicCards;
    vector<PendulumCard> pendulumCards;

public:
    string getName() const;
    void setDeckname(string);
    Deck(string name="");
    void addMonsterCard(MonsterCard&);
    void addMagicCard(MagicCard&);
    void addPendulumCard(PendulumCard&);
    int getMonstersCount();
    int getMagicsCount();
    int getPendulumsCount();
    void setMonsterCard(int, MonsterCard);
    void setMagicCard(int, MagicCard);
    void setPendulumCard(int, PendulumCard);

    void clearDeck();

    void printDeck();


};



