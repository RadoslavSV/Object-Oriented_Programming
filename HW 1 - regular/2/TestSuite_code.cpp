///Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#include "TestSuite.hpp"
#include <cstring>

TestSuite::TestSuite()   //default constructor, makes name an empty string
{
    this->name = "";
    v.clear();          //the initial vector (container for multiple test cases) will be empty
}

TestSuite::TestSuite(std::string name)   //constructor with parameter that gives name to the Test suite
{
    this->name = name;
    v.clear();
}

string TestSuite::getName() const
{
    return this->name;
}

void TestSuite::setName(const std::string& newName)
{
    this->name = newName;
}

void TestSuite::add(const TestCase& tc)
{
    v.push_back(tc);   //add the new test case (tc) in the first empty position in the dynamic array

    for(int i=0; i<v.size(); i++)      //we need to remove all repeating test cases
    {
        for(int j=0; j<v.size(); j++)
        {
            if( i<j && v[i].getName() == v[j].getName() )
            {
                v.erase(v.begin()+j);
                i--;
                j--;
            }
        }
    }
}

void TestSuite::printAllTestCases()
{
    for(int i=0; i<v.size(); i++) cout<<v[i].getName()<<endl;
}

std::vector<TestCase> TestSuite::filterPassing() const
{
    vector<TestCase> newV;  //create a new vector to collect all needed test cases (those that have passed)
    newV.clear();   //initially make it an empty one
    for(int i=0; i<v.size(); i++)
    {
        if( (bool)v[i].isPassing()==true )   //for each "passing" test case of the original vector
        {
            newV.push_back(v[i]);            //insert it into the new vector
        }
    }
    return newV;  //returns the new vector
}

std::vector<TestCase> TestSuite::filterFailing() const
{
    vector<TestCase> newV;
    newV.clear();
    for(int i=0; i<v.size(); i++)
    {
        if( (bool)v[i].isPassing()==false )  //for every "not-passing/failing" test case
        {
            newV.push_back(v[i]);
        }
    }
    return newV;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType et) const
{
    vector<TestCase> newV;
    newV.clear();
    for(int i=0; i<v.size(); i++)
    {
        if( (int)v[i].getErrorType()==(int)et )  //for each test case of that particular error type
        {
            newV.push_back(v[i]);
        }
    }
    return newV;
}

void TestSuite::removeByErrorType(ErrorType et)
{//does not create a new vector, but erase elements from the original one
    for(int i=0; i<v.size(); i++)
    {
        if( (int)v[i].getErrorType()==(int)et )  //for every test case of that particular error
        {
            v.erase(v.begin()+i);  //just remove the value that belongs to this container
        }
    }
}



