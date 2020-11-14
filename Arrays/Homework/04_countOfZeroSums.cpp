#include <iostream>
#include <vector>
using namespace std;

int countZeroSums(vector<int> collection);
void runUnitTests();

int main()
{
    // When you implement the method countZeroSums run the program and your logic will be tested automatically for a second
    // You will see how many of the test failed and how many of them passed.
    // If the test failed you will see the difference between expected output and your output.
    runUnitTests();
}

int countZeroSums(vector<int> sequence)
{
    // TODO: implement this function
    return -1;
}

void runUnitTests()
{
    // TODO: add other inputs and try to catch the edge cases
    vector<vector<int>> inputs = {
        {1, 2, 3},
        {1, 2, -3},
        {-1, 0, 1, 2, 3, 4, -2},
        {-3, -2, -1, 0, 1, 2, 3},
    };

    // TODO: add the other expected outputs here
    vector<int> expectedOutputs = {0, 1, 3, 5};

    for (int i = 0; i < inputs.size(); i++)
    {
        // Arrange
        vector<int> input = inputs[i];
        int expectedOutput = expectedOutputs[i];

        // Act
        int actualOutput = countZeroSums(input);

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