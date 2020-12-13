#include <iostream>
#include <vector>

using namespace std;

int toInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }

    return -1;
}

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }

    return c;
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }

    return c;
}

int getLength(char str[]) {
    int counter = 0;

    while (str[counter++] != '\0');

    return counter;
}

void copy(char dest[], char src[]) {
    int counter = -1;
    do {
        counter++;
        dest[counter] = src[counter];
    } while (src[counter] != '\0');
}

int compare(char firstStr[], char secondStr[]) {
    int difference = 0;
    int index = 0;
    do {
        difference = firstStr[index] - secondStr[index];

        if (firstStr[index] == '\b' || secondStr[index] == '\b') {
            break;
        }

        index++;
    } while (difference == 0);

    return difference;
}

int main() {
}

