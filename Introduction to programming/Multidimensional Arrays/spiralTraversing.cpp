#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> readMatrix(int rows, int cols);
void spiralTraverse(vector<vector<int>> matrix);
void printNumber(int element);

int main()
{
    // 1 2 3 4
    // 5 6 7 8
    // 9 10 11 12
    // 13 14 15 16
    // 1 2 3 4 8 12 16 15 14 13 9 5 7 11 10

    // 1 2 3
    // 8 9 4
    // 7 6 5
    // 1 2 3 4 5 6 7 8 9

    // 1 2
    // 3 4
    // 5 6
    // 1 2 4 6 5 3

    int rows, cols;
    cin >> rows;
    cin >> cols;

    vector<vector<int>> matrix = readMatrix(rows, cols);

    spiralTraverse(matrix);
}

vector<vector<int>> readMatrix(int rows, int cols)
{
    vector<vector<int>> matrix(rows);

    for (int row = 0; row < rows; row++)
    {
        matrix[row] = vector<int>(cols);
        for (int col = 0; col < cols; col++)
        {
            cin >> matrix[row][col];
        }
    }

    return matrix;
}

void spiralTraverse(vector<vector<int>> matrix)
{
    int startRowIndex = 0;
    int endRowIndex = matrix.size() - 1;
    int startColIndex = 0;
    int endColIndex = matrix[startRowIndex].size() - 1;

    while (startRowIndex <= endRowIndex && startColIndex <= endColIndex)
    {
        // Print the current top row
        for (int col = startColIndex; col <= endColIndex; col++)
        {
            printNumber(matrix[startRowIndex][col]);
        }

        startRowIndex++;

        // Print the current right column
        for (int row = startRowIndex; row <= endRowIndex; row++)
        {
            printNumber(matrix[row][endColIndex]);
        }

        endColIndex--;

        // Print the current bottom row
        if (startRowIndex <= endRowIndex)
        {
            for (int col = endColIndex; col >= startColIndex; col--)
            {
                printNumber(matrix[endRowIndex][col]);
            }

            endRowIndex--;
        }

        // Prtint the current left row
        if (startColIndex <= endColIndex)
        {
            for (int row = endRowIndex; row >= startRowIndex; row--)
            {
                printNumber(matrix[row][startColIndex]);
            }

            startColIndex++;
        }
    }
}

void printNumber(int element)
{
    cout << element << " ";
}