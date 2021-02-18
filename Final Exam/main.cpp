#include <iostream>
#include "solutions.h"
using namespace std;

void testRevAndReplace() {
    char input[] = " I left you alone ";
    //  !nola uo* tf!l I
    //  !nola uo* tf!l I
    char* result = revandreplace(input);
    cout << "start" << result << "end" << endl;
    delete[] result;
}

void testCheckDate() {
    char date[] = "2000 g.";
    cout << CheckDate(date);
}

void testCountLetters() {
    int a[] = {30, 91, 40, 2,  90, 5, 122, 100, 25};
    int b[] = {35, -1, 40, -50, 8, 0, 0, 100, 0 };

    int* result =  countletters(a, b, 8);
    cout << result[0] << " -> " << result[1] << endl;
    delete[] result;
}

int main() {
    testCountLetters();
}
