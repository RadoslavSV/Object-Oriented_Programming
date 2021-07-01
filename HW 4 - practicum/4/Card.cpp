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
#include "Card.hpp"

std::string Card::getName() const
{
    return this->name;
}

void Card::setName(std::string name)
{
    this->name = name;
}

std::string Card::getEffect() const
{
    return this->effect;
}

void Card::setEffect(std::string effect)
{
    this->effect = effect;
}

unsigned int Card::getRarity() const
{
    return this->rarity;
}

void Card::setRarity(unsigned int rarity)
{
    this->rarity = rarity;
}

Card::Card(std::string name, std::string effect, unsigned int rarity) : name(name), effect(effect), rarity(rarity) {}

bool Card::operator>(const Card& rhs) const
{
    return rarity > rhs.rarity;
}

bool Card::operator<(const Card& rhs) const
{
    return rarity < rhs.rarity;
}




