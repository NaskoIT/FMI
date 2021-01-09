#include<iostream>

using namespace std;

const char DEFAULT_DELIMITER[] = ", ";

template<typename T>
void printArray(const T *array, size_t size, const char delimiter[]);

template<typename T>
void insertAt(T *array, size_t &size, T element, size_t index);

template<typename T>
void removeAt(T *array, size_t &size, size_t index);

int main() {
    size_t size = 6;
    int array[10] = {10, 20, 30, 40, 50, 60};
    printArray<int>(array, size, DEFAULT_DELIMITER);

    insertAt(array, size, 15, 1);
    printArray<int>(array, size, DEFAULT_DELIMITER);

    insertAt(array, size, 70, 7);
    printArray<int>(array, size, DEFAULT_DELIMITER);

    insertAt(array, size, 5, 0);
    printArray<int>(array, size, DEFAULT_DELIMITER);

    removeAt<int>(array, size, 0);
    printArray<int>(array, size, DEFAULT_DELIMITER);

    removeAt<int>(array, size, 7);
    printArray<int>(array, size, DEFAULT_DELIMITER);

    removeAt<int>(array, size, 1);
    printArray<int>(array, size, DEFAULT_DELIMITER);
}

template<typename T>
void shiftRight(T *array, size_t size, size_t startFrom, size_t positions) {
    if (array == nullptr) {
        return;
    }

    size_t writeIndex = size + positions - 1;
    size_t readIndex = size - 1;

    // readIndex should be less than size because when readIndex becomes zero and then readIndex-- will lead to overflow of size_t and readIndex will become size_t max value
    while (readIndex >= startFrom && readIndex < size) {
        array[writeIndex--] = array[readIndex--];
    }
}

template<typename T>
void shiftLeft(T *array, size_t size, size_t startFrom, std::size_t positions) {
    if (array == nullptr) {
        return;
    }

    size_t writeIndex = startFrom;
    size_t readIndex = startFrom + positions;
    while (readIndex < size) {
        array[writeIndex++] = array[readIndex++];
    }
}

template<typename T>
void removeAt(T *array, size_t &size, size_t index) {
    if (array == nullptr || index >= size) {
        return;
    }

    shiftLeft(array, size, index, 1);
    size--;
}

template<typename T>
void insertAt(T *array, size_t &size, T element, size_t index) {
    if (array == nullptr || index > size) {
        return;
    }

    shiftRight(array, size, index, 1);
    size++;

    array[index] = element;
}

template<typename T>
void printArray(const T *array, size_t size, const char delimiter[]) {
    if (array == nullptr) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        cout << array[i];
        if (i < size - 1) {
            cout << delimiter;
        }
    }

    cout << endl;
}