#include <assert.h>

#include <cstring>
#include <iostream>

#include "Error.hpp"
#include "TestCase.hpp"
#include "TestSuite.hpp"

void runTests() {
    Error errNone = Error::newNone();
    assert(errNone.getType() == ErrorType::None);
    assert(errNone.hasMessage() == false);

    Error errBuild = Error::newBuildFailed("Failed to build Homework5");
    assert(errBuild.getType() == ErrorType::BuildFailed);
    assert(errBuild.hasMessage() == true);
    assert(strcmp(errBuild.getMessage(), "Failed to build Homework5") == 0);

    TestCase testCaseNone("Passing test", errNone);
    assert(testCaseNone.getErrorType() == ErrorType::None);
    assert(testCaseNone.hasError() == false);

    TestCase testCaseFailed("Failing test", Error::newFailedAssertion("Failed on Error::getType"));
    assert(testCaseFailed.getErrorMessage() == std::string("Failed on Error::getType"));

    TestSuite suite("Suite 1");
    suite.add(testCaseNone);
    suite.add(testCaseNone);
    suite.add(testCaseFailed);
    assert(suite.filterPassing().size() == 2);
}

int main() {
    runTests();
    std::cout << "Success!\n";
}
