#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 5 -> 10 20 20 40 50 -> 20 -> true
    // 2 -> 10 10 -> 10-> true
    // 3 -> 10 15 10 -> 10 -> fasle
    // 1 -> 1 -> 1 -> false

    int n;
    cin >> n;
    if (n == 0)
    {
        return 0;
    }

    vector<int> numbers(n);

    for (int i = 0; i < numbers.size(); i++)
    {
        cin >> numbers[i];
    }

    for (int i = 1; i < numbers.size(); i++)
    {
        numbers[i] += numbers[i - 1];
    }
    
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
}