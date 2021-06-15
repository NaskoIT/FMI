#include "TestSuite.hpp"

bool isPassing(const TestCase &testCase) {
    return testCase.isPassing();
}

bool isFailing(const TestCase &testCase) {
    return testCase.hasError();
}

TestSuite::TestSuite(std::string name) {
    this->name = name;
}

void TestSuite::add(const TestCase &testCase) {
    this->testCases.push_back(testCase);
}

std::vector<TestCase> TestSuite::filter(bool (*predicate)(const TestCase &)) const {
    std::vector<TestCase> targetTestCases;
    for (const TestCase &testCase : testCases) {
        if (predicate(testCase)) {
            targetTestCases.push_back(testCase);
        }
    }

    return targetTestCases;
}

std::vector<TestCase> TestSuite::filterPassing() const {
    return filter(isPassing);
}

std::vector<TestCase> TestSuite::filterFailing() const {
    return filter(isFailing);
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType errorType) const {
    std::vector<TestCase> targetTestCases;
    for (const TestCase &testCase : testCases) {
        if (testCase.getErrorType() == errorType) {
            targetTestCases.push_back(testCase);
        }
    }

    return targetTestCases;
}

void TestSuite::removeByErrorType(ErrorType errorType) {
    std::vector<TestCase> tempTestCases;
    for (int i = 0; i < testCases.size(); ++i) {
        if(testCases[i].getErrorType() == errorType) {
            testCases.erase(testCases.begin() + i);
            i--;
        }
    }
}

std::string TestSuite::getName() const {
    return this->name;
}

void TestSuite::setName(const std::string &name) {
    this->name = name;
}

int TestSuite::getTestsCount() const {
    return this->testCases.size();
}

TestSuite::TestSuite(const TestSuite &testSuite) {
    copy(testSuite);
}

TestSuite &TestSuite::operator=(const TestSuite &testSuite) {
    copy(testSuite);
}

void TestSuite::copy(const TestSuite &testSuite) {
    name = testSuite.name;
    testCases = testSuite.testCases;
}
