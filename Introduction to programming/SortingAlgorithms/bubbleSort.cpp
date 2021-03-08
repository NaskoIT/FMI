#include<iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<double>& array);

int main() {
    cout << "bubble sort demo." << endl;
    vector<double> array = {15, 25, 10, -7, 55, 100, -100};
    bubbleSort(array);

    for (double i : array) {
        cout << i << " ";
    }
}

void swap(vector<double> &array, int firstIndex, int secondIndex) {
    double temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

void bubbleSort(vector<double>& array) {
    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = array.size() - 1; j > i; j--) {
            if(array[j - 1] > array[j]) {
                swap(array, j - 1, j);
            }
        }
    }
}