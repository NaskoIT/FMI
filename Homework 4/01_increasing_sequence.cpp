/**
*
* Solution to homework assignment 4
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

const int ERROR_EXIT_CODE = -1;
const int SUCCESS_EXIT_CODE = 0;

bool canSequenceBecomeIncreasing(const int *sequence, int length, int possibleChangesCount);

bool isNaturalNumber(int number);

int main() {
    int possibleChangesCount;
    cin >> possibleChangesCount;
    if (!isNaturalNumber(possibleChangesCount)) {
        cout << ERROR_EXIT_CODE;
        return SUCCESS_EXIT_CODE;
    }

    int length;
    cin >> length;
    if (!isNaturalNumber(length)) {
        cout << ERROR_EXIT_CODE;
        return SUCCESS_EXIT_CODE;
    }

    int *sequence = new int[length];
    for (int i = 0; i < length; i++) {
        cin >> sequence[i];
        if (!isNaturalNumber(sequence[i])) {
            cout << ERROR_EXIT_CODE << endl;
            return SUCCESS_EXIT_CODE;
        }
    }

    cout << canSequenceBecomeIncreasing(sequence, length, possibleChangesCount);

    delete[] sequence;

    return SUCCESS_EXIT_CODE;
}

int getLongestIncreasingSubsequenceCount(const int *sequence, int length) {
    int *bestLengths = new int[length];
    int maxLength = 1;

    for (int i = 0; i < length; i++) {
        bestLengths[i] = 1;
        for (int j = 0; j < i; j++) {
            if (sequence[i] >= sequence[j] && bestLengths[j] + 1 > bestLengths[i]) {
                bestLengths[i] = bestLengths[j] + 1;
            }
        }

        if (maxLength < bestLengths[i]) {
            maxLength = bestLengths[i];
        }
    }

    delete[] bestLengths;
    return maxLength;
}

bool canSequenceBecomeIncreasing(const int *sequence, int length, int possibleChangesCount) {
    if (length == 0) {
        return true;
    }

    int neededChanges = length - getLongestIncreasingSubsequenceCount(sequence, length);
    return neededChanges <= possibleChangesCount;
}

bool isNaturalNumber(int number) {
    return number > 0;
}