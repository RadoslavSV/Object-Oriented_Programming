/// Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#pragma once
#include <iostream>
using namespace std;

//implement string.h functions

void StrnCpy(char d[], const char s[], int q)   //my implementation of strncpy
{
    int i=0;
    for(;i<q;i++)
    {
        d[i]=s[i];
    }
    d[i]='\0';
    return;
}

int StrLen(const char str[])     //my implementation of strlen
{
    int i=0;
    for(;str[i]!='\0';i++);
    return i;
}
