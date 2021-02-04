// task 1
int analyzeArray(int arr[], int length) {
    if (length < 2) {
        return 0;
    }

    for (int i = 1; i < length - 1; ++i) {
        int leftSum = 0;
        for (int j = 0; j <= i; ++j) {
            leftSum += arr[j];
        }

        int rightSum = 0;
        for (int j = i + 1; j < length; ++j) {
            rightSum += arr[j];
        }

        if (leftSum == rightSum) {
            return 1;
        }
    }

    return 0;
}

// task 2
const char TERMINATING_SYMBOL = '\0';

int getLength(const char *str) {
    int length = 0;
    while (str[length] != TERMINATING_SYMBOL) {
        length++;
    }

    return length;
}

bool doExist(char *symbols, char *word) {
    int symbolsLength = getLength(symbols);
    int wordLength = getLength(word);

    if (symbolsLength < wordLength) {
        return false;
    }

    int lowerBound = symbolsLength - wordLength - 1;
    for (int i = symbolsLength - 1; i >= lowerBound; i--) {
        bool areEqual = true;
        for (int j = 0; j < wordLength; ++j) {
            if (symbols[i - j] != word[j]) {
                areEqual = false;
            }
        }

        if (areEqual) {
            return true;
        }
    }

    return false;
}

// task 3
double calculateMatrix(int **matrix, int m) {
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j || i + j == m - 1) {
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}
