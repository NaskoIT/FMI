/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 1
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

bool isStringCorrect(char str[]);

void getLetterOccurrences(char str[], int occurrences[], int size);

const int MAX_SIZE = 151;
const int ASCII_TABLE_SIZE = 128;
const char TERMINATING_CHARACTER = '\0';

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    cout << isStringCorrect(str) << endl;
}

bool isStringCorrect(char str[]) {
    int occurrences[ASCII_TABLE_SIZE];
    getLetterOccurrences(str, occurrences, ASCII_TABLE_SIZE);

    int minOccurrences = MAX_SIZE;
    int maxOccurrences = 0;
    for (int i = 0; i < ASCII_TABLE_SIZE; i++) {
        int currentLetterOccurrences = occurrences[i];
        if (currentLetterOccurrences > 0 && currentLetterOccurrences < minOccurrences) {
            minOccurrences = currentLetterOccurrences;
        }

        if (currentLetterOccurrences > maxOccurrences) {
            maxOccurrences = currentLetterOccurrences;
        }
    }

    int occurrencesDifference = maxOccurrences - minOccurrences;
    if (occurrencesDifference == 0) {
        return true;
    } else if (minOccurrences == 1) {
        int minOccurrencesCount = 0;
        for (int i = 0; i < ASCII_TABLE_SIZE; i++) {
            if (occurrences[i] == minOccurrences) {
                minOccurrencesCount++;
            }

            if (minOccurrencesCount > 1) {
                break;
            }
        }

        if (minOccurrencesCount == 1) {
            for (int i = 0; i < ASCII_TABLE_SIZE; i++) {
                int currentOccurrences = occurrences[i];
                if (currentOccurrences != 0 &&
                    currentOccurrences != minOccurrences &&
                    currentOccurrences != maxOccurrences) {
                    return false;
                }
            }

            return true;
        }
    }

    if (occurrencesDifference == 1) {
        int maxOccurrencesCount = 0;
        for (int i = 0; i < ASCII_TABLE_SIZE; i++) {
            if (occurrences[i] == maxOccurrences) {
                maxOccurrencesCount++;
            }

            if (maxOccurrencesCount > 1) {
                return false;
            }
        }
    } else if (occurrencesDifference > 1) {
        return false;
    }

    return true;
}

void getLetterOccurrences(char str[], int occurrences[], int size) {
    for (int i = 0; i < size; i++) {
        occurrences[i] = 0;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        if (str[i] == TERMINATING_CHARACTER) {
            break;
        }

        unsigned int index = str[i];
        occurrences[index]++;
    }
}