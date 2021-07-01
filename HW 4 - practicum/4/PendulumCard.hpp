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
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class PendulumCard: public MonsterCard, public MagicCard{
private:
    int pendulumScale = 1;    //its value has to be between 1 and 13
public:
    int getPendulumScale() const;
    void setPendulumScale(int);
    PendulumCard(std::string name="", std::string effect="", unsigned int rarity=0, unsigned int attPts=0, unsigned int defPts=0,
                 int pendulumScale=1, CardType type=CardType::TRAP);
    ~PendulumCard() override = default;
    void printCard() override;
};










