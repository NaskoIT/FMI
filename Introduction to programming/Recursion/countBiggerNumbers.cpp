#include <iostream>

using namespace std;

const int ARRAY_SIZE = 5;

int countBiggerNumbers(int array[], int size, int bound, int index = 0);

int main() {
    int n;
    cin >> n;

    int array[] = {1, 5, -2, 3, 6};

    cout << countBiggerNumbers(array, ARRAY_SIZE, n);
}

int countBiggerNumbers(int array[], int size, int bound, int index) {
    if (index == size) {
        return 0;
    }

    int currentCount = array[index] > bound ? 1 : 0;
    return currentCount + countBiggerNumbers(array, size, bound, index + 1);
}
