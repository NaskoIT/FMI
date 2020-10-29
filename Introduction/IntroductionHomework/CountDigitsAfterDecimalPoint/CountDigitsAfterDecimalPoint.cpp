#include <iostream>
using namespace std;

int main()
{
	int inputNumber;
	cin >> inputNumber;
	int number = inputNumber;

	while (true)
	{
		if (number % 2 == 0)
		{
			number /= 2;
		}
		else if (number % 5 == 0) 
		{
			number /= 5;
		}
		else 
		{
			break;
		}
	}

	if (number == 1) 
	{
		double reciprocalNumber = 1.0 / inputNumber;
		int digitsAfterDeciamalPoint = 0;

		while (reciprocalNumber > int(reciprocalNumber)) 
		{
			digitsAfterDeciamalPoint++;
			reciprocalNumber *= 10;
		}

		cout << digitsAfterDeciamalPoint << endl;
	}
	else 
	{
		cout << "NO" << endl;
	}
}
