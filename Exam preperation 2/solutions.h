#include <iostream>
#include <iomanip>

using namespace std;

const int CONSOLE_ROWS = 25;
const int CONSOLE_COLS = 80;

// task 1
int *buildSortedArray(const int *firstArray, const int *secondArray, int firstLength, int secondLength) {
    int firstIndex = 0;
    int secondIndex = 0;
    int resultIndex = 0;
    int *result = new int[firstLength + secondLength];

    while (firstIndex < firstLength && secondIndex < secondLength) {
        if (firstArray[firstIndex] < secondArray[secondIndex]) {
            result[resultIndex++] = firstArray[firstIndex++];
        } else {
            result[resultIndex++] = secondArray[secondIndex++];
        }
    }

    while (firstIndex < firstLength) {
        result[resultIndex++] = firstArray[firstIndex++];
    }

    while (secondIndex < secondLength) {
        result[resultIndex++] = secondArray[secondIndex++];
    }

    return result;
}

// task 3
void printRectangle(int rows, int cols, char symbol) {
    int emptyRows = (CONSOLE_ROWS - rows) / 2;
    int emptyCols = (CONSOLE_COLS - cols) / 2;

    for (int i = 0; i < emptyRows; ++i) {
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        cout << setw(emptyCols);
        for (int j = 0; j < cols; ++j) {
            cout << symbol;
        }

        cout << endl;
    }
}

// task 4
int getSumOfElementsAboveMainDiagonal(int n, int **matrix) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

// task 5
int **transpose(int **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    return matrix;
}
