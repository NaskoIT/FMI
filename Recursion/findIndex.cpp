#include <iostream>

using namespace std;

const int ARRAY_SIZE = 5;

int findIndex(int array[], int size, int targetElement);

int main() {
    int array[] = { 1, 5, -2, 3, 6 };

    cout << findIndex(array, ARRAY_SIZE, 1) << endl;
    cout << findIndex(array, ARRAY_SIZE, -2) << endl;
    cout << findIndex(array, ARRAY_SIZE, 6) << endl;
    cout << findIndex(array, ARRAY_SIZE, 0) << endl;
}

int findIndex(int array[], int size, int index, int targetElement) {
    if(index == size) {
        return -1;
    }
    else if(array[index] == targetElement) {
        return index;
    }

    findIndex(array, size, index + 1, targetElement);
}

int findIndex(int array[], int size, int targetElement) {
    return findIndex(array, size, 0, targetElement);
}
