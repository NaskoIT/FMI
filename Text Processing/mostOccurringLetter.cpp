#include <iostream>

using namespace std;

const int ALPHABET_COUNT = 26;
const char LOWER_A = 'a';

char getMostOccurringSymbol(const char* str) {
    int occurrences[ALPHABET_COUNT];
    for (int i = 0; i < ALPHABET_COUNT; ++i) {
        occurrences[i] = 0;
    }

    char mostOccurringLetter;
    int mostOccurringLetterCount = 0;

    int index = 0;
    while (str[index] != '\0') {
        int symbolIndex = str[index] - LOWER_A;
        occurrences[symbolIndex]++;

        if(occurrences[symbolIndex] > mostOccurringLetterCount) {
            mostOccurringLetterCount = occurrences[symbolIndex];
            mostOccurringLetter = str[index];
        }

        index++;
    }

    return mostOccurringLetter;
}

int main() {
    char str[100];
    cin >> str;

    cout << getMostOccurringSymbol(str);
}