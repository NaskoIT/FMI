#include <iostream>
#include <string>

using namespace std;

void reverse(string &sequence, int index = 0);

int main() {
    string sequence;
    cin >> sequence;

    reverse(sequence);

    cout << sequence;
}


void reverse(string &sequence, int index) {
    if (index == sequence.length() / 2) {
        return;
    }

    char temp = sequence[index];
    sequence[index] = sequence[sequence.length() - index - 1];
    sequence[sequence.length() - index - 1] = temp;

    reverse(sequence, index + 1);
}