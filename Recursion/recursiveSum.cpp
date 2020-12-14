#include <iostream>

using namespace std;

double sum(double collection[], int size, int index);

int main() {
    double array[] = { 1, 5.5, -2.5, 3, 5 };
    cout << sum(array, 5, 0);
}

double sum(double collection[], int size, int index) {
    if(size == index) {
        return 0;
    }

    return collection[index] + sum(collection, size, index + 1);
}