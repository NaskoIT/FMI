#include <iostream>
#include <vector>
using namespace std;

double calulcateMaxProfit(vector<double> collection);
void runUnitTests();

int main()
{
    // When you implement the method calulcateMaxProfit run the program and your logic will be tested automatically for a second
    // You will see how many of the test failed and how many of them passed.
    // If the test failed you will see the difference between expected output and your output.
    runUnitTests();
    return 0;
}

double calulcateMaxProfit(vector<double> collection)
{
    // TODO: implement this function
    return -1;
}

void runUnitTests()
{
    // TODO: add the other inputs and try to catch the edge cases
    vector<vector<double>> inputs = {
        {1, 2, 3, 4, 3, 2, 1, 5},
        {15, 14.5, 10, 7.45, 5},
    };

    // TODO: add the other expected outputs here
    vector<double> expectedOutputs = {7, 0};

    for (int i = 0; i < inputs.size(); i++)
    {
        // Arrange
        vector<double> input = inputs[i];
        int expectedOutput = expectedOutputs[i];

        // Act
        int actualOutput = calulcateMaxProfit(input);

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
