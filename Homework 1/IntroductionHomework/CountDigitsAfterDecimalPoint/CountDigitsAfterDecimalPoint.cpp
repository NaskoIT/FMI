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

int countDigitsAfterDecimalPoint(int numerator, int denominator)
{
	int count = 0;
	while (numerator % denominator != 0) 
	{
		numerator = numerator % denominator;
		numerator *= 10;
		count++;
	}

	return count;
}

int main()
{
	int inputNumber;
	cin >> inputNumber;
	while (!cin || inputNumber < 2 || inputNumber > pow(10, 9))
	{
		cin >> inputNumber;
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
		cout << countDigitsAfterDecimalPoint(1, inputNumber) << endl;
	}
	else 
	{
		cout << "NO" << endl;
	}

	return 0;
}
