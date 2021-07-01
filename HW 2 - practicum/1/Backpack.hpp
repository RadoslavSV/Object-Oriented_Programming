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
#include <cmath>

template <class Type>
class Backpack{
    vector < Type > v;
    int slots = 0;
public:
    int getSlots();
    void addMaterialToBackpack(Materials);
    void addMoneyToBackpack(Money);
    void removeFromBackpack(int);  //removes a material from the backpack by given index
    void removeMoneyFromBackpack(int,int,int); //removes money from backpack by given gold, silver and copper as parameters
    void clearBackpack();
    bool isBackpackFull();
    bool isBackpackEmpty();

    void printMaterials();
    void printMoney();

};

template <class Type>
int Backpack<Type>::getSlots()
{
    return this->slots;
}

template <class Type>
void Backpack<Type>::addMaterialToBackpack(Materials stuff)
{
    if( slots < 16 )
    {
        v.push_back(stuff);
        slots++;
    }
}

template <class Type>
void Backpack<Type>::addMoneyToBackpack(Money cash)
{
    v.push_back(cash);
}

template <class Type>
void Backpack<Type>::removeFromBackpack(int n)
{
    v.erase( v.begin() + n );
    slots--;
}

template <class Type>
void Backpack<Type>::removeMoneyFromBackpack(int g, int s, int c)
{
    int totalGold = 0;
    int totalSilver = 0;
    int totalCopper = 0;
    for(int i=0; i<v.size();i++)
    {
        totalGold += v[i].getGold();
        totalSilver += v[i].getSilver();
        totalCopper += v[i].getCopper();
    }
    totalGold -= g;
    totalSilver -= s;
    totalCopper -= c;
    if(totalCopper>99)
    {
        while(totalCopper>99)
        {
            totalSilver++;
            totalCopper -= 100;
        }
    }
    if(totalSilver>99)
    {
        while(totalSilver>99)
        {
            totalGold++;
            totalSilver -= 100;
        }
    }
    if(totalCopper<0)
    {
        while(totalCopper<-99)
        {
        totalSilver--;
        totalCopper += 100;
        }
    }
    if(totalSilver<0)
    {
        while(totalSilver<-99)
        {
        totalGold--;
        totalSilver += 100;
        }
    }
    if(totalGold<0)
    {
        totalGold=0;
        totalSilver=0;
        totalCopper=0;
    }

    if(totalSilver<0)
    {
        totalGold--;
        totalSilver=100-fabs(totalSilver);
    }
    if(totalCopper<0)
    {
        totalSilver--;
        totalCopper=100-fabs(totalCopper);
    }
    Money ca; //create a new money object; its initial gold, silver and copper are all zero
    ca.addGold(totalGold); //give it the amount of total accumulated gold
    ca.addSilver(totalSilver);//analogically with the silver...
    ca.addCopper(totalCopper);//...and with the copper
    v.clear();//clear the whole original vector
    v.push_back(ca);//and give it a single value of that aforecreated object of type money
}

template <class Type>
void Backpack<Type>::clearBackpack()
{
    v.clear();
    slots = 0;
}

template <class Type>
bool Backpack<Type>::isBackpackFull()
{
    if( getSlots() == 16 ) return true;
    else if( getSlots() < 16 ) return false;
}

template <class Type>
bool Backpack<Type>::isBackpackEmpty()
{
    if( getSlots() == 0 ) return true;
    else return false;
}

template <class Type>
void Backpack<Type>::printMaterials()
{
    for(int i=0; i<v.size();i++)
    {
        if( (int)v[i].getType()==0 ) cout<<"Type:herbs Quantity:"<<v[i].getQuantity()<<endl;
        if( (int)v[i].getType()==1 ) cout<<"Type:ores Quantity:"<<v[i].getQuantity()<<endl;
        if( (int)v[i].getType()==2 ) cout<<"Type:cloth Quantity:"<<v[i].getQuantity()<<endl;
        if( (int)v[i].getType()==3 ) cout<<"Type:essence Quantity:"<<v[i].getQuantity()<<endl;
    }
}

template <class Type>
void Backpack<Type>::printMoney()
{
    int totalGold = 0;
    int totalSilver = 0;
    int totalCopper = 0;
    for(int i=0; i<v.size();i++)
    {
        totalGold += v[i].getGold();
        totalSilver += v[i].getSilver();
        totalCopper += v[i].getCopper();
    }
    if(totalCopper>99)
    {
        while(totalCopper>99)
        {
            totalSilver++;    //silver increases
            totalCopper -= 100;
        }
    }
    if(totalSilver>99)
    {
        while(totalSilver>99)
        {
            totalGold++;    //gold increases
            totalSilver -= 100;
        }
    }
    cout<<"Gold:"<<totalGold<<" Silver:"<<totalSilver<<" Copper:"<<totalCopper<<endl;
}


































