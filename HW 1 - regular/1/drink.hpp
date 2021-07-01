/// Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#pragma once

class Drink {
private:
    char *name = nullptr;
    double quantity;
    int calories;
    double price;

public:
    Drink();  //add a default constructor
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);  //constructor
    Drink(const Drink&);  //copy constructor
    Drink& operator=(const Drink&);  //operator=
    ~Drink();  //add a destructor as well to form the big 4

    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;

    void set_name(const char* new_name);
    void set_calories(int new_calories);
    void set_quantity(double new_quantity);
    void set_price(double new_price);

    void print_drink();  //my own function that prints a drink with its characteristics

};
