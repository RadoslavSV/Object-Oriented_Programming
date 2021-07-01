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
#include "MagicCard.hpp"
using namespace std;

CardType MagicCard::getType() const
{
    return this->type;
}

void MagicCard::setType(CardType type)
{
    this->type=type;
}

MagicCard::MagicCard(string name, string effect, CardType type)
{
    setName(name);
    setEffect(effect);
    setType(type);
}

void MagicCard::printMagicCard()
{
    std::cout<<"Name: "<<getName()<<", Effect:"<<getEffect()<<", Type:";
    if( (int)getType()==0 ) std::cout<<"TRAP";
    else if( (int)getType()==1 ) std::cout<<"BUFF";
    else if( (int)getType()==2 ) std::cout<<"SPELL";
    std::cout<<std::endl;
}








