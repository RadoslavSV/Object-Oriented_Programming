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

enum class MaterialType{
    herbs,       //=0
    ores,        //=1
    cloth,       //=2
    essence,     //=3
};

class Materials{
    MaterialType type;
    int quantity = 0;
    int slots = 0;  //used for occupied slots in Backpack

public:
    Materials();
    Materials(MaterialType, int);
    MaterialType getType();
    int getQuantity();
    int getSlots();
    void setType(MaterialType);
    void addQuantity(int);

    void printMaterial(); //write a function that print a material (prints its type and quantity)

};



