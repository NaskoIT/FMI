#include <iostream>
#include <vector>
using namespace std;

vector<int> fibonacci(int n);
void print(vector<int> values);

int main() {
    int n;
    cin >> n;

    vector<int> values = fibonacci(n);

    print(values);
}

vector<int> fibonacci(int n) {
    vector<int> values(n);
    values[0] = 0;
    values[1] = 1;


    for (int i = 2; i < n; i++) {
        values[i] = values[i - 2] + values[i - 1];
    }

    return values;
}

void print(vector<int> values) {
    for (int i = 0; i < values.size(); i++) {
        cout << values[i]<< " ";
    }

    cout << endl;
}
