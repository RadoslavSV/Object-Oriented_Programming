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

template <class Typename>
class Inventory{
    Typename inventory;
public:
    void setInventory(Typename);
    Typename getInventory();
    int getSlots();


};

template <class Typename>
void Inventory<Typename>::setInventory(Typename inv)
{
    this->inventory = inv;
}

template <class Typename>
Typename Inventory<Typename>::getInventory()
{
    return this->inventory;
}

template <class Typename>
int Inventory<Typename>::getSlots()
{
    return this->inventory.getSlots();
}

template <class Typename>
bool operator==(Typename lhs, Typename rhs)
{
    return lhs.getSlots() == rhs.getSlots();  //compares the two inventories by their sizes (taken slots)
}

template <class Typename>
bool operator!=(Typename lhs, Typename rhs)
{
    return !( lhs.getSlots() == rhs.getSlots() );  //compares the two inventories by their sizes (taken slots)
}














