/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 4
* @compiler VC
*
*/


#include <iostream>
using namespace std;

int main()
{
	int number;

	do
	{
		cin >> number;
	} while (!cin || number <= 0 || number > pow(10, 9));

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

		for (int j = i; j <= sqrt(number / i); j++)
		{
			int currentDivisor = i * j;
			if (number % currentDivisor == 0)
			{
				int thirdTempDivisor = number / currentDivisor;
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
	}

	cout << firstDivisor << " " << secondDivisor << " " << thirdDivisor;
	return 0;
}