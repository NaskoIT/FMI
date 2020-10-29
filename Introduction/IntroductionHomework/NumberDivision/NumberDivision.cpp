#include <iostream>
using namespace std;

int main()
{
	int number;
	cin >> number;
	int firstDivisor = 0;
	int secondDivisor = 0;
	int thirdDivisor = 0;
	int minSum = INT_MAX;

	for (int i = 1; i <= cbrt(number); i++)
	{
		if (number % i != 0)
		{
			continue;
		}

		for (int j = i + 1; j <= sqrt(number / i); j++)
		{
			if (number % j != 0)
			{
				continue;
			}

			int thirdTempDivisor = number / (i * j);
			int currentSum = i + j + thirdTempDivisor;
			if (minSum > currentSum)
			{
				firstDivisor = i;
				secondDivisor = j;
				thirdDivisor = thirdTempDivisor;
				minSum = currentSum;
			}
		}
	}

	cout << firstDivisor << " " << secondDivisor << " " << thirdDivisor;
}