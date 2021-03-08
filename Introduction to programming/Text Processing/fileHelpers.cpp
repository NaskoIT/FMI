#include <iostream>
#include <fstream>

using namespace std;

const int STRING_SIZE = 1000;

int appendToFile(char str[], char filename[]) {
    ofstream file(filename, ios::app);

    if(!file.is_open()) {
        return 1;
    }

    file << str << endl;

    file.close();

    return 0;
}

int readLineFromFile(char filename[], char destination[], int size, int line) {
    ifstream file(filename);

    // Unable to open file
    if(!file.is_open()) {
        return 1;
    }

    int lineNumber = 1;
    while ((lineNumber++ <= line) && (file.getline(destination, size)));

    if(file.eof() && (line + 2 != lineNumber)) {
        // File is shorter than requested
        return 2;
    }

    file.close();
    return 0;
}

int printFileContent(char filename[]) {
    ifstream file(filename);

    if(!file.is_open()) {
        return 1;
    }

    char line[STRING_SIZE];
    while (!file.eof()) {
        file.getline(line, STRING_SIZE);
        cout << line << endl;
    }

    return 0;
}

int main() {
}
