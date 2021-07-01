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
using namespace std;
#pragma once
#include "Card.hpp"

class MonsterCard: virtual public Card{
private:
    unsigned int attPts = 0;
    unsigned int defPts = 0;
public:
    unsigned int getAttPts() const;
    void setAttPts(unsigned int);
    unsigned int getDefPts() const;
    void setDefPts(unsigned int);
    MonsterCard(std::string name="", std::string effect="", unsigned int rarity=0, unsigned int attPts=0, unsigned int defPts=0);
    ~MonsterCard() override = default;
    void printCard() override;
};










