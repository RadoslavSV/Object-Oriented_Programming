/// Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#pragma once

class VendingMachine {
private:
    Drink *drinks;
    int cnt;

public:
    VendingMachine();  //default constructor
    VendingMachine(Drink *drinks, const int &cnt);  //add a constructor with parameters
    VendingMachine(const VendingMachine& from);  //copy constructor
    VendingMachine& operator=(const VendingMachine& from);  //operator=
    ~VendingMachine(); //add a destructor

    void set_drinks(Drink newDrinks[], const int &newCount);
    int get_cnt();
    Drink *get_drinks();

    void print_all_drinks();

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);
    double income; //a double variable for that will serve as a container for the income
    double get_income() const;

};
