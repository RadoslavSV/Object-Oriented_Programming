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

template <class TTT>    //typename TTT
class Equipment{
    vector< TTT > v;
    int slots = 0;
public:
    int getSlots();
    void addEquipment(TTT);
    void removeEquipment(int);
    void removeExactArmor(Armor);  //removes the exact said armor as a parameter
    void removeExactWeapon(Weapon);//removes the exact given weapon as a parameter
    bool isEquipmentFull();  //if all slots are takes, returns true
    bool isEquipmentEmpty(); //if not even one slot is taken, returns true
    void clearEquipment();   //removes all inserted equipments from the dynamic array
    TTT bestEquipment();   //return an equipment from type TTT

    void printArmorEquipment();  //prints all inserted armors in the equipment
    void printWeaponEquipment(); //prints all inserted weapons in the equipment

};

template <class TTT>
int Equipment<TTT>::getSlots()
{
    return this->slots;
}

template <class TTT>
void Equipment<TTT>::addEquipment(TTT tool)
{
    if( slots < 24 )   //if slots are 24, then function does not proceed to add more, because there's no more space left
    {
        v.push_back(tool);
        slots++;
    }
}

template <class TTT>
void Equipment<TTT>::removeEquipment(int n)
{
    v.erase( v.begin() + n );
    slots--;
}

template <class TTT>
void Equipment<TTT>::removeExactArmor(Armor tool)
{
    for(int i=0; i<v.size(); i++)
    {
        if( (int)v[i].getType() == (int)tool.getType() && v[i].getDefense() == tool.getDefense() )
        {
            v.erase( v.begin() + i );
            slots--;
        }
    }
}

template <class TTT>
void Equipment<TTT>::removeExactWeapon(Weapon tool)
{
    for(int i=0; i<v.size(); i++)
    {
        if( (int)v[i].getKind() == (int)tool.getKind() )
        {
            v.erase( v.begin() + i );
            slots--;
        }
    }
}

template <class TTT>
bool Equipment<TTT>::isEquipmentFull()
{
    if( getSlots() == 24 ) return true;         //disclaimer: slots cannot be more than 24, because of the way addEquipment() function works
    else if( getSlots() < 24 ) return false;
}

template <class TTT>
bool Equipment<TTT>::isEquipmentEmpty()
{
    if( getSlots() == 0 ) return true;          //slots cannot be negative, due to the removeExactArmor() function
    else return false;
}

template <class TTT>
void Equipment<TTT>::clearEquipment()
{
    v.clear();
    slots = 0;
}

template <class TTT>
TTT Equipment<TTT>::bestEquipment()
{
    double bestScore = v[0].getScore();
    int bestScoreIdx = 0;
    for(int i=1; i<v.size();i++)
    {
        if( v[i].getScore() > bestScore )
        {
            bestScore = v[i].getScore();
            bestScoreIdx = i;
        }
    }
    return v[bestScoreIdx];
}

template <class TTT>
void Equipment<TTT>::printArmorEquipment()
{
    for(int i=0; i<v.size();i++)
    {
        if( (int)v[i].getType() == 0 ) cout<<"Type:cloth Defense:";
        if( (int)v[i].getType() == 1 ) cout<<"Type:leather Defense:";
        if( (int)v[i].getType() == 2 ) cout<<"Type:mail Defense:";
        cout<<v[i].getDefense()<<" Score:"<<v[i].getScore()<<endl;
    }
}

template <class TTT>
void Equipment<TTT>::printWeaponEquipment()
{
    for(int i=0; i<v.size();i++)
    {
        if( (int)v[i].getKind() == 0 ) cout<<"Kind:axe";
        if( (int)v[i].getKind() == 1 ) cout<<"Kind:sword";
        if( (int)v[i].getKind() == 2 ) cout<<"Kind:dagger";
        if( (int)v[i].getKind() == 3 ) cout<<"Kind:mace";
        if( (int)v[i].getKind() == 4 ) cout<<"Kind:staff";
        cout<<" Score:"<<v[i].getScore()<<endl;
    }
}










