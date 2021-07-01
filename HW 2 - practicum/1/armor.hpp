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

#pragma once
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <utility>

enum class ArmorType{
    cloth,       //=0
    leather,     //=1
    mail,        //=2
};

class Armor{
    ArmorType type = ArmorType::cloth;  //assume cloth as default armor type
    int defense = 0;
    vector< pair<string,double> > setOfEffects;   //set of effects, where each one has their name (type string) and power (type double)
    double Gearscore = 0;

public:
    Armor(ArmorType = ArmorType::cloth, int = 0);
    ArmorType getType();
    int getDefense();
    vector< pair<string,double> > getSetOfEffects();
    void addEffect(string, double);
    void removeEffect(string, double); //removes an effect by given name and accurate power (both the name and the power must be equal to some effect's ones in the array)
    void removeEffectByIdx(int);
    void changePower(int,double);  //changes power of an effect by said index and given exact power
    double getScore(); //getter for the "Gearscore" variable, which calculates (accumulates all present powers of all effects) and then returns the result

    bool operator==(Armor); //overload operator== that will compare two Armor-type objects by their gear score
    bool operator!=(Armor); //same with the operator!=

    void printAllEffects(); //function that prints all current effects into the set

};




