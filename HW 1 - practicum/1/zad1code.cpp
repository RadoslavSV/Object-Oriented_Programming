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



#include "zad1class.hpp"

Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void Date::printDate()
{
    cout<<day<<"."<<month<<"."<<year<<endl;
}

void Date::addDays(int n)
{
    day += n;
    if(month==4 || month==6 || month == 9 || month==11)   //months that have no more than 30 days
    {
        while(day>30)
        {
            int rem = day-30;
            day = 0;
            day += rem;
            month++;
        }
    }
    else
    if(month==2)      //February has exactly 28
    {
        while(day>28)
        {
            int rem = day-28;
            day = 0;
            day += rem;
            month++;
        }
    }
    else              //others have 31
    {
        while(day>31)
        {
            int rem = day-31;
            day = 0;
            day += rem;
            month++;
        }
    }
}

void Date::removeDays(int n)
{
    day -= n;
    if(month==4 || month==6 || month == 9 || month==11)
    {
        while(day<=0)
        {
            int rem = day;
            day = 30;
            day += rem;
            month--;
        }
    }
    else
    if(month==2)
    {
        while(day<=0)
        {
            int rem = day;
            day = 28;
            day += rem;
            month--;
        }
    }
    else
    {
        while(day<=0)
        {
            int rem = day;
            day = 31;
            day += rem;
            month--;
        }
    }
}

bool Date::isLeapYear()
{
    if( year%4==0 && year%100==0 && year%400==0 ) return true;
    else if( year%4==0 && year%100==0 && year%400!=0 ) return false;
    else if( year%4==0 && year%100!=0 && year%400!=0 ) return true;
    else return false;
}

int Date::daysToXmas()
{
    int total=0;   //serves as a counter for total past days
    int m = month;
    int d = day;
    while(m>0)
    {
        m--;
        if(m==2) total += 28;         //accumulate the corresponding already-past months' days into the total
        if(m==4 || m==6 || m==9 || m==11) total+=30;
        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) total += 31;
    }
    total += d;

    if(isLeapYear()) 360-total;    //use the aforewritten method; in a leap year, Dec 25th is the 360th day

    if( (359-total)>=0 ) return 359-total;
    else return 365-(total-359);   //applies to the days from Dec 26th to Dec 31st
}

int Date::daysToNewYear()
{   //identical to the previous method used for Christmas
    int total=0;
    int m = month;
    int d = day;
    while(m>0)
    {
        m--;
        if(m==2) total += 28;
        if(m==4 || m==6 || m==9 || m==11) total+=30;
        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) total += 31;
    }
    total += d;

    if(isLeapYear()) return 366-total;

    return 365-total;
}

int Date::daysToExactDate(int d, int m, int y)
{
    int total1=0;
    int mo = month;
    int da = day;
    while(mo>0)
    {
        mo--;
        if(mo==2) total1 += 28;
        if(mo==4 || mo==6 || mo==9 || mo==11) total1+=30;
        if(mo==1 || mo==3 || mo==5 || mo==7 || mo==8 || mo==10 || mo==12) total1 += 31;
    }
    total1 += da;

    int total=0;
    while(m>0)
    {
        m--;
        if(m==2) total += 28;
        if(m==4 || m==6 || m==9 || m==11) total+=30;
        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) total += 31;
    }
    total += d;

    if(year!=y)      //in case of comparing dates in different years
    {
        int difference = 0;
        if(year>y) difference = year-y;   //instead of using "abs" function
        else difference = y-year;
        total += difference*365;
    }

    if(total1 >= total) return total1 - total;   //again instead of absolute value
    else return total-total1;
}

bool Date::isLaterThan(Date dd)
{
    if(dd.year>year) return true;
    else if(dd.year==year && dd.month>month) return true;
    else if(dd.year==year && dd.month==month && dd.day>day) return true;
    else return false;
}




