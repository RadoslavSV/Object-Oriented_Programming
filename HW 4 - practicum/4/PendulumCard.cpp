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
#include "PendulumCard.hpp"

int PendulumCard::getPendulumScale() const
{
    return this->pendulumScale;
}

void PendulumCard::setPendulumScale(int pendulumScale)
{
    this->pendulumScale = pendulumScale;
}

PendulumCard::PendulumCard(std::string name, std::string effect, unsigned int rarity, unsigned int attPts, unsigned int defPts,
                           int pendulumScale, CardType type)
{
    setName(name);
    setEffect(effect);
    setRarity(rarity);
    setAttPts(attPts);
    setDefPts(defPts);
    setPendulumScale(pendulumScale);
    setType(type);
}

void PendulumCard::printCard()
{
    std::cout<<"Name:"<<getName()<<" Effect:"<<getEffect()<<" Rarity:"<<getRarity()<<" ATT:"<<getAttPts()<<" DEF:"<<getDefPts()
             <<" PendulumScale:"<<getPendulumScale()<<" Type:"<<static_cast<int>(getType())<<std::endl;
}




