#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> readMatrix(int rows, int cols);
vector<vector<int>> sumMatricies(vector<vector<int>> firstMatrix, vector<vector<int>> secondMatrix);
void printMatrix(vector<vector<int>> matrix);

int main()
{
    int rows, cols;
    cin >> rows;
    cin >> cols;

    vector<vector<int>> firstMatrix = readMatrix(rows, cols);
    vector<vector<int>> secondMatrix = readMatrix(rows, cols);

    vector<vector<int>> resultMatrix = sumMatricies(firstMatrix, secondMatrix);

    printMatrix(resultMatrix);
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

vector<vector<int>> sumMatricies(vector<vector<int>> firstMatrix, vector<vector<int>> secondMatrix)
{
    vector<vector<int>> resultMatrix(firstMatrix.size());

    for (int row = 0; row < firstMatrix.size(); row++)
    {
        resultMatrix[row] = vector<int>(firstMatrix[row].size());
        for (int col = 0; col < firstMatrix[row].size(); col++)
        {
            resultMatrix[row][col] = firstMatrix[row][col] + secondMatrix[row][col];
        }
    }

    return resultMatrix;
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
