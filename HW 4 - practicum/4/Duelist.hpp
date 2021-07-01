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
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;
#pragma once
#include "Deck.hpp"

class Duelist{
private:
    std::string name="";
    Deck deck;
public:
    std::string getName() const;
    void setName(std::string);
    Deck& getDeck();
    void setDeck(Deck);
    Duelist(std::string name="");
    bool saveDeck(const char* filename);
    bool loadDeck(const char* filename);
    void duel(Duelist&);
    friend std::istream& operator>>(std::istream& in, Duelist& d);
    friend std::ostream& operator<<(std::ostream& out, Duelist& d);
    void display();
};

inline std::istream& operator>>(std::istream& in, Duelist& d)
{
    char discard='|';
    std::string inputName, inputEffect;
    int input2, input3, input4, input5, inputPendulum, inputType;
    unsigned int inputRarity, inputAttPts, inputDefPts;
    in>>inputName>>discard>>input2>>discard>>input3>>discard>>input4>>discard>>input5;

    d.getDeck().setDeckname(inputName);
    int i=0;
    for( ; i<input3; i++)
    {
        in>>inputName>>discard>>inputEffect>>discard>>inputRarity>>discard>>inputAttPts>>discard>>inputDefPts;
        MonsterCard m(inputName, inputEffect, inputRarity, inputAttPts, inputDefPts);
        d.getDeck().addCard(&m);
    }
    for( ; i<input4; i++)
    {
        in>>inputName>>discard>>inputEffect>>discard>>inputRarity>>discard>>inputType;
        MagicCard m(inputName, inputEffect, inputRarity, static_cast<CardType>(inputType) );
        d.getDeck().addCard(&m);
    }
    for( ; i<input5; i++)
    {
        in>>inputName>>discard>>inputEffect>>discard>>inputRarity>>discard>>inputAttPts>>discard>>inputDefPts>>discard>>inputPendulum>>discard>>inputType;
        PendulumCard p(inputName, inputEffect, inputRarity, inputAttPts, inputDefPts, inputPendulum, static_cast<CardType>(inputType) );
        d.getDeck().addCard(&p);
    }
    return in;
}

inline std::ostream& operator<<(std::ostream& out, Duelist& d)
{
    out<<d.getDeck().getDeckname()<<"|"<<d.getDeck().getCardsCount()<<"|"<<d.getDeck().getMonstersCount()<<"|"<<d.getDeck().getMagicsCount()
       <<"|"<<d.getDeck().getPendulumsCount()<<std::endl;



    int i=0;
    for( ; i<d.getDeck().getMonstersCount(); i++)
    {
        MonsterCard* monsterPtr = dynamic_cast<MonsterCard*>(d.getDeck().cards[i]);
        out<<monsterPtr->getName()<<"|"<<monsterPtr->getEffect()<<"|"<<monsterPtr->getRarity()<<"|"
           <<monsterPtr->getAttPts()<<"|"<<monsterPtr->getDefPts()<<"|"<<std::endl;
    }
    for( ; i<d.getDeck().getMagicsCount(); i++)
    {
        MagicCard* magicPtr = dynamic_cast<MagicCard*>(d.getDeck().cards[i]);
        out<<magicPtr->getName()<<"|"<<magicPtr->getEffect()<<"|"<<magicPtr->getRarity()<<"|"
           <<static_cast<int>(magicPtr->getType())<<std::endl;
    }
    for( ; i<d.getDeck().getPendulumsCount(); i++)
    {
        PendulumCard* pendulumPtr = dynamic_cast<PendulumCard*>(d.getDeck().cards[i]);
        out<<pendulumPtr->getName()<<"|"<<pendulumPtr->getEffect()<<"|"<<pendulumPtr->getRarity()<<"|"
           <<pendulumPtr->getAttPts()<<"|"<<pendulumPtr->getDefPts()<<"|"<<pendulumPtr->getPendulumScale()<<"|"
           <<static_cast<int>(pendulumPtr->getType())<<std::endl;
    }
    return out;
}














