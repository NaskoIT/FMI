#include <iostream>
#include "Solutions.h"

void testCheckRectangular() {
    Point a = {1, 0};
    Point b = {1, 3};
    Point c = {5, 0};

    cout << CheckRectangular(a, b, c) << endl;
}

void testSolve() {
    char equation[] = "1*х^2+3*x+2=0";
    cout << Solve(equation);
}

void testExtract() {
    int* arr = Extract(-223441 );
    for (int i = 0; i < 3; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
    delete[] arr;
}

int main() {
    testExtract();
}
