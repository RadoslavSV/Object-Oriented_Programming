/// Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#include "drink_code.cpp"  //add the source file with the definitions and methods of "drink"
#include "drink.hpp"
#include "VendingMachine.hpp"
#include "myStrFunctions.hpp"  //use my implementations of <string.h> functions
#include <iostream>
using namespace std;

VendingMachine::VendingMachine() : drinks(NULL), cnt(0) {}

VendingMachine::VendingMachine(Drink drinks[], const int &cnt) : cnt(cnt)
{
    this->drinks = new Drink[cnt];
    for(int i=0; i<cnt; i++)
    {
        this->drinks[i] = drinks[i];
    }
}

VendingMachine::VendingMachine(const VendingMachine& from) : cnt(from.cnt)
{
    delete[] drinks;
    this->drinks = new Drink[cnt];
    for(int i=0; i<cnt; i++)
    {
        this->drinks[i] = from.drinks[i];
    }
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
    delete[] drinks;
    this->drinks = new Drink[cnt];
    for(int i=0; i<cnt; i++)
    {
        this->drinks[i] = from.drinks[i];
    }
}

VendingMachine::~VendingMachine()
{
    delete[] drinks;
}

void VendingMachine::set_drinks(Drink newDrinks[], const int &newCount)
{
    if(newCount>0) cnt = newCount;
    else cout<<"Error"<<endl;

    delete[] drinks;
    this->drinks = new Drink[cnt];
    for(int i=0; i<cnt; i++)
    {
        this->drinks[i] = newDrinks[i];
    }
}

int VendingMachine::get_cnt()
{
    return cnt;
}

Drink *VendingMachine::get_drinks()
{
    return drinks;
}

void VendingMachine::print_all_drinks()
{
    for (int i=0; i<cnt; i++)
    {
        drinks[i].print_drink();
    }
    cout<<endl;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
    Drink *newDrinks = new Drink[cnt + 1];
    for (int i=0; i<cnt; i++)
    {
        newDrinks[i] = drinks[i];
    }


    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<StrLen(to_add.get_name()); j++)
        {
            if( newDrinks[i].get_name()[j] == to_add.get_name()[j] )
            {
                return false;
            }
        }
    }

    newDrinks[cnt] = to_add;
    cnt++;
    delete[] drinks;
    drinks = newDrinks;

    return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
    int index=0;
    bool doExist=false;  //checks to see whether the beverage exists or not
    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<StrLen(drink_name); j++)
        {
            if( drinks[i].get_name()[j] != drink_name[j] )
            {
                index++;
                break;
            }
            else doExist=true;
        }
        if(doExist==true) break;
    }

    if(doExist==false) return 2;   //the beverage does not exist
    else
    {
        if(money < drinks[index].get_price())
        {
            income += money;
            return 1;
        }
        else if(money >= drinks[index].get_price())
        {
            Drink *newDrinks = new Drink[cnt - 1];
            for(int i=0; i<index; i++)
            {
                newDrinks[i] = drinks[i];
            }
            for (int i=index; i<cnt - 1; i++)
            {
                newDrinks[i] = drinks[i + 1];
            }
            delete[] drinks;
            cnt--;
            drinks = newDrinks;

            income += money;
            return 0;
        }
    }
}

double VendingMachine::get_income() const
{
    return this->income;
}



