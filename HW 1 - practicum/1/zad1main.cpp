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



#include <iostream>
using namespace std;

#include "zad1code.cpp"

int main()
{   //random examples of the constructors and the methods below:
    Date d1(13, 7, 2014);
    d1.printDate();

    Date d2;
    d2.printDate();

    d1.addDays(23);
    d1.printDate();

    d1.removeDays(12);
    d1.printDate();

    cout<<d1.isLeapYear()<<" "<<d2.isLeapYear()<<endl;

    cout<<d1.daysToXmas()<<" "<<d2.daysToXmas()<<endl;

    cout<<d1.daysToNewYear()<<" "<<d2.daysToNewYear()<<endl;

    cout<<d1.daysToExactDate(28,7,2016)<<" "<<d2.daysToExactDate(4,1,2000)<<endl;

    Date d3(21, 2, 2017), d4(18, 3, 2017);
    cout<<d3.isLaterThan(d4)<<endl;


    return 0;
}
