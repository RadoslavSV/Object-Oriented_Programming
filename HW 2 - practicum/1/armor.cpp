/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 1
* @compiler GCC
*/

#include "armor.hpp"

Armor::Armor(ArmorType type, int defense)
{
    this->type = type;
    this->defense = defense;
}

ArmorType Armor::getType()
{
    return this->type;
}

int Armor::getDefense()
{
    return this->defense;
}

vector< pair<string,double> > Armor::getSetOfEffects()
{
    return this->setOfEffects;
}

void Armor::addEffect(string name, double power)
{
    this->setOfEffects.push_back( make_pair(name,power) );
}

void Armor::removeEffect(string name, double power)
{
    for(int i=0; i<setOfEffects.size(); i++)
    {
        if(this->setOfEffects[i].first == name && setOfEffects[i].second == power)
        {
            this->setOfEffects.erase( setOfEffects.begin() + i );
        }
    }
}

void Armor::removeEffectByIdx(int n)
{
    this->setOfEffects.erase( setOfEffects.begin() + n );
}

void Armor::changePower(int n,double power)
{
    this->setOfEffects[n].second = power;
}

void Armor::printAllEffects()
{
    cout<<endl;
    for(int i=0; i<setOfEffects.size(); i++)
    {
        cout<<"Effect:"<<getSetOfEffects()[i].first<<" Power:"<<getSetOfEffects()[i].second<<endl;
    }
}

double Armor::getScore()
{
    this->Gearscore=0;  //make initial gear score equal to zero, cause otherwise it accumulates as many times as we call the function
    for(int i=0; i<setOfEffects.size(); i++)
    {
        this->Gearscore += getSetOfEffects()[i].second;
    }
    return this->Gearscore;
}

bool Armor::operator==(Armor rhs)
{
    return this->getScore() == rhs.getScore();
}

bool Armor::operator!=(Armor rhs)
{
    return this->getScore() != rhs.getScore();
}










