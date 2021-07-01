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

enum class WeaponType{
    oneHanded,    //=0
    twoHanded,   ///=1
};

enum class WeaponKind{
    axe,           //=0 ; type: oneHanded
    sword,        ///=1 ; type: twoHanded
    dagger,        //=2 ; type: oneHanded
    mace,          //=3 ; type: oneHanded
    staff,        ///=4 ; type: twoHanded
};

class Weapon{
    WeaponType type;
    WeaponKind kind;
    vector< pair<string,double> > setOfEffects;
    pair<double,double> hitDamage; //a pair whose first value is the minimum power of all effects and second value is the maximum power of the effects
    double WeaponScore = 0;

public:
    Weapon(WeaponType type = WeaponType::oneHanded, WeaponKind kind = WeaponKind::axe); //the constructor creates an object by given type and kind
    WeaponType getType();
    WeaponKind getKind();
    vector< pair<string,double> > getSetOfEffects();
    void changeKind(WeaponKind);  //changes the kind of the weapon by given a new one as a parameter (automatically changes the type as well)
    void changeType(WeaponType);  //changes the type of the weapon (if the current kind is of the opposite type it changes the kind as well to the default one)
    void addEffect(string, double);
    void removeEffect(string, double);
    void removeEffectByIdx(int);
    void changePower(int,double);
    pair<double,double> getHitDamage(); //getter for the private hitDamage variable (calculation in method itself)
    double getScore(); //calculates and return the Weapon score

    bool operator==(Weapon); //overload operator== that will compare two Weapon-type objects by their weapon score
    bool operator!=(Weapon); //same with operator!=

    void printAllEffects(); //prints all inserted current effects of the weapon

};


