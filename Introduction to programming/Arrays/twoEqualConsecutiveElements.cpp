#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //Task 2
    // 5 -> 10 20 20 40 50 -> 20 -> true
    // 2 -> 10 10 -> 10-> true
    // 3 -> 10 15 10 -> 10 -> fasle
    // 1 -> 1 -> 1 -> false

    int n;
    cin >> n;
    if (n <= 0)
    {
        return 1;
    }
    
    vector<int> numbers(n);

    for (int i = 0; i < numbers.size(); i++)
    {
        cin >> numbers[i];
    }

    int targetNumber;
    cin >> targetNumber;

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] == targetNumber && numbers[i] == numbers[i + 1])
        {
            cout << "true";
            return 0;
        }
    }

    cout << "false";
    return 0;
}
