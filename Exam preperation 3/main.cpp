#include <iostream>
#include "Solutions.h"

using namespace std;

void testAnalyzeArray() {
    int arr1[] = {1, 3, 0, 0, 4};
    int arr2[] = {1, 6, 1, 0, 5, 199};

    cout << "test 1: " << analyzeArray(arr1, 5) << endl;
    cout << "test 2: " << analyzeArray(arr2, 6) << endl;
}

void testDoExist(char symbols[], char word[]) {
    cout << word << " contains in: " << symbols << " -> " << doExist(symbols, word) << endl;
}

void testDoExist() {
    char symbols1[] = "abcasd";
    char word1[] = "dsa";
    testDoExist(symbols1, word1);

    char symbols2[] = "abcdef";
    char word2[] = "cba";
    testDoExist(symbols2, word2);

    char symbols3[] = "abba";
    char word3[] = "abba";
    testDoExist(symbols3, word3);

    char symbols4[] = "abcdef";
    char word4[] = "fedcba";
    testDoExist(symbols4, word4);

    char symbols5[] = "abcdef";
    char word5[] = "fdc";
    testDoExist(symbols5, word5);

    char symbols6[] = "abcde";
    char word6[] = "abcdae";
    testDoExist(symbols6, word6);

    char symbols7[] = "abcde";
    char word7[] = "bab";
    testDoExist(symbols7, word7);
}

//1 2 3 4
//5 6 7 8
//9 10 11 12
//13 14 15 16
// should be 68
void testCalculateMatrix() {
    const int m = 4;
    int **matrix = new int *[m];
    int counter = 1;
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = counter++;
        }
    }

    cout << calculateMatrix(matrix, m) << endl;

    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main() {
    testCalculateMatrix();
}
