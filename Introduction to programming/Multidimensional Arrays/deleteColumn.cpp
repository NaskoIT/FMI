#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> readMatrix(int rows, int cols);
void deleteColumn(vector<vector<int>> &matrix, int col);
void printMatrix(vector<vector<int>> matrix);

int main()
{
    int rows, cols, colIndex;
    cin >> rows;
    cin >> cols;
    cin >> colIndex;

    vector<vector<int>> matrix = readMatrix(rows, cols);

    deleteColumn(matrix, colIndex);

    printMatrix(matrix);
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

void deleteColumn(vector<vector<int>> &matrix, int colIndex)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = colIndex; col < matrix[row].size() - 1; col++)
        {
            int currentElement = matrix[row][col];
            matrix[row][col] = matrix[row][col + 1];
            matrix[row][col + 1] = currentElement;
        }

        matrix[row].pop_back();
    }
}

void printMatrix(vector<vector<int>> matrix)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[row].size(); col++)
        {
            cout << matrix[row][col] << " ";
        }

        cout << endl;
    }
}