/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 2
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

const int STRING_MAX_LENGTH = 151;
const char TERMINATING_CHARACTER = '\0';
const int SUCCESS_EXIT_CODE = 0;
const int ENGLISH_ALPHABET_COUNT = 26;
const char ENGLISH_ALPHABET_FIRST_LOWERCASE_LETTER = 'a';
const char ENGLISH_ALPHABET_LAST_LOWERCASE_LETTER = 'z';

bool isStringCompatible(
        int firstStrLettersOccurrences[],
        int secondStrLettersOccurrences[],
        char resultStr[],
        int firstStrLength,
        int secondStrLength);

bool isStringCompatible(char firstStr[], char secondStr[], char resultStr[]);

bool isValidString(char str[]);

bool isLower(char symbol);

int getLength(char str[]);

void countLetters(char str[], int occurrences[], int startIndex, int endIndex);

bool areArraysEqual(int firstArray[], int secondArray[], int size);

int getZeroBasedIndex(char symbol);

int main() {
    char firstStr[STRING_MAX_LENGTH];
    cin >> firstStr;

    char secondStr[STRING_MAX_LENGTH];
    cin >> secondStr;

    char resultStr[STRING_MAX_LENGTH];
    cin >> resultStr;

    if (!isValidString(firstStr) || !isValidString(secondStr) || !isValidString(resultStr)) {
        cout << "-1";
        return SUCCESS_EXIT_CODE;
    }

    cout << isStringCompatible(firstStr, secondStr, resultStr);
    return SUCCESS_EXIT_CODE;
}

bool isStringCompatible(char firstStr[], char secondStr[], char resultStr[]) {
    int firstStrLength = getLength(firstStr);
    int secondStrLength = getLength(secondStr);
    int resultStrLength = getLength(resultStr);

    if (firstStrLength + secondStrLength != resultStrLength) {
        return false;
    }

    int firstStrLettersOccurrences[ENGLISH_ALPHABET_COUNT];
    countLetters(firstStr, firstStrLettersOccurrences, 0, firstStrLength - 1);

    int secondStrLettersOccurrences[ENGLISH_ALPHABET_COUNT];
    countLetters(secondStr, secondStrLettersOccurrences, 0, secondStrLength - 1);

    return isStringCompatible(
            firstStrLettersOccurrences,
            secondStrLettersOccurrences,
            resultStr,
            firstStrLength,
            secondStrLength) ||
           isStringCompatible(
                   secondStrLettersOccurrences,
                   firstStrLettersOccurrences,
                   resultStr,
                   secondStrLength,
                   firstStrLength);
}

bool isStringCompatible(
        int firstStrLettersOccurrences[],
        int secondStrLettersOccurrences[],
        char resultStr[],
        int firstStrLength,
        int secondStrLength) {
    int resultFirstPartLetterOccurrences[ENGLISH_ALPHABET_COUNT];
    countLetters(resultStr, resultFirstPartLetterOccurrences, 0, firstStrLength - 1);

    int resultSecondPartLetterOccurrences[ENGLISH_ALPHABET_COUNT];
    countLetters(resultStr, resultSecondPartLetterOccurrences, firstStrLength, firstStrLength + secondStrLength - 1);

    return areArraysEqual(firstStrLettersOccurrences, resultFirstPartLetterOccurrences, ENGLISH_ALPHABET_COUNT) &&
           areArraysEqual(secondStrLettersOccurrences, resultSecondPartLetterOccurrences, ENGLISH_ALPHABET_COUNT);
}

bool isValidString(char str[]) {
    int index = 0;
    while (str[index] != TERMINATING_CHARACTER) {
        if (!isLower(str[index])) {
            return false;
        }

        index++;
    }

    return true;
}

bool isLower(char symbol) {
    return symbol >= ENGLISH_ALPHABET_FIRST_LOWERCASE_LETTER && symbol <= ENGLISH_ALPHABET_LAST_LOWERCASE_LETTER;
}

int getLength(char str[]) {
    int counter = 0;

    while (str[counter] != TERMINATING_CHARACTER) {
        counter++;
    }

    return counter;
}

void countLetters(char str[], int occurrences[], int startIndex, int endIndex) {
    for (int i = 0; i < ENGLISH_ALPHABET_COUNT; i++) {
        occurrences[i] = 0;
    }

    for (int i = startIndex; i <= endIndex; i++) {
        int index = getZeroBasedIndex(str[i]);
        occurrences[index]++;
    }
}

bool areArraysEqual(int firstArray[], int secondArray[], int size) {
    for (int i = 0; i < size; i++) {
        if (firstArray[i] != secondArray[i]) {
            return false;
        }
    }

    return true;
}

int getZeroBasedIndex(char symbol) {
    return symbol - ENGLISH_ALPHABET_FIRST_LOWERCASE_LETTER;
}