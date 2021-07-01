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
#pragma once
#include "Card.hpp"

enum class CardType{
    TRAP,   //=0
    BUFF,   //=1
    SPELL,  //=2
};

class MagicCard: virtual public Card{
private:
    CardType type = CardType::TRAP;  //assume that TRAP is the default card type
public:
    CardType getType() const;
    void setType(CardType);
    MagicCard(std::string name="", std::string effect="", unsigned int rarity=0, CardType type=CardType::TRAP);
    ~MagicCard() override = default;
    void printCard() override;
};











