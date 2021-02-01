#include <iostream>
#include <iomanip>
#include "BullsAndCows.h"

using namespace std;

const int NUMBER_MAX_LENGTH = 4;
const int DIGIT_COUNT = 9;
const int POSSIBLE_NUMBERS_COUNT = 3024;
const int SUGGESTION_RESULT_LENGTH = 2;

void play();

int* toArray(short number);

short toNumber(int *array);

void generateVariations(int set[], int variation[], bool used[], int **pool, int &poolIndex, int index = 0);

int **generatePool();

void getScore(int *currentSuggestion, int *secret, int *result);

bool canBeRemoved(int *currentSuggestion, int *possibleSuggestion, int *result);

bool isSolution(int *result);

void clearPool(int **pool, int *currentSuggestion, int *result, bool possibleNumbers[]);

int *getSuggestion(int **pool, bool possibleNumbers[]);

int main() {
    play();
}

void releaseMemory(int **pool) {
    for (int i = 0; i < POSSIBLE_NUMBERS_COUNT; ++i) {
        delete[] pool[i];
    }

    delete[] pool;
}

void play() {
    bool possibleNumbers[POSSIBLE_NUMBERS_COUNT];
    for (int i = 0; i < POSSIBLE_NUMBERS_COUNT; ++i) {
        possibleNumbers[i] = true;
    }

    int **pool = generatePool();

    cout << endl << " SECRET: " << SECRET << endl << "==============" << endl;
    cout << "+-----------+---------+--------+\n|   GUESS   |  BULLS  |  COWS  |\n+-----------+---------+--------+\n";

    while (true) {
        int *possibleSuggestion = getSuggestion(pool, possibleNumbers);

        if (possibleSuggestion == nullptr) {
            cout << endl << "Sorry, the program cannot find an answer!" << endl;
            releaseMemory(pool);
            return;
        }

        int number = toNumber(possibleSuggestion);

        int *result = tryGuess(number);
        if (isSolution(result)) {
            cout << endl << "I found the secret number!" << endl << "It is: " << number << endl;
            delete[] result;
            releaseMemory(pool);
            return;
        }

        cout << "|    " << number << "   |  " << setw(3) << result[0] << "    |  " << setw(3) << result[1]
             << "   |\n+-----------+---------+--------+\n";

        clearPool(pool, possibleSuggestion, result, possibleNumbers);
        delete[] result;
    }
}

int *toArray(int number) {
    int *array = new int[NUMBER_MAX_LENGTH];

    for (int i = 3; i >= 0; i--) {
        array[i] = number % 10;
        number /= 10;
    }

    return array;
}

short toNumber(int *array) {
    return array[0] * 1000 + array[1] * 100 + array[2] * 10 + array[3];
}

void generateVariations(int set[], int variation[], bool used[], int **pool, int &poolIndex, int index) {
    if (index == NUMBER_MAX_LENGTH) {
        for (int i = 0; i < NUMBER_MAX_LENGTH; ++i) {
            pool[poolIndex][i] = variation[i];
        }

        poolIndex++;
    } else {
        for (int i = 0; i < DIGIT_COUNT; i++) {
            if (!used[i]) {
                used[i] = true;
                variation[index] = set[i];
                generateVariations(set, variation, used, pool, poolIndex, index + 1);
                used[i] = false;
            }
        }
    }
}

int **generatePool() {
    bool used[DIGIT_COUNT];
    int set[DIGIT_COUNT];
    int variation[NUMBER_MAX_LENGTH];

    for (int i = 0; i < DIGIT_COUNT; ++i) {
        used[i] = false;
        set[i] = i + 1;
    }

    int **pool = new int *[POSSIBLE_NUMBERS_COUNT];
    for (int i = 0; i < POSSIBLE_NUMBERS_COUNT; ++i) {
        pool[i] = new int[NUMBER_MAX_LENGTH];
    }

    int poolIndex = 0;
    generateVariations(set, variation, used, pool, poolIndex);
    return pool;
}

void getScore(int *currentSuggestion, int *secret, int *result) {
    result[0] = 0;
    result[1] = 0;

    for (unsigned int i = 0; i < NUMBER_MAX_LENGTH; i++) {
        if (currentSuggestion[i] == secret[i]) {
            result[0]++;
        } else {
            for (unsigned int j = 0; j < NUMBER_MAX_LENGTH; j++)
                if (currentSuggestion[i] == secret[j]) {
                    result[1]++;
                }
        }
    }
}

bool canBeRemoved(int *currentSuggestion, int *possibleSuggestion, int *result) {
    int possibleSuggestionResult[SUGGESTION_RESULT_LENGTH];
    getScore(currentSuggestion, possibleSuggestion, possibleSuggestionResult);
    return possibleSuggestionResult[0] != result[0] || possibleSuggestionResult[1] != result[1];
}

bool isSolution(int *result) {
    return result[0] == NUMBER_MAX_LENGTH;
}

void clearPool(int **pool, int *currentSuggestion, int *result, bool possibleNumbers[]) {
    for (int i = 0; i < POSSIBLE_NUMBERS_COUNT; ++i) {
        if (possibleNumbers[i] && canBeRemoved(currentSuggestion, pool[i], result)) {
            possibleNumbers[i] = false;
        }
    }
}

int *getSuggestion(int **pool, bool possibleNumbers[]) {
    for (int i = 0; i < POSSIBLE_NUMBERS_COUNT; ++i) {
        if (possibleNumbers[i]) {
            possibleNumbers[i] = false;
            return pool[i];
        }
    }

    return nullptr;
}