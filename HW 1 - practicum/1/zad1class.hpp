/**
* Solution to homework assignment 1
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

class Date{
public:
    int day, month, year;

    Date ();
    Date (int, int, int);
    void printDate();
    void addDays(int);
    void removeDays(int);
    bool isLeapYear();
    int daysToXmas();
    int daysToNewYear();
    int daysToExactDate(int, int, int);
    bool isLaterThan(Date);

};




