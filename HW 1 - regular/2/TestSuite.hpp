///Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

#include "TestCase.hpp"

/// TestSuite is a collection of many Test Cases
/// A Test Suite has a name so we can know which problem it's from
class TestSuite {
    /// Feel free to add additional private/public methods/fields
    private:
    string name;


    public:
    vector<TestCase> v;
    /// Constructor we'll need for initializing the TestSuite
    TestSuite();
    TestSuite(std::string name);

    /// Add a new test case to the collection of cases
    void add(const TestCase&);

    void printAllTestCases(); //add a function that prints all inserted test cases' names into a single test suite

    /// Retrieve the test cases, which are passing
    std::vector<TestCase> filterPassing() const;

    /// Retrieve the test cases, which are failing (those which function isPassing() returns false)
    std::vector<TestCase> filterFailing() const;

    /// Retrieve the test cases, which have the specified error type
    std::vector<TestCase> filterByErrorType(ErrorType) const;

    /// Remove all test cases with the given error type
    void removeByErrorType(ErrorType);

    /// Retrieve the name of the TestSuite
    std::string getName() const;

    /// Change the name of the TestSuite
    void setName(const std::string&);
};
