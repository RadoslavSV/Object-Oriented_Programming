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

class Money{
    int gold = 0;
    int silver = 0;
    int copper = 0;

public:
    Money(int gold = 0, int silver = 0, int copper = 0);
    int getGold();
    int getSilver();
    int getCopper();
    void addGold(int);
    void addSilver(int);
    void addCopper(int);

    void printMoney(); //write a function that print money (prints its gold, silver and copper quantities)

};





