// Atanas Vasilev - 62577

#include <iostream>
#include <vector>

using namespace std;

vector<int> readNumbers(int n);

bool isInRange(int index, int length);

void printNumbers(vector<int> numbers);

void reverse(vector<int> &numbers, int start, int end);

void swap(vector<int> &numbers, int firstIndex, int secondIndex);

int main() {
    int n;
    cin >> n;
    vector<int> numbers = readNumbers(n);

    int start, end;
    cin >> start;
    cin >> end;

    printNumbers(numbers);

    if (isInRange(start, n) && isInRange(end, n)) {
        reverse(numbers, start, end);
    }

    printNumbers(numbers);
}

vector<int> readNumbers(int n) {
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    return numbers;
}

void printNumbers(vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;
}

bool isInRange(int index, int length) {
    if (index < 0 || index >= length) {
        return false;
    }

    return true;
}

void reverse(vector<int> &numbers, int start, int end) {
    if (end <= start) {
        return;
    }

    swap(numbers, start, end);

    reverse(numbers, start + 1, end - 1);
}

void swap(vector<int> &numbers, int firstIndex, int secondIndex) {
    int temp = numbers[firstIndex];
    numbers[firstIndex] = numbers[secondIndex];
    numbers[secondIndex] = temp;
}
