#include <iostream>
#include <vector>
using namespace std;

int sumOddIndicesElements(vector<int> number);

int main()
{
    // 5 -> 10 20 30 40 50 -> 60
    // 6 -> 10 15 20 25 20 2 -> 2
    // 1 -> 1 -> 0
    // 2 -> 1 1 -> 0
    // 2 -> 1 2 -> 2
    // 4 -> -2 -2 3 10 -> 8

    vector<vector<int>> inputs = {
        vector<int>{10, 20, 30, 40, 50},
        vector<int>{10, 15, 20, 25, 20, 2},
        vector<int>{1},
        vector<int>{1, 1},
        vector<int>{1, 2},
        vector<int>{-2, -2, 3, 10}};

    vector<int> expectedOutputs = {60, 2, 0, 0, 2, 8};

    for (int i = 0; i < inputs.size(); i++)
    {
        // Arrange
        vector<int> input = inputs[i];
        int expectedOutput = expectedOutputs[i];

        // Act
        int actualOutput = sumOddIndicesElements(input);

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

int sumOddIndicesElements(vector<int> numbers)
{
    int sum = 0;
    for (int i = 1; i < numbers.size(); i += 2)
    {
        int currentNumber = numbers[i];
        if (currentNumber % 2 == 0)
        {
            sum += currentNumber;
        }
    }

    return sum;
}