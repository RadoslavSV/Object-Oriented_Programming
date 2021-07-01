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

#include "materials.hpp"

Materials::Materials(): type(MaterialType::herbs), quantity(0) {} //assume that the default type of material is herbs

Materials::Materials(MaterialType type, int quantity)
{
    this->type = type;
    this->quantity = quantity;
}

MaterialType Materials::getType()
{
    return this->type;
}

int Materials::getQuantity()
{
    return this->quantity;
}

int Materials::getSlots()
{
    slots = 0;
    if(quantity>1) slots=1;
    int currentQuantity = quantity;
    if( (int)getType()==3 && currentQuantity>10) //type is essence and is more than 10
    {
        while( currentQuantity > 10 )
        {
            slots++;
            currentQuantity -= 10;
        }
    }
    if( (int)getType()==0 || (int)getType()==1 || (int)getType()==2 && currentQuantity>20 ) //type is herbs, ores or cloth and is more than 20
    {
        while( currentQuantity > 20 )
        {
            slots++;
            currentQuantity -= 20;
        }
    }

    return slots;
}

void Materials::setType(MaterialType type)
{
    this->type = type;
}

void Materials::addQuantity(int quantity)
{
    this->quantity += quantity;
}

void Materials::printMaterial()
{
    cout<<"Type:";
    if((int)getType()==0) cout<<"herbs"<<" ";
    if((int)getType()==1) cout<<"ores"<<" ";
    if((int)getType()==2) cout<<"cloth"<<" ";
    if((int)getType()==3) cout<<"essence"<<" ";
    cout<<" Quantity:";
    cout<<getQuantity()<<endl;
}



