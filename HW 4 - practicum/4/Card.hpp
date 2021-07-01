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

class Card{
private:
    std::string name = "";
    std::string effect = "";
    unsigned int rarity = 0;

public:
    std::string getName() const;
    void setName(std::string);
    std::string getEffect() const;
    void setEffect(std::string);
    unsigned int getRarity() const;
    void setRarity(unsigned int);
    Card(std::string name="", std::string effect="", unsigned int rarity=0);
    bool operator>(const Card&) const;
    bool operator<(const Card&) const;
    virtual ~Card() {}
    virtual void printCard() = 0; //virtual method, thus making the class an abstract one
};



