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
using namespace std;
#pragma once
#include "Card.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
class Duelist;

class Deck{
private:
    std::string deckname="";
    std::vector<Card*> cards;
public:
    std::string getDeckname() const;
    void setDeckname(std::string);
    std::vector<Card*> getCards();
    void setCards(std::vector<Card*>);
    Deck(std::string deckname="");
    void addCard(Card*);
    int getMonstersCount() const;
    int getMagicsCount() const;
    int getPendulumsCount() const;
    int getCardsCount() const;
    void setCard(int, Card*);
    void clearDeck();
    void shuffle();
    void printDeck() const;
    virtual ~Deck() {}
    friend class Duelist;
    friend std::ostream& operator<<(std::ostream& out, Duelist& d);
};







