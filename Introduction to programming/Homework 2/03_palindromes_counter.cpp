/**
*  
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 3
* @compiler GCC
*
*/

#include <iostream>
#include <vector>
using namespace std;

const int SUB_SEQUENCE_MIN_LENGTH = 3;
const int SEQUENCE_MIN_LENGTH = 3;
const int SEQUENCE_MAX_LENGTH = 1000;

vector<int> readSequence(int length);
int countSubsequences(vector<int> collection);
bool isPallindrome(vector<int> sequence, int startIndex, int length);
bool isDigit(int number);
void runUnitTests();

int main()
{
    // input validation
    // {9, 6, 9, 9, 10, 99, 88, 77, 6, 6, 6, 9, 6, 9} - 5
    
    int length;
    do
    {
        cin >> length;

    } while (length < SEQUENCE_MIN_LENGTH || length > SEQUENCE_MAX_LENGTH);
    
    vector<int> sequence = readSequence(length);

    cout << countSubsequences(sequence);
}

vector<int> readSequence(int length)
{
    vector<int> array(length);
    for (int i = 0; i < length; i++)
    {
        int number;
        cin >> number;
        if (isDigit(number))
        {
            array[i] = number;
        }
        else
        {
            i--;
        }
    }

    return array;
}

int countSubsequences(vector<int> sequence)
{
    int count = 0;
    for (int i = 0; i < sequence.size() - SUB_SEQUENCE_MIN_LENGTH + 1; i++)
    {
        for (int j = i + SUB_SEQUENCE_MIN_LENGTH - 1; j < sequence.size(); j++)
        {
            if (isPallindrome(sequence, i, j))
            {
                count++;
            }
        }
    }

    return count > 0 ? count : -1;
}

bool isPallindrome(vector<int> sequence, int startIndex, int endIndex)
{
    int middleIndex = (startIndex + endIndex) / 2;
    for (int i = startIndex; i <= middleIndex; i++)
    {
        if (sequence[i] != sequence[endIndex + startIndex - i])
        {
            return false;
        }
    }

    return true;
}

bool isDigit(int number)
{
    return number >= 0 && number <= 9;
}

void runUnitTests()
{
    vector<vector<int>> inputs = {
        {1, 2, 2, 1},
        {5, 0, 6, 0, 5},
        {1, 3, 8, 3, 1, 4, 5, 4, 1, 4},
        {4, 1, 2, 2, 1},
        {5, 5, 0, 6, 0, 5},
        {10, 1, 3, 8, 3, 1, 4, 5, 4, 1, 4},
        {7, 1, 2, 3, 3, 2, 1, 2},
        {10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {3, 9, 7, 1, 5},
        {13, 5, 9, 6, 3, 4, 2, 8, 8, 7, 5, 8, 1, 2},
        {0, 1, 5, 5, 5, 5, 1},
        {4, 1, 1, 1, 1}
    };

    vector<int> expectedOutputs = {1, 2, 5, 1, 2, 5, 3, 36, -1, -1, 4, 3};

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