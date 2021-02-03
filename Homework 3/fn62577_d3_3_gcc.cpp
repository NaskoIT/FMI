/**
*
* Solution to homework assignment 3
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

const double EPSILON = 0.000001;
const int MATRIX_MIN_SIZE = 2;
const int MATRIX_MAX_SIZE = 999;
const int SUCCESS_STATUS_CODE = 0;
const int ERROR_STATUS_CODE = -1;
const double ELEMENT_MAX_VALUE = 100;
const double ELEMENT_MIN_VALUE = 0;

int readMatrix(int n, vector<vector<double>> &matrix);

bool isMagicalMatrix(vector<vector<double>> matrix);

double getMainDiagonalSum(vector<vector<double>> matrix);

double getSecondaryDiagonalSum(vector<vector<double>> matrix);

double abs(double number);

bool areEqual(double firstNumber, double secondNumber);

int main() {
    int n;
    cin >> n;

    if (n < MATRIX_MIN_SIZE || n > MATRIX_MAX_SIZE) {
        cout << ERROR_STATUS_CODE;
        return SUCCESS_STATUS_CODE;
    }

    vector<vector<double>> matrix(n);
    int executionResult = readMatrix(n, matrix);
    if(executionResult == ERROR_STATUS_CODE) {
        cout << ERROR_STATUS_CODE;
        return SUCCESS_STATUS_CODE;
    }

    cout << (isMagicalMatrix(matrix) ? "true" : "false");

    return SUCCESS_STATUS_CODE;
}

int readMatrix(int n, vector<vector<double>> &matrix) {
    for (int i = 0; i < n; i++) {
        matrix[i] = vector<double>(n);
        for (int j = 0; j < n; j++) {
            double number;
            cin >> number;
            if (number < ELEMENT_MIN_VALUE || number > ELEMENT_MAX_VALUE) {
                return ERROR_STATUS_CODE;
            }

            matrix[i][j] = number;
        }
    }

    return SUCCESS_STATUS_CODE;
}

bool isMagicalMatrix(vector<vector<double>> matrix) {
    int size = matrix.size();
    double mainDiagonalSum = getMainDiagonalSum(matrix);
    double secondaryDiagonalSum = getSecondaryDiagonalSum(matrix);

    if (!areEqual(mainDiagonalSum, secondaryDiagonalSum)) {
        return false;
    }

    vector<double> colsSums(size, 0);

    for (int row = 0; row < size; row++) {
        double currentRowSum = 0;
        for (int col = 0; col < size; col++) {
            double element = matrix[row][col];
            currentRowSum += element;
            colsSums[col] += element;
        }

        if (!areEqual(mainDiagonalSum, currentRowSum)) {
            return false;
        }
    }

    for (int i = 0; i < size; i++) {
        if (!areEqual(mainDiagonalSum, colsSums[i])) {
            return false;
        }
    }

    return true;
}

double getMainDiagonalSum(vector<vector<double>> matrix) {
    double sum = 0;
    for (int i = 0; i < matrix.size(); i++) {
        sum += matrix[i][i];
    }

    return sum;
}

double getSecondaryDiagonalSum(vector<vector<double>> matrix) {
    double sum = 0;
    unsigned int j = matrix.size() - 1;
    for (int i = 0; i < matrix.size(); i++) {
        sum += matrix[i][j - i];
    }

    return sum;
}

double abs(double number) {
    return number >= 0 ? number : -number;
}

bool areEqual(double firstNumber, double secondNumber) {
    return abs(firstNumber - secondNumber) <= EPSILON;
}