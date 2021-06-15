
#include "TestCase.hpp"

TestCase::TestCase(const std::string &name, const Error &error) :
        name(name),
        error(error) {}

std::string TestCase::getName() const {
    return name;
}

bool TestCase::isPassing() const {
    return error.getType() == ErrorType::None || error.getType() == ErrorType::Warning;
}

bool TestCase::hasError() const {
    return error.getType() != ErrorType::None;
}

ErrorType TestCase::getErrorType() const {
    return error.getType();
}

std::string TestCase::getErrorMessage() const {
    const char *errorMessage = error.getMessage();
    if (errorMessage == nullptr) {
        return std::string();
    } else {
        return std::string(errorMessage);
    }
}

TestCase &TestCase::operator=(const TestCase &testCase) {
    copy(testCase);
}

TestCase::TestCase(const TestCase &testCase) {
    copy(testCase);
}

void TestCase::copy(const TestCase &testCase) {
    name = testCase.name;
    error = testCase.error;
}

