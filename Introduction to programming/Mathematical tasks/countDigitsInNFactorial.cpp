#include <iostream>
#include <cmath>

using namespace std;

int countDigitsInNFactorial(int n) {
    double result = 0;

    for (int i = 2; i <= n; ++i) {
        result += log10((double)i);
    }

    return (int)result + 1;
}

int main() {
    int n;
    cin >> n;

    cout << countDigitsInNFactorial(n);
}