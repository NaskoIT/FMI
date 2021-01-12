#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
const int SIZE = 3;
 
int getRandomNumber(int lowerBound, int upperBound, int seed);
 
void randomizeMatrix(int matrix[SIZE][SIZE]);
 
void printNumbers(int matrix[SIZE][SIZE]);
 
void printMatrix(int matrix[SIZE][SIZE], int guessedNumbers[SIZE][SIZE]);
 
int isWin(int guessedNumbers[SIZE][SIZE]);
 
int main() {
    int matrix[SIZE][SIZE];
    int counter = 1;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = counter++;
        }
    }
 
    randomizeMatrix(matrix);
    printNumbers(matrix);
 
    int guessedNumbers[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            guessedNumbers[i][j] = 0;
        }
    }
 
    printMatrix(matrix, guessedNumbers);
 
    int number;
    while (1) {
        scanf("%d", &number);
 
        int isRunning = 1;
        for (int i = 0; i < SIZE; ++i) {
            if (!isRunning) {
                break;
            }
 
            for (int j = 0; j < SIZE; ++j) {
                if (matrix[i][j] == number) {
                    guessedNumbers[i][j] = 1;
                    printMatrix(matrix, guessedNumbers);
                    if (isWin(guessedNumbers)) {
                        printf("BINGO. It is Christmas!");
                        return 0;
                    }
 
                    isRunning = 0;
                    break;
                }
            }
        }
    }
}
 
void printNumbers(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d ", matrix[i][j]);
        }
 
        printf("\n");
    }
}
 
int getRandomNumber(int lowerBound, int upperBound, int seed) {
    srand(seed);
    int r = rand();
    return lowerBound + r % upperBound;
}
 
int getIndex(int seed) {
    return getRandomNumber(0, SIZE * SIZE, seed) % SIZE;
}
 
void randomizeMatrix(int matrix[SIZE][SIZE]) {
    int seed = time(NULL) % 1000;
    for (int i = 0; i < SIZE * SIZE * SIZE; ++i) {
        int sourceRow = getIndex(seed++);
        int sourceCol = getIndex(seed++);
        int destinationRow = getIndex(seed++);
        int destinationCol = getIndex(seed++);
 
        int temp = matrix[sourceRow][sourceCol];
        matrix[sourceRow][sourceCol] = matrix[destinationRow][destinationCol];
        matrix[destinationRow][destinationCol] = temp;
    }
}
 
void printMatrix(int matrix[SIZE][SIZE], int guessedNumbers[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (guessedNumbers[i][j]) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("* ");
            }
        }
 
        printf("\n");
    }
}
 
int isWin(int guessedNumbers[SIZE][SIZE]) {
    int colGuessedNumbersCount[SIZE];
    int rowGuessedNumbersCount[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        colGuessedNumbersCount[i] = 0;
        rowGuessedNumbersCount[i] = 0;
    }
 
    int mainDiagonalGuessedNumbersCount = 0;
    int secondaryDiagonalGuessedNumbersCount = 0;
 
    for (int i = 0; i < SIZE; ++i) {
        int rowGuessedNumbers = 0;
        for (int j = 0; j < SIZE; ++j) {
            if (guessedNumbers[i][j]) {
                colGuessedNumbersCount[j]++;
                rowGuessedNumbers++;
 
                if (i == j) {
                    mainDiagonalGuessedNumbersCount++;
                }
                if (i + j == SIZE - 1) {
                    secondaryDiagonalGuessedNumbersCount++;
                }
            }
        }
 
        rowGuessedNumbersCount[i] = rowGuessedNumbers;
    }
 
    if (mainDiagonalGuessedNumbersCount == SIZE ||
        secondaryDiagonalGuessedNumbersCount == SIZE) {
        return 1;
    }
 
    for (int i = 0; i < SIZE; ++i) {
        if (colGuessedNumbersCount[i] == SIZE ||
            rowGuessedNumbersCount[i] == SIZE) {
            return 1;
        }
    }
 
    return 0;
}