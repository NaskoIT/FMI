/**
*  
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 1
* @compiler GCC
*
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> readSequence(int length);
int getAbsoluteValue(int value);
bool isAbsoluteValuesEqual(int a, int b);
bool isTriangleSequence(vector<int> collection);
void runUnitTests();

const int SEQUENCE_MIN_LENGTH = 3;
const int SEQUENCE_MAX_LENGTH = 100;

int main()
{
    int length;
    do
    {
        cin >> length;
    } while (length < SEQUENCE_MIN_LENGTH || length > SEQUENCE_MAX_LENGTH);

    vector<int> sequence = readSequence(length);

    cout << isTriangleSequence(sequence);
}

vector<int> readSequence(int length)
{
    vector<int> array(length);
    for (int i = 0; i < length; i++)
    {
        int number;
        cin >> number;
        if (number < 0)
        {
            i--;
        }
        else
        {
            array[i] = number;
        }
    }

    return array;
}

int getAbsoluteValue(int value)
{
    return value < 0 ? -value : value;
}

bool isAbsoluteValuesEqual(int a, int b)
{
    return getAbsoluteValue(a) == getAbsoluteValue(b);
}

bool isTriangleSequence(vector<int> collection)
{
    int size = collection.size();
    for (int i = 1; i < size / 2; i++)
    {
        int leftDifference = collection[i - 1] - collection[i];
        int rightDifference = collection[size - i] - collection[size - i - 1];
        if (!isAbsoluteValuesEqual(leftDifference, rightDifference))
        {
            return false;
        }
    }

    return true;
}

void runUnitTests()
{
    vector<vector<int>> inputs = {
        {9, 8, 3, 4, 2, 1, 6, 5},
        {5, 5, 0, 5, 5},
        {1, 2, 3, 6, 8, 7},
        {2, 1, 2, 3, 3, 2, 1},
        {5, 5, 5, 0, 5, 5},
        {4, 2, -1, 0, 1, 3},
        {-1, 5, 3, 5, 3, -2, 1, 3}};

    vector<int> expectedOutputs = {1, 1, 0, 1, 0, 0, 0};

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