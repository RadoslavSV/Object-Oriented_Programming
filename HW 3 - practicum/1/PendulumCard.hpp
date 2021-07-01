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

class PendulumCard : public MagicCard{
private:
    int pendulumScale;   //must have value between 1 and 13

public:
    int getPendulumScale() const;

    PendulumCard(string name="",string effect="",unsigned int attPts=0,unsigned int defPts=0,int pendulumScale=0,CardType type=CardType::TRAP);

    void printPendulumCard();

};



