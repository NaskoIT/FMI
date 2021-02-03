/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 4
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

const char TERMINATING_CHARACTER = '\0';
const int STRING_MAX_LENGTH = 100;
const int ENGLISH_ALPHABET_COUNT = 26;
const char ENGLISH_ALPHABET_FIRST_LOWERCASE_LETTER = 'a';
const int MAX_RECURSIVE_SOLUTION = 16;
const int MAX_COMBINATIONS = 1000;

void generateCombinations(
        char set[],
        char combination[],
        int setLength,
        int combinationLength,
        char combinations[MAX_COMBINATIONS][STRING_MAX_LENGTH],
        int index = 0,
        int start = 0);

bool hasRepetitions(char str[]);

int getLength(char str[]);

long long countCombinations(int n, int k);

void addIfNotExists(char array[MAX_COMBINATIONS][STRING_MAX_LENGTH], char combination[], int length);

bool isLower(char symbol);

bool isUpper(char symbol);

bool isValidInput(char line[]);

void resetCombinations(char combinations[MAX_COMBINATIONS][STRING_MAX_LENGTH]);

int main() {
    char set[STRING_MAX_LENGTH];
    cin >> set;
    if (!isValidInput(set)) {
        cout << "-1";
        return 0;
    }

    int length = getLength(set);

    if (!hasRepetitions(set) || length > MAX_RECURSIVE_SOLUTION) {
        long long combinationsCount = 1;
        for (int i = 1; i < length; i++) {
            combinationsCount += countCombinations(length, i);
        }

        cout << combinationsCount << endl;
        return 0;
    }

    char combination[STRING_MAX_LENGTH];
    long long combinationsCount = 1;

    for (int i = 1; i < length; i++) {
        char combinations[MAX_COMBINATIONS][STRING_MAX_LENGTH];
        resetCombinations(combinations);

        combination[length - i] = TERMINATING_CHARACTER;
        generateCombinations(set, combination, length, length - i, combinations);

        int count = 0;
        while (combinations[count][0] != TERMINATING_CHARACTER) {
            count++;
        }

        combinationsCount += count;
    }

    cout << combinationsCount;
    return 0;
}

void generateCombinations(
        char set[],
        char combination[],
        int setLength,
        int combinationLength,
        char combinations[MAX_COMBINATIONS][STRING_MAX_LENGTH],
        int index,
        int start) {
    if (index == combinationLength) {
        addIfNotExists(combinations, combination, combinationLength);
    } else {
        for (int i = start; i < setLength; i++) {
            combination[index] = set[i];
            generateCombinations(
                    set,
                    combination,
                    setLength,
                    combinationLength,
                    combinations,
                    index + 1,
                    i + 1);
        }
    }
}


long long countCombinations(int n, int k) {
    long long denominator = 1;
    long long numerator = 1;
    int index = 1;
    for (int i = n; i > n - k; i--) {
        numerator *= i;
        denominator *= index++;
    }

    return numerator / denominator;
}

bool hasRepetitions(char str[]) {
    int occurrences[ENGLISH_ALPHABET_COUNT];
    for (int i = 0; i < ENGLISH_ALPHABET_COUNT; i++) {
        occurrences[i] = 0;
    }

    for (int i = 0; i < STRING_MAX_LENGTH; i++) {
        if (str[i] == TERMINATING_CHARACTER) {
            return false;
        }

        int index = str[i] - ENGLISH_ALPHABET_FIRST_LOWERCASE_LETTER;
        if (occurrences[index] > 0) {
            return true;
        }

        occurrences[index]++;
    }

    return false;
}

int getLength(char str[]) {
    int counter = 0;

    while (str[counter] != TERMINATING_CHARACTER) {
        counter++;
    }

    return counter;
}

void addIfNotExists(char array[MAX_COMBINATIONS][STRING_MAX_LENGTH], char combination[], int length) {
    for (int i = 0; i < MAX_COMBINATIONS; i++) {
        if (array[i][0] == TERMINATING_CHARACTER) {
            for (int j = 0; j < length; ++j) {
                array[i][j] = combination[j];
            }

            return;
        } else {
            bool areEquals = true;
            for (int j = 0; j < length; ++j) {
                if (array[i][j] != combination[j]) {
                    areEquals = false;
                    break;
                }
            }

            if (areEquals) {
                return;
            }
        }
    }
}

bool isLower(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

bool isUpper(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

bool isValidInput(char line[]) {
    for (int i = 0; i < STRING_MAX_LENGTH; i++) {
        if (line[i] == TERMINATING_CHARACTER) {
            return true;
        }

        if (!(isUpper(line[i]) || isLower(line[i]))) {
            return false;
        }
    }

    return true;
}

void resetCombinations(char combinations[MAX_COMBINATIONS][STRING_MAX_LENGTH]) {
    for (int j = 0; j < MAX_COMBINATIONS; ++j) {
        for (int k = 0; k < STRING_MAX_LENGTH; ++k) {
            combinations[j][k] = TERMINATING_CHARACTER;
        }
    }
}