#include <iostream>

using namespace std;

int *readArray(int size) {
    int *array = new int[size];

    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    return array;
}

int *buildNewSortedArray(const int *firstArray, int firstArraySize, const int *secondArray, int secondArraySize) {
    int *resultArray = new int[firstArraySize + secondArraySize];
    int firstArrayIndex = 0;
    int secondArrayIndex = 0;
    int resultArrayIndex = 0;

    while (firstArrayIndex < firstArraySize && secondArrayIndex < secondArraySize) {
        if (firstArray[firstArrayIndex] <= secondArray[secondArrayIndex]) {
            resultArray[resultArrayIndex++] = firstArray[firstArrayIndex++];
        } else {
            resultArray[resultArrayIndex++] = secondArray[secondArrayIndex++];
        }
    }

    while (firstArrayIndex < firstArraySize) {
        resultArray[resultArrayIndex++] = firstArray[firstArrayIndex++];
    }

    while (secondArrayIndex < secondArraySize) {
        resultArray[resultArrayIndex++] = secondArray[secondArrayIndex++];
    }

    return resultArray;
}

int main() {
    int n;
    cin >> n;
    int *firstArray = readArray(n);

    int m;
    cin >> m;
    int *secondArray = readArray(m);

    int* resultArray = buildNewSortedArray(firstArray, n, secondArray, m);
    delete[] firstArray;
    delete[] secondArray;

    for (int i = 0; i < n + m; ++i) {
        cout << resultArray[i] << " ";
    }

    delete[] resultArray;
    cout << endl;
}