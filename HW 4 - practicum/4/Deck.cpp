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
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include "Deck.hpp"

std::string Deck::getDeckname() const
{
    return this->deckname;
}

void Deck::setDeckname(std::string deckname)
{
    this->deckname = deckname;
}

std::vector<Card*> Deck::getCards()
{
    return this->cards;
}

void Deck::setCards(std::vector<Card*> cards)
{
    this->cards = cards;
}

Deck::Deck(std::string deckname)
{
    setDeckname(deckname);
}

void Deck::addCard(Card* card)
{
    cards.push_back(card);
}

int Deck::getMonstersCount() const
{
    int monstersCount=0;
    for(auto x : cards)
    {
        auto monsterPtr = dynamic_cast<MonsterCard*>(x);
        if(monsterPtr) { monstersCount++; }
    }
    monstersCount -= getPendulumsCount();
    //subtract the number of pendulum cards in the deck, because the PendulumCard class inherits both MonsterCard and MagicCard
    return monstersCount;
}

int Deck::getMagicsCount() const
{
    int magicsCount=0;
    for(auto x : cards)
    {
        auto magicPtr = dynamic_cast<MagicCard*>(x);
        if(magicPtr) { magicsCount++; }
    }
    magicsCount -= getPendulumsCount();
    //the same here
    return magicsCount;
}

int Deck::getPendulumsCount() const
{
    int pendulumsCount=0;
    for(auto x : cards)
    {
        auto pendulumPtr = dynamic_cast<PendulumCard*>(x);
        if(pendulumPtr) { pendulumsCount++; }
    }
    return pendulumsCount;
}

int Deck::getCardsCount() const
{
    return cards.size();
}

void Deck::setCard(int i, Card* newCard)
{
    int monstersCount=0;
    int magicsCount=0;
    int pendulumsCount=0;
    MonsterCard* monsterPtr = dynamic_cast<MonsterCard*>(cards[i]);
    if(monsterPtr) { monstersCount=1; magicsCount=0; pendulumsCount=0; }
    MagicCard* magicPtr = dynamic_cast<MagicCard*>(cards[i]);
    if(magicPtr) { magicsCount=1; monstersCount=0; pendulumsCount=0; }
    PendulumCard* pendulumPtr = dynamic_cast<PendulumCard*>(cards[i]);
    if(pendulumPtr) { pendulumsCount=1; monstersCount=0; magicsCount=0; }

    int newMonstersCount=0;
    int newMagicsCount=0;
    int newPendulumsCount=0;
    auto monstPtr = dynamic_cast<MonsterCard*>(newCard);
    if(monstPtr) { newMonstersCount=1; newMagicsCount=0; newPendulumsCount=0; }
    auto magPtr = dynamic_cast<MagicCard*>(newCard);
    if(magPtr) { newMagicsCount=1; newPendulumsCount=0; newMonstersCount=0; }
    auto pendPtr = dynamic_cast<PendulumCard*>(newCard);
    if(pendPtr) { newPendulumsCount=1; newMonstersCount=0; newMagicsCount=0; }

    if( (monstersCount==1 && newMonstersCount==1) || (magicsCount==1 && newMagicsCount==1) || (pendulumsCount==1 && newPendulumsCount==1) )
    { cards[i] = newCard; }
}

void Deck::shuffle()
{
    std::random_shuffle(cards.begin(),cards.end());
}

void Deck::clearDeck()
{
    cards.clear();
}

void Deck::printDeck() const
{
    std::cout<<"Deckname:"<<getDeckname()<<std::endl;
    for(auto x : cards)
    {
        x->printCard();
    }
    std::cout<<"Monster cards count: "<<getMonstersCount()<<std::endl;
    std::cout<<"Magic cards count: "<<getMagicsCount()<<std::endl;
    std::cout<<"Pendulum cards count: "<<getPendulumsCount()<<std::endl;
    std::cout<<"Total cards count: "<<getCardsCount()<<std::endl;
}









