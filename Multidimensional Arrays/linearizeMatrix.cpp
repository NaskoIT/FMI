#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> readMatrix(int rows, int cols);
;

int main()
{
    int rows;
    cin >> rows;

    vector<vector<int>> matrix = readMatrix(rows, rows);
    vector<int> array;

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[row].size(); col++)
        {
            array.push_back(matrix[row][col]);
        }
    }

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
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