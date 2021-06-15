#include <assert.h>

#include <cstring>
#include <iostream>

#include "Error.hpp"
#include "TestCase.hpp"
#include "TestSuite.hpp"

using namespace std;

void testWarningError();

void testBuildError();

void testFailedAssertionError();

void testNoneError();

void assertTestCaseNameIsValid();

void assertTestCaseWithNoneErrorIsWorking();

void assertFailedAssertionTestCaseIsWorking();

void assertBuildFailedTestCaseIsWorking();

void assertWarningTestCaseIsWorking();

void assertTestSuiteNameIsWorking();

TestSuite createTestSuite();

void assertTestSuiteTestNameIsWorking();

void assertTestSuiteFilterFailingWithDifferentTestCasesIsWorking();

void assertTestSuiteGetByErrorTypeWithDifferentTestCasesIsWorking();

void assertTestSuiteFilterPassingWithDifferentTestCasesIsWorking();

void assertTestSuiteRemoveByErrorTypeIsWorkingWithDifferentCases();

void runTestEngineUnitTests() {
    cout << "Start executing test engine unit tests!" << endl;

    testNoneError();

    testWarningError();

    testBuildError();

    testFailedAssertionError();

    assertTestCaseNameIsValid();

    assertTestCaseWithNoneErrorIsWorking();

    assertFailedAssertionTestCaseIsWorking();

    assertBuildFailedTestCaseIsWorking();

    assertWarningTestCaseIsWorking();

    assertTestSuiteNameIsWorking();

    assertTestSuiteTestNameIsWorking();

    assertTestSuiteFilterFailingWithDifferentTestCasesIsWorking();

    assertTestSuiteGetByErrorTypeWithDifferentTestCasesIsWorking();

    assertTestSuiteFilterPassingWithDifferentTestCasesIsWorking();

    assertTestSuiteRemoveByErrorTypeIsWorkingWithDifferentCases();

    cout << "Finish executing test engine unit tests!" << endl;
}

void assertTestSuiteRemoveByErrorTypeIsWorkingWithDifferentCases() {
    TestSuite testSuite = createTestSuite();
    testSuite.add(TestCase("test5", Error::newWarning("Warning test")));

    testSuite.removeByErrorType(ErrorType::Warning);

    assert(testSuite.filterByErrorType(ErrorType::Warning).size() == 0);
    assert(testSuite.getTestsCount() == 3);

    testSuite.removeByErrorType(ErrorType::None);
    assert(testSuite.filterByErrorType(ErrorType::None).size() == 0);
    assert(testSuite.getTestsCount() == 2);
}

void assertTestSuiteFilterPassingWithDifferentTestCasesIsWorking() {
    TestSuite testSuite = createTestSuite();
    std::vector<TestCase> actualResult = testSuite.filterPassing();
    assert(actualResult.size() == 2);
    assert(actualResult[0].getName() == "test1");
    assert(actualResult[1].getName() == "test2");
}

void assertTestSuiteGetByErrorTypeWithDifferentTestCasesIsWorking() {
    TestSuite testSuite = createTestSuite();
    std::vector<TestCase> actualResult = testSuite.filterByErrorType(ErrorType::FailedAssertion);
    assert(actualResult.size() == 1);
    assert(actualResult[0].getName() == "test4");
}

void assertTestSuiteFilterFailingWithDifferentTestCasesIsWorking() {
    TestSuite testSuite = createTestSuite();
    std::vector<TestCase> actualResult = testSuite.filterFailing();
    assert(actualResult.size() == 3);
    assert(actualResult[0].getName() == "test2");
    assert(actualResult[1].getName() == "test3");
    assert(actualResult[2].getName() == "test4");
}

void assertTestSuiteTestNameIsWorking() {
    TestSuite testSuite = createTestSuite();
    testSuite.setName("new name");
    assert(testSuite.getName() == "new name");
}

TestSuite createTestSuite() {
    TestCase test1 = TestCase("test1", Error::newNone());
    TestCase test2 = TestCase("test2", Error::newWarning("Warning"));
    TestCase test3 = TestCase("test3", Error::newBuildFailed("Build"));
    TestCase test4 = TestCase("test4", Error::newFailedAssertion("Assertion"));

    TestSuite testSuite("test suite 1");
    testSuite.add(test1);
    testSuite.add(test2);
    testSuite.add(test3);
    testSuite.add(test4);

    return testSuite;
}

void assertTestSuiteNameIsWorking() {
    TestSuite testSuite("test suite");
    assert(testSuite.getName() == "test suite");
}

void assertWarningTestCaseIsWorking() {
    TestCase testCase("Failing test", Error::newBuildFailed("Warning on Error::getType"));
    assert(testCase.getErrorMessage() == std::string("Warning on Error::getType"));
    assert(testCase.getErrorType() == ErrorType::BuildFailed);
    assert(testCase.hasError());
    assert(testCase.isPassing() == false);
}

void assertBuildFailedTestCaseIsWorking() {
    TestCase testCase("Failing test", Error::newBuildFailed("Build Failed on Error::getType"));
    assert(testCase.getErrorMessage() == std::string("Build Failed on Error::getType"));
    assert(testCase.getErrorType() == ErrorType::BuildFailed);
    assert(testCase.hasError());
    assert(testCase.isPassing() == false);
}

void assertFailedAssertionTestCaseIsWorking() {
    TestCase testCaseFailed("Failing test", Error::newFailedAssertion("Failed on Error::getType"));
    assert(testCaseFailed.getErrorMessage() == std::string("Failed on Error::getType"));
    assert(testCaseFailed.getErrorType() == ErrorType::FailedAssertion);
    assert(testCaseFailed.hasError());
    assert(testCaseFailed.isPassing() == false);
}

void assertTestCaseWithNoneErrorIsWorking() {
    Error errNone = Error::newNone();
    TestCase testCaseNone("Passing test", errNone);
    assert(testCaseNone.getErrorType() == ErrorType::None);
    assert(testCaseNone.hasError() == false);
    assert(testCaseNone.isPassing());
    assert(testCaseNone.getErrorMessage() == "");
}

void assertTestCaseNameIsValid() {
    Error errNone = Error::newNone();
    TestCase testCaseNone("Passing test", errNone);
    assert(testCaseNone.getName() == "Passing test");
}

void testNoneError() {
    Error errNone = Error::newNone();
    assert(errNone.getType() == ErrorType::None);
    assert(errNone.hasMessage() == false);
    assert(errNone.getMessage() == nullptr);
}

void testFailedAssertionError() {
    Error error = Error::newFailedAssertion("Assertion failed!");
    assert(error.getType() == ErrorType::FailedAssertion);
    assert(error.hasMessage() == true);
    assert(strcmp(error.getMessage(), "Assertion failed!") == 0);
}

void testBuildError() {
    Error errBuild = Error::newBuildFailed("Failed to build Homework5");
    assert(errBuild.getType() == ErrorType::BuildFailed);
    assert(errBuild.hasMessage() == true);
    assert(strcmp(errBuild.getMessage(), "Failed to build Homework5") == 0);
}

void testWarningError() {
    Error error = Error::newWarning("Warning in the project.");
    assert(error.getType() == ErrorType::Warning);
    assert(error.hasMessage() == true);
    assert(strcmp(error.getMessage(), "Warning in the project.") == 0);
}
