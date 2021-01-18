#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int **matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    int sumOfElementsAboveMainDiagonal = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sumOfElementsAboveMainDiagonal += matrix[i][j];
        }
    }

    cout << sumOfElementsAboveMainDiagonal << endl;

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;

}