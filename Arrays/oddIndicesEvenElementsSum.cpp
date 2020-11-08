#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 5 -> 10 20 30 40 50 -> 60
    // 6 -> 10 15 20 25 20 2 -> 2
    // 1 -> 1 -> 0
    // 2 -> 1 1 -> 0
    // 2 -> 1 2 -> 2
    // 4 -> -2 -2 3 10 -> 8

    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < numbers.size(); i++)
    {
        cin >> numbers[i];
    }

    int sum = 0;
    for (int i = 1; i < numbers.size(); i += 2)
    {
        int currentNumber = numbers[i];
        if (currentNumber % 2 == 0)
        {
            sum += currentNumber;
        }
    }

    cout << sum;
    return 0;
}