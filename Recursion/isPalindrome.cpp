#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string sequence, int index = 0);

int main() {
    string input;
    cin >> input;

    cout << isPalindrome(input);
}

bool isPalindrome(string sequence, int index) {
    if (index == sequence.length() / 2) {
        return true;
    } else if (sequence[index] != sequence[sequence.length() - 1 - index]) {
        return false;
    }

    return isPalindrome(sequence, index + 1);
}