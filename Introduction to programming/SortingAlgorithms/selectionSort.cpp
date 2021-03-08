#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<double> &array);

void swap(const vector<double> &array, int firstIndex, int secondIndex);

int main() {
    vector<double> array = {15, 25, 10, -7, 55, 100, -100};
    selectionSort(array);

    for (double i : array) {
        cout << i << " ";
    }
}

void swap(vector<double> &array, int firstIndex, int secondIndex) {
    double temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

void selectionSort(vector<double> &array) {
    int minElementIndex;
    for (int i = 0; i < array.size(); i++) {
        minElementIndex = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[minElementIndex]) {
                minElementIndex = j;
            }
        }

        if (minElementIndex != i) {
            swap(array, i, minElementIndex);
        }
    }
}

