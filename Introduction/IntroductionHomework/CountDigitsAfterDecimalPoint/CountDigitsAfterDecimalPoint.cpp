/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 5
* @compiler VC
*
*/


#include <iostream>
using namespace std;

int main()
{
	int inputNumber;
	cin >> inputNumber;
	if (!cin || inputNumber < 2 || inputNumber > pow(10, 9))
	{
		cout << "-1";
		return -1;
	}

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
