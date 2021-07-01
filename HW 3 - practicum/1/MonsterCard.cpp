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

#include <iostream>
#include "MonsterCard.hpp"
using namespace std;

std::string MonsterCard::getName() const
{
    return this->name;
}

std::string MonsterCard::getEffect() const
{
    return this->effect;
}

unsigned int MonsterCard::getAttPts() const
{
    return this->attPts;
}

unsigned int MonsterCard::getDefPts() const
{
    return this->defPts;
}

void MonsterCard::setName(string name)
{
    this->name=name;
}

void MonsterCard::setEffect(string effect)
{
    this->effect=effect;
}

void MonsterCard::setAttPts(unsigned int attPts)
{
    this->attPts=attPts;
}

void MonsterCard::setDefPts(unsigned int defPts)
{
    this->defPts=defPts;
}

MonsterCard::MonsterCard()
{
    name = "";
    effect = "";
    attPts = 0;
    defPts = 0;
}

MonsterCard::MonsterCard(std::string name, std::string effect, unsigned int attPts, unsigned int defPts)
{
    this->name = name;
    this->effect = effect;
    this->attPts = attPts;
    this->defPts = defPts;
}

void MonsterCard::printMonsterCard()
{
    std::cout<<"Name: "<<getName()<<", Effect:"<<getEffect()<<", ATK:"<<getAttPts()<<", DEF:"<<getDefPts()<<std::endl;
}



















