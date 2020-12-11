#include <iostream>
using namespace std;

long long pow(int base, int degree);

int main() {
    int base;
    cout << "Enter base" << endl;
    cin >> base;

    int degree;
    cout << "Enter degree" << endl;
    cin >> degree;

    cout << pow(base, degree);
}

long long pow(int base, int degree) {
    if(degree == 0) {
        return 1;
    }

    return base * pow(base, degree - 1);
}
