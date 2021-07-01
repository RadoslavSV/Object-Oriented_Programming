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
#include "MagicCard.hpp"

CardType MagicCard::getType() const
{
    return this->type;
}

void MagicCard::setType(CardType type)
{
    this->type = type;
}

MagicCard::MagicCard(std::string name, std::string effect, unsigned int rarity, CardType type)
{
    setName(name);
    setEffect(effect);
    setRarity(rarity);
    setType(type);
}

void MagicCard::printCard()
{
    std::cout<<"Name:"<<getName()<<" Effect:"<<getEffect()<<" Rarity:"<<getRarity()<<" Type:"<<static_cast<int>(getType())<<std::endl;
}








