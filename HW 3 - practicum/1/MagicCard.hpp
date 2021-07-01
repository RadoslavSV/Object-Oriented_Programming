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

#pragma once
using namespace std;
#include<string>

enum class CardType{
    TRAP,     //=0
    BUFF,     //=1
    SPELL,    //=2
};

class MagicCard : public MonsterCard{
private:
    CardType type;

public:
    CardType getType() const;
    void setType(CardType);

    MagicCard(string name="", string effect="", CardType type=CardType::TRAP); //assume that type TRAP is the default one

    void printMagicCard();

};




