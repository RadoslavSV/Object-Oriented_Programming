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
#include "MonsterCard.hpp"

unsigned int MonsterCard::getAttPts() const
{
    return this->attPts;
}

void MonsterCard::setAttPts(unsigned int attPts)
{
    this->attPts = attPts;
}

unsigned int MonsterCard::getDefPts() const
{
    return this->defPts;
}

void MonsterCard::setDefPts(unsigned int defPts)
{
    this->defPts = defPts;
}

MonsterCard::MonsterCard(std::string name, std::string effect, unsigned int rarity, unsigned int attPts, unsigned int defPts)
{
    setName(name);
    setEffect(effect);
    setRarity(rarity);
    setAttPts(attPts);
    setDefPts(defPts);
}

void MonsterCard::printCard()
{
    std::cout<<"Name:"<<getName()<<" Effect:"<<getEffect()<<" Rarity:"<<getRarity()<<" ATT:"<<getAttPts()<<" DEF:"<<getDefPts()<<std::endl;
}











