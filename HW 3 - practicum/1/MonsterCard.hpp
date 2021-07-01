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

class MonsterCard{
private:
    string name;
    string effect;
    unsigned int attPts;
    unsigned int defPts;

public:
    string getName() const;
    string getEffect() const;
    unsigned int getAttPts() const;
    unsigned int getDefPts() const;
    void setName(string);
    void setEffect(string);
    void setAttPts(unsigned int);
    void setDefPts(unsigned int);

    MonsterCard();
    MonsterCard(string, string, unsigned int, unsigned int);

    void printMonsterCard();

};









