/**
*  
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 4
* @compiler GCC
*
*/

#include <iostream>
#include <vector>
using namespace std;

const int ElementsInSumCount = 3;

vector<int> readUniqueSequence(int length);
int countZeroSums(vector<int> collection);
bool isPallindrome(vector<int> sequence, int startIndex, int length);
bool contains(vector<int> collection, int value);
bool hasNegativeNumber(vector<int> collection);
void runUnitTests();

const int INPUT_MIN_VALUE = -2147483648;
const int INPUT_MAX_VALUE = 2147483647;
const int SEQUENCE_MIN_LENGTH = 3;
const int SEQUENCE_MAX_LENGTH = 100;

int main()
{
    int length;
    do
    {
        cin >> length;

    } while (length < SEQUENCE_MIN_LENGTH || length > SEQUENCE_MAX_LENGTH);
    
    vector<int> sequence = readUniqueSequence(length);

    cout << countZeroSums(sequence);
}

vector<int> readUniqueSequence(int length)
{
    vector<int> array;
    for (int i = 0; i < length; i++)
    {
        long long number;
        cin >> number;
        if (number > INPUT_MAX_VALUE || number < INPUT_MIN_VALUE || contains(array, number))
        {
            i--;
        }
        else
        {
            array.push_back(number);
        }
    }

    return array;
}

int countZeroSums(vector<int> sequence)
{
    if (!hasNegativeNumber(sequence))
    {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < sequence.size() - 2; i++)
    {
        for (int j = i + 1; j < sequence.size() - 1; j++)
        {
            for (int k = j + 1; k < sequence.size(); k++)
            {
                if (sequence[i] + sequence[j] + sequence[k] == 0)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

bool contains(vector<int> collection, int value)
{
    for (int i = 0; i < collection.size(); i++)
    {
        if (collection[i] == value)
        {
            return true;
        }
    }

    return false;
}

bool hasNegativeNumber(vector<int> collection)
{
    for (int i = 0; i < collection.size(); i++)
    {
        if (collection[i] < 0)
        {
            return true;
        }
    }

    return false;
}

void runUnitTests()
{
    vector<vector<int>> inputs = {
        {1, 2, 3},
        {1, 2, -3},
        {-1, 0, 1, 2, 3, 4, -2},
        {-3, -2, -1, 0, 1, 2, 3},
    };

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