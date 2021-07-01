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

#include "money.hpp"

Money::Money(int gold, int silver, int copper)
{
    this->gold = gold;
    this->silver = silver;
    this->copper = copper;

    if(this->copper>99)  //copper cannot be 100 or more
    {
        while(this->copper>99)
        {
            this->silver++;  //silver increases
            this->copper -= 100;  //100 copper equals 1 silver
        }
    }
    if(this->silver>99)  //silver cannot be 100 or more
    {
        while(this->silver>99)
        {
            this->gold++;    //gold increases
            this->silver -= 100;  //100 silver equals 1 gold
        }
    }
}

int Money::getGold()
{
    return this->gold;
}

int Money::getSilver()
{
    return this->silver;
}

int Money::getCopper()
{
    return this->copper;
}

void Money::addGold(int gold)
{
    this->gold += gold;
}

void Money::addSilver(int silver)
{
    this->silver += silver;

    if(this->silver>99)
    {
        while(this->silver>99)
        {
            this->gold++;
            this->silver -= 100;
        }
    }
}

void Money::addCopper(int copper)
{
    this->copper += copper;

    if(this->copper>99)
    {
        while(this->copper>99)
        {
            this->silver++;
            this->copper -= 100;
        }
    }
}

void Money::printMoney()
{
    cout<<"Gold:"<<getGold()<<" Silver:"<<getSilver()<<" Copper:"<<getCopper()<<endl;
}









