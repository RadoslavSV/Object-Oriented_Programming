///Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#include <assert.h>

#include <cstring>
#include <iostream>

#include "Error_code.cpp"
#include "TestCase_code.cpp"
#include "TestSuite_code.cpp"
using namespace std;

void runTests() {
    Error errNone = Error::newNone();
//    assert(errNone.getType() == ErrorType::None);
//    assert(errNone.hasMessage() == false);

    Error errBuild = Error::newBuildFailed("Failed to build Homework5");
//    assert(errBuild.getType() == ErrorType::BuildFailed);
//    assert(errBuild.hasMessage() == true);
//    assert(strcmp(errBuild.getMessage(), "Failed to build Homework5") == 0);
    Error errWarning = Error::newWarning("I have to warn you...");
    Error errFail = Error::newFailedAssertion("You've failed!");

    TestCase testCaseNone("Passing test", errNone);
    TestCase testCase2("Not passing test", errBuild);
    TestCase testCase3("Achtung!", errWarning);
    TestCase testCase4("Failing test", Error::newFailedAssertion("Failed on Error::getType"));
    assert(testCaseNone.getErrorType() == ErrorType::None);
    assert(testCaseNone.hasError() == false);
    cout<<testCaseNone.hasError()<<endl; ///0
    cout<<testCase2.hasError()<<endl;///1
    cout<<testCase3.hasError()<<endl;///1
    cout<<testCase4.hasError()<<endl;///1
    cout<<endl;
    cout<<testCaseNone.isPassing()<<endl;///1
    cout<<testCase2.isPassing()<<endl;///0
    cout<<testCase3.isPassing()<<endl;///1
    cout<<testCase4.isPassing()<<endl;///0
    cout<<endl;
    cout<<testCaseNone.CHECKgetErrorType()<<endl;///None
    cout<<testCase2.CHECKgetErrorType()<<endl;///Build Failed
    cout<<testCase3.CHECKgetErrorType()<<endl;///Warning
    cout<<testCase4.CHECKgetErrorType()<<endl;///Failed Assertion
    cout<<endl;
    cout<<testCaseNone.getErrorMessage()<<endl;///
    cout<<testCase2.getErrorMessage()<<endl;///Failed to build Homework5
    cout<<testCase3.getErrorMessage()<<endl;///I have to warn you...
    cout<<testCase4.getErrorMessage()<<endl;///Failed on Error::getType
    cout<<endl;

    TestCase testCaseFailed("Failing test", Error::newFailedAssertion("Failed on Error::getType"));
//    assert(testCaseFailed.getErrorMessage() == std::string("Failed on Error::getType"));

    TestSuite suitecase("unknown Suite");
    cout<<suitecase.getName()<<endl;
    suitecase.setName("VIP Suite");
    cout<<suitecase.getName()<<endl<<endl;

    TestSuite suite("Suite 1");

    suite.add(testCaseNone);
    suite.add(testCaseNone); //the "add" method does not add certain test cases more than once
    suite.add(testCaseNone); // - || -
    suite.add(testCaseFailed);
    suite.add(testCaseFailed); // - || -
    suite.add(testCaseNone);   // - || -

    suite.printAllTestCases();///Passing test
                              ///Failing test
    cout<<endl;
    suite.removeByErrorType(ErrorType::None); //removes all errors of type "None"
    suite.printAllTestCases();///Failing test

    suite.filterByErrorType(ErrorType::None);
    suite.filterByErrorType(ErrorType::FailedAssertion);
//    assert(suite.filterPassing().size() == 2);
}

int main() {
    runTests();
    cout << endl << "Success!\n";

    return 0;
}
