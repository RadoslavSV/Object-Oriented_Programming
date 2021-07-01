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
#include "Deck.cpp"
#include <iostream>
#include <fstream>
#include <ostream>

class Duelist{
private:
    string name;
    Deck deck;

public:
    string getName() const;
    Deck& getDeck();
    Duelist(string name="");
    void setName(string);
    void setDeck(Deck);

    bool saveDeck(const char* filename);
    bool loadDeck(const char* filename);

    void display();
};



