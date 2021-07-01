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

#include "weapon.hpp"

Weapon::Weapon(WeaponType type, WeaponKind kind)
{
    this->type = type;
    this->kind = kind;
}

WeaponType Weapon::getType()
{
    return this->type;
}

WeaponKind Weapon::getKind()
{
    return this->kind;
}

vector< pair<string,double> > Weapon::getSetOfEffects()
{
    return this->setOfEffects;
}

void Weapon::changeKind(WeaponKind newKind)
{
    this->kind = newKind;

    if( (int)getKind() == 0 || (int)getKind() == 2 || (int)getKind() == 3)  //this means the weapon is either axe, dagger or mace
        this->type = WeaponType::oneHanded;

    if( (int)getKind() == 1 || (int)getKind() == 4 )  //the weapon is either sword or staff
        this->type = WeaponType::twoHanded;
}

void Weapon::changeType(WeaponType newType)
{
    this->type = newType;

    if( (int)getType() == 0 && (int)getKind() != 2 && (int)getKind() != 3 )  //the weapon is one-handed AND is neither dagger nor mace
        this->kind = WeaponKind::axe;  //assume that the default one-handed weapon is axe

    if( (int)getType() == 1 && (int)getKind() != 4 )  //the weapon is two-handed AND is not staff
        this->kind = WeaponKind::sword; //assume that the default two-handed weapon is sword

}

void Weapon::addEffect(string name, double power)
{
    this->setOfEffects.push_back( make_pair(name,power) );
}

void Weapon::removeEffect(string name, double power)
{
    for(int i=0; i<setOfEffects.size(); i++)
    {
        if(this->setOfEffects[i].first == name && setOfEffects[i].second == power)
        {
            this->setOfEffects.erase( setOfEffects.begin() + i );
        }
    }
}

void Weapon::removeEffectByIdx(int n)
{
    this->setOfEffects.erase( setOfEffects.begin() + n );
}

void Weapon::changePower(int n, double power)
{
    this->setOfEffects[n].second = power;
}

pair<double,double> Weapon::getHitDamage()
{
    double minPower = setOfEffects[0].second;
    double maxPower = setOfEffects[0].second;
    for(int i=0; i<setOfEffects.size(); i++)
    {
        if( minPower > setOfEffects[i].second)
        {
            minPower = setOfEffects[i].second;
        }
        if( maxPower < setOfEffects[i].second)
        {
            maxPower = setOfEffects[i].second;
        }
    }
    hitDamage.first = minPower;
    hitDamage.second = maxPower;

    return this->hitDamage;
}

double Weapon::getScore()
{
    this->WeaponScore=0;
    for(int i=0; i<setOfEffects.size(); i++)
    {
        this->WeaponScore += getSetOfEffects()[i].second;
    }
    this->WeaponScore += (hitDamage.first + hitDamage.second)/2;
    if( (int)getType()==0 ) this->WeaponScore *= 0.75;
    if( (int)getType()==1 ) this->WeaponScore *= 1.5;

    return this->WeaponScore;
}

void Weapon::printAllEffects()
{
    cout<<endl;
    for(int i=0; i<setOfEffects.size(); i++)
    {
        cout<<"Effect:"<<getSetOfEffects()[i].first<<" Power:"<<getSetOfEffects()[i].second<<endl;
    }
}

bool Weapon::operator==(Weapon rhs)
{
    return this->getScore() == rhs.getScore();
}

bool Weapon::operator!=(Weapon rhs)
{
    return this->getScore() != rhs.getScore();
}


