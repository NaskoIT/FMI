// Atanas Vasilev - 62577
// Izpit_UP_20210205_1_62577_gcc.h

const char TERMINATING_SYMBOL = '\0';

// task 1
char *revandreplace(char *str) {
    int length = 0;
    while (str[length] != TERMINATING_SYMBOL) {
        length++;
    }

    int index = 0;
    char *reversed = new char[length];
    while (index < length) {
        char symbol = str[length - index - 1];
        if (symbol == 'e') {
            reversed[index] = '!';
        } else if (symbol == 'y') {
            reversed[index] = '*';
        } else {
            reversed[index] = symbol;
        }

        index++;
    }

    reversed[index] = TERMINATING_SYMBOL;
    return reversed;
}

// task 2
// YYYY g.
int parseDigit(char symbol) {
    if (symbol >= '0' && symbol <= '9') {
        return symbol - '0';
    }
}

bool CheckDate(char dateAsString[]) {
    int year = 0;
    int multiplier = 1000;
    for (int i = 0; i < 4; ++i) {
        int digit = parseDigit(dateAsString[i]);
        year += digit * multiplier;
        multiplier /= 10;
    }

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }

        return true;
    }

    return false;
}

// task 3
bool isUpperLetter(int code) {
    if (code >= 'A' && code <= 'Z') {
        return true;
    }

    return false;
}

bool isLowerLetter(int code) {
    if (code >= 'a' && code <= 'z') {
        return true;
    }

    return false;
}

int *countletters(int firstArr[], int secondArr[], int N) {
    int upperLettersCount = 0;
    int lowerLettersCount = 0;

    for (int i = 0; i < N; ++i) {
        int code = firstArr[i] + secondArr[i];
        if (isUpperLetter(code)) {
            upperLettersCount++;
        } else if (isLowerLetter(code)) {
            lowerLettersCount++;
        }
    }

    int *result = new int[2];
    result[0] = upperLettersCount;
    result[1] = lowerLettersCount;
    return result;
}