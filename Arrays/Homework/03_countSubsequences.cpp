#include <iostream>
#include <vector>
using namespace std;

int countSubsequences(vector<int> collection);
void runUnitTests();

int main()
{
    // When you implement the method countSubsequences run the program and your logic will be tested automatically for a second
    // You will see how many of the test failed and how many of them passed.
    // If the test failed you will see the expected output and you output.
    runUnitTests();
}

int countSubsequences(vector<int> sequence)
{
    return -1;
}

void runUnitTests()
{
    // TODO: add the other inputs and try to catch the edge cases
    vector<vector<int>> inputs = {
        {1, 2, 2, 1},
        {5, 0, 6, 0, 5},
        {1, 3, 8, 3, 1, 4, 5, 4, 1, 4},
        {1, 2, 3, 4, 5}};

    // TODO: add the other expected outputs here
    vector<int> expectedOutputs = {1, 2, 5, -1};

    for (int i = 0; i < inputs.size(); i++)
    {
        // Arrange
        vector<int> input = inputs[i];
        int expectedOutput = expectedOutputs[i];

        // Act
        int actualOutput = countSubsequences(input);

        // Assert
        if (actualOutput == expectedOutput)
        {
            cout << "Test #" << i + 1 << " passed" << endl;
        }
        else
        {
            cout << "Test #" << i + 1 << " failed" << endl;
            cout << "\t Expected output: " << expectedOutput << endl;
            cout << "\t Actual output: " << actualOutput << endl;
        }
    }
}