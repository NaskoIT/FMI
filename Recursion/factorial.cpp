#include <iostream>

using namespace std;

long long factorial(int n);

int main() {
    int n;
    cin >> n;

    cout << factorial(n);
}

long long factorial(int n) {
    if(n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}
