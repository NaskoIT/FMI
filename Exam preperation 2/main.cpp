#include <iostream>
#include "solutions.h"

using namespace std;

void testBuildSortedArray() {
    int firstArray[] = {1, 7, 8};
    int secondArray[] = {-1, 0, 2};
    int *result = buildSortedArray(firstArray, secondArray, 3, 3);

    for (int i = 0; i < 6; ++i) {
        cout << result[i] << " ";
    }

    cout << endl;

    delete[] result;
}

void testGetSumOfElementsAboveMainDiagonal() {
    int n = 4;
    int **matrix = new int *[n];
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = ++counter;
        }
    }

    cout << getSumOfElementsAboveMainDiagonal(n, matrix);

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void testPrintRectangle() {
    printRectangle(10, 7, 'A');
}

void testTranspose() {
    int n = 4;
    int **matrix = new int *[n];
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = ++counter;
        }
    }

    transpose(matrix, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main() {
    testBuildSortedArray();
}