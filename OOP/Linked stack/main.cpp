#include <iostream>
#include "linkedStack.h"

using namespace std;

int main() {
    LinkedStack<int> stack;

    cout << "Number: ";
    int n;
    cin >> n;

    int x = n;
    while (x)
    {
        stack.push(x % 2);
        x /= 2;
    }

    while (!stack.empty())
    {
        cout << stack.pop();
    }

    cout << endl;
}