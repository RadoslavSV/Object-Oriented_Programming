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

#include "PendulumCard.hpp"
using namespace std;

int PendulumCard::getPendulumScale() const
{
    return this->pendulumScale;
}

PendulumCard::PendulumCard(string name,string effect,unsigned int attPts,unsigned int defPts,int pendulumScale,CardType type)
{
    setName(name);
    setEffect(effect);
    setAttPts(attPts);
    setDefPts(defPts);
    this->pendulumScale = pendulumScale;
    setType(type);
}

void PendulumCard::printPendulumCard()
{
    std::cout<<"Name: "<<getName()<<", Effect:"<<getEffect()<<", ATK:"<<getAttPts()<<", DEF:"<<getDefPts();
    std::cout<<", Pendulum Scale: "<<getPendulumScale()<<", Type:";
    if( (int)getType()==0 ) std::cout<<"TRAP";
    else if( (int)getType()==1 ) std::cout<<"BUFF";
    else if( (int)getType()==2 ) std::cout<<"SPELL";
    std::cout<<std::endl;
}





