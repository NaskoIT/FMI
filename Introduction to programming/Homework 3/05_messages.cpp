/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 5
* @compiler GCC
*
*/

#include <iostream>
#include <fstream>

using namespace std;

const int STRING_SIZE = 151;
const int FILE_CANNOT_BE_OPEN_ERROR_CODE = -2;
const int ERROR_CODE = -1;
const int SUCCESS_CODE = 0;
const int FILE_MAX_LINES = 1000;
const char TERMINATING_CHARACTER = '\0';
const char FILE_NAME[] = "message.txt";
const char BIGGEST_ALPHABET_LETTER = 'z';
const char DEFAULT_DECRYPTED_CHARACTER = '.';

int decryptMessage(const char filename[], char decryptedMessage[]);

char getDecryptedLetter(char message[], int length);

char getNextLetter(char letter);

void selectionSort(char array[]);

void swap(char array[], int firstIndex, int secondIndex);

bool isLower(char symbol);

bool isUpper(char symbol);

bool isValidLine(char line[]);

int main() {
    char decryptedMessage[FILE_MAX_LINES + 1];
    int executionCode = decryptMessage(FILE_NAME, decryptedMessage);

    if (executionCode != SUCCESS_CODE) {
        cout << executionCode;
    } else {
        cout << decryptedMessage;
    }
}

int decryptMessage(const char filename[], char decryptedMessage[]) {
    ifstream file(filename);

    if (!file.is_open()) {
        return FILE_CANNOT_BE_OPEN_ERROR_CODE;
    }

    char line[STRING_SIZE];
    int index = 0;

    while (!file.eof()) {
        if (index == FILE_MAX_LINES) {
            return ERROR_CODE;
        }

        file.getline(line, STRING_SIZE);
        if (!isValidLine(line)) {
            return ERROR_CODE;
        }

        decryptedMessage[index++] = getDecryptedLetter(line, STRING_SIZE);
    }

    decryptedMessage[index] = TERMINATING_CHARACTER;

    return SUCCESS_CODE;
}

char getDecryptedLetter(char message[], int length) {
    selectionSort(message);
    char decryptedCharacter = DEFAULT_DECRYPTED_CHARACTER;

    for (int i = 0; i < length; i++) {
        if (message[i + 1] == TERMINATING_CHARACTER) {
            if (message[i] != BIGGEST_ALPHABET_LETTER) {
                decryptedCharacter = getNextLetter(message[i]);
            }

            break;
        }

        if (message[i] != message[i + 1] && getNextLetter(message[i]) != message[i + 1]) {
            decryptedCharacter = getNextLetter(message[i]);
            break;
        }
    }

    return decryptedCharacter;
}

char getNextLetter(char letter) {
    if (letter == 'Z') {
        return 'a';
    }

    return (char) ((int) letter + 1);
}

void swap(char array[], int firstIndex, int secondIndex) {
    char temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

void selectionSort(char array[]) {
    int minElementIndex;
    for (int i = 0; i < STRING_SIZE; i++) {
        if (array[i] == TERMINATING_CHARACTER) {
            break;
        }

        minElementIndex = i;
        for (int j = i + 1; j < STRING_SIZE; j++) {
            if (array[j] == TERMINATING_CHARACTER) {
                break;
            }

            if (array[j] < array[minElementIndex]) {
                minElementIndex = j;
            }
        }

        if (minElementIndex != i) {
            swap(array, i, minElementIndex);
        }
    }
}

bool isLower(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

bool isUpper(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

bool isValidLine(char line[]) {
    for (int i = 0; i < STRING_SIZE; i++) {
        if (line[i] == TERMINATING_CHARACTER) {
            return true;
        }

        if (!(isUpper(line[i]) || isLower(line[i]))) {
            return false;
        }
    }

    return true;
}