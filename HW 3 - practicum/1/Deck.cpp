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

#include "Deck.hpp"
using namespace std;

std::string Deck::getName() const
{
    return this->name;
}

void Deck::setDeckname(string name)
{
    this->name = name;
}

Deck::Deck(std::string name)
{
    this->name = name;
    monsterCards.clear();
    magicCards.clear();
    pendulumCards.clear();
}

void Deck::addMonsterCard(MonsterCard& m)
{
    MonsterCard newM(m.getName(), m.getEffect(), m.getAttPts(), m.getDefPts());
    monsterCards.push_back(newM);
}

void Deck::addMagicCard(MagicCard& m)
{
    MagicCard newM(m.getName(), m.getEffect(), m.getType());
    magicCards.push_back(m);
}

void Deck::addPendulumCard(PendulumCard& p)
{
    PendulumCard newP(p.getName(), p.getEffect(), p.getAttPts(), p.getDefPts(), p.getPendulumScale(), p.getType());
    pendulumCards.push_back(newP);
}

int Deck::getMonstersCount()
{
    return monsterCards.size();
}

int Deck::getMagicsCount()
{
    return magicCards.size();
}

int Deck::getPendulumsCount()
{
    return pendulumCards.size();
}

void Deck::setMonsterCard(int n, MonsterCard m)
{
    MonsterCard newM( m.getName(), m.getEffect(), m.getAttPts(), m.getDefPts() );
    monsterCards[n] = newM;
}

void Deck::setMagicCard(int n, MagicCard m)
{
    MagicCard newM( m.getName(), m.getEffect(), m.getType() );
    magicCards[n] = newM;
}

void Deck::setPendulumCard(int n, PendulumCard p)
{
    PendulumCard newP( p.getName(), p.getEffect(), p.getAttPts(), p.getDefPts(), p.getPendulumScale(), p.getType() );
    pendulumCards[n] = newP;
}

void Deck::clearDeck()
{
    this->name = "";
    monsterCards.clear();
    magicCards.clear();
    pendulumCards.clear();
}

void Deck::printDeck()
{
    std::cout<<"Deck name: "<<getName()<<std::endl;
    std::cout<<"Monster Cards:"<<std::endl;
    for(int i=0; i<monsterCards.size(); i++)
    {
        monsterCards[i].printMonsterCard();
    }
    std::cout<<"Magic Cards:"<<std::endl;
    for(int i=0; i<magicCards.size(); i++)
    {
        magicCards[i].printMagicCard();
    }
    std::cout<<"Pendulum Cards:"<<std::endl;
    for(int i=0; i<pendulumCards.size(); i++)
    {
        pendulumCards[i].printPendulumCard();
    }
}














