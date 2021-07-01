/// Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#pragma once
#include "drink.hpp"
#include "VendingMachine.hpp"
#include "myStrFunctions.hpp"  //use my implementations of some <string.h> functions
#include <iostream>
using namespace std;

Drink::Drink() : name(NULL), quantity(0.0), calories(0), price(0.0) {}

Drink::Drink(const char *init_name, const int init_calories, const double& init_quantity, const double& init_price)
{
    int nameCount = StrLen(init_name);
    this->name = new char[nameCount + 1];
    StrnCpy(this->name, init_name, nameCount + 1);

    calories = init_calories;
    quantity = init_quantity;
    price = init_price;

}

Drink::Drink(const Drink& other)
{
    delete[] name;
    int nameCount = StrLen(other.name);
    this->name = new char[nameCount + 1];
    StrnCpy(this->name, name, nameCount + 1);

    calories = other.calories;
    quantity = other.quantity;
    price = other.price;
}

Drink& Drink::operator=(const Drink& other)
{
    delete[] name;
    if(this!=&other)
    {
        set_name(other.name);
        calories = other.calories;
        quantity = other.quantity;
        price = other.price;
    }
    return *this;
}

Drink::~Drink()
{
    delete[] name;
}

const char* Drink::get_name() const
{
    return name;
}

int Drink::get_calories() const
{
    return calories;
}

double Drink::get_quantity() const
{
    return quantity;
}

double Drink::get_price() const
{
    return price;
}

void Drink::set_name(const char* new_name)
{
    delete[] name;
    int nameCount = StrLen(new_name);
    this->name = new char[nameCount + 1];
    StrnCpy(this->name, new_name, nameCount + 1);
}

void Drink::set_calories(int new_calories)
{
    this->calories = new_calories;
}

void Drink::set_quantity(double new_quantity)
{
    this->quantity = new_quantity;
}

void Drink::set_price(double new_price)
{
    this->price = new_price;
}

void Drink::print_drink()
{
    cout<<"Drink: "<<name<<"   calories: "<<calories<<"   quantity: "<<quantity<<"ml   price: $"<<price<<endl;
}





