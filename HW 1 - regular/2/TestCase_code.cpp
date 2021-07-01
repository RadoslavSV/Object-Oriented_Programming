///Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#include "TestCase.hpp"
#include <cstring>


TestCase::TestCase(const std::string& name, const Error& error)
{
    this->name = name;
    this->error.setMessage(error.getMessage());    //manually set the message and the type
    this->error.setType(error.getType());
}

string TestCase::getName() const
{
    return this->name;
}

bool TestCase::hasError() const
{
    if((int)error.getType()==0) return 0;  //0 stands for ErrorType::None
    else return 1;   //1, 2, 3 correspondingly stand for ErrorType::BuildFailed, Warning, FailedAssertion
}

bool TestCase::isPassing() const
{
    if((int)error.getType()==0 || (int)error.getType()==2) return 1;
    else return 0;
}

ErrorType TestCase::getErrorType() const
{
    switch((int)error.getType())
    {
        case 0: return ErrorType::None;
        break;
        case 1: return ErrorType::BuildFailed;
        break;
        case 2: return ErrorType::Warning;
        break;
        case 3: return ErrorType::FailedAssertion;
    }
}

string TestCase::CHECKgetErrorType() const
{
    switch((int)getErrorType())   //here we check what value does "getErrorType()" return in integer
    {
        case 0: return "None";
        break;
        case 1: return "Build Failed";
        break;
        case 2: return "Warning";
        break;
        case 3: return "Failed Assertion";
    }
}

string TestCase::getErrorMessage() const
{
    return this->error.getMessage(); //in the case of 'None', returns an empty string
}



