#include<iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<double>& array);

int main() {
    cout << "insertion sort demo." << endl;
    vector<double> array = {15, 25, 10, -7, 55, 100, -100};
    insertionSort(array);

    for (double i : array) {
        cout << i << " ";
    }
}

void bubbleSort(vector<double>& array) {
    double minElement = 0;
    int j = 0;
    for (int i = 0; i < array.size(); i++) {
        minElement = array[i];
        for (j = i - 1; j >= 0; j--) {
            if(array[j] <= minElement) {
                break;
            }

            array[j + 1] = array[j];
        }

        array[j + 1] = minElement;
    }
}