const char TERMINATING_SYMBOL = '\0';

char revertSymbol(char symbol) {
    int differenceBetweenUpperAndLowerCase = 'a' - 'A';
    if(symbol >= 'a' && symbol <= 'z') {
        return (char)(symbol - differenceBetweenUpperAndLowerCase);
    }
    else if(symbol >= 'A' && symbol <= 'Z') {
        return (char)(symbol + differenceBetweenUpperAndLowerCase);
    }
}

void revert(char array[]) {
    int index = 0;
    while (array[index] != TERMINATING_SYMBOL) {
        array[index] = revertSymbol(array[index]);
        index++;
    }
}