/// Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#include "VendingMachine_code.cpp"

#include <iostream>
using namespace std;

int main()
{
    Drink d1("Sprite", 4000, 500, 2.65);   //define object drink "Sprite" with 4000 clrs, 500ml and the price of $2.65
    d1.set_name("Fanta");                  //change its name to "Fanta"
    d1.set_price(1.75);                    //change its price to $1.75

    Drink d2("Cola", 5000, 250, 1.50);     //define more drinks through the constructor:
    Drink d3("Pepsi", 1000, 500, 0.75);
    Drink d4("Schweppes", 500, 250, 0.45);

    VendingMachine v1;                     //define v1 - object from type VendingMachine

    v1.add_drink(d1);                      //add those aforedefined drinks to the vending machine (v1)
    v1.add_drink(d2);
    v1.add_drink(d3);
    v1.add_drink(d4);

    v1.print_all_drinks();                 //prints all current drinks in the machine

    v1.buy_drink("Cola", 2.50);            //buys "Cola", because gives enough money
    v1.buy_drink("Fanta", 1.65);           //does not buy "Fanta", cause not enough money are inserted

    v1.print_all_drinks();                 //again print all drinks to show results

    cout<<"Income: $"<<v1.get_income();    //print the eventual income after all operations



    return 0;
}


