#include <iostream>
#include <vector>
using namespace std;

bool isTriangleSequence(vector<int> collection);
void runUnitTests();

int main()
{
    // When you implement the method isTriangleSequence run the program and your logic will be tested automatically for a second
    // You will see how many of the test failed and how many of them passed.
    // If the test failed you will see the difference between expected output and your output.
    runUnitTests();
}

bool isTriangleSequence(vector<int> collection)
{
    // TODO: implement this function
    return false;
}

void runUnitTests()
{
    // TODO: add the other inputs and try to catch the edge cases
    vector<vector<int>> inputs = {
        {9, 8, 3, 4, 2, 1, 6, 5},
        {5, 5, 0, 5, 5},
        {1, 2, 3, 6, 8, 7},
        {-10, -3, 5, 10, 3},
        {10, 10, 20, 20, 30, 30, 40, 40, 50, 50, 60, 60},
        {1, -5, 4, 1, 2, 4, 10, 6},
    };

    // TODO: add the other expected outputs here
    vector<int> expectedOutputs = {1, 1, 0, 1, 1, 0};

    for (int i = 0; i < inputs.size(); i++)
    {
        // Arrange
        vector<int> input = inputs[i];
        int expectedOutput = expectedOutputs[i];

        // Act
        int actualOutput = isTriangleSequence(input);

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