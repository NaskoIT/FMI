int parseDigit(char symbol) {
    return symbol - '0';
}

bool isDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

bool tryParseNumber(char str[], int startIndex, int endIndex, int &number) {
    int multiplier = 1;
    for (int i = endIndex; i >= startIndex ; i--) {
        if(!isDigit(str[i])) {
            return false;
        }

        int digit = parseDigit(str[i]);
        number += multiplier * digit;
        multiplier *= 10;
    }

    return true;
}

int getLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

bool isValidMonth(int month) {
    return month >= 1 && month <= 12;
}

bool isValidDay(int days, int month) {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int maxDaysInMonth = daysInMonth[month - 1];

    return days >= 0 && days <= maxDaysInMonth;
}

bool checkDate(char date[]) {

    int length = getLength(date);
    if(length != 5) {
        return false;
    }

    if(date[2] != '.') {
        return false;
    }

    int month = 0;
    int day = 0;
    if(!tryParseNumber(date, 3, 4, month) || !tryParseNumber(date, 0, 1, day)) {
        return false;
    }

    return isValidMonth(month) && isValidDay(day, month);
}
