/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 3
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int buildPalindromeNumber(int firstNumber, int secondNumber, int thirdNumber)
{
	if (firstNumber == 0)
	{
		return INT_MAX;
	}

	int number = firstNumber * 10000 + secondNumber * 1000 + thirdNumber * 100 + secondNumber * 10 + firstNumber;
	return number;
}

int buildThreeDigitNumber(int firstNumber, int secondNumber, int thirdNumber)
{
	return firstNumber * 100 + secondNumber * 10 + thirdNumber;
}

bool isDigit(int number)
{
	return number >= 0 && number <= 9;
}

int main()
{
	int firstNumber;
	int secondNumber;
	int thirdNumber;

	do
	{
		cin >> firstNumber;
	} while (!cin || !isDigit(firstNumber));

	do
	{
		cin >> secondNumber;
	} while (!cin || !isDigit(secondNumber));

	do
	{
		cin >> thirdNumber;
	} while (!cin || !isDigit(thirdNumber));

	int smallestPalindrome = 0;
	int zerosCount = 0;
	if (firstNumber == 0) 
	{
		zerosCount++;
	}
	if (secondNumber == 0)
	{
		zerosCount++;
	}
	if (thirdNumber == 0)
	{
		zerosCount++;
	}

	if (zerosCount == 3) 
	{
		smallestPalindrome = 0;
	}
	else if (zerosCount == 2)
	{
		int biggestNumber = max(firstNumber, max(secondNumber, thirdNumber));
		smallestPalindrome = biggestNumber * 1000 + biggestNumber;
	}
	else if(firstNumber == secondNumber && secondNumber == thirdNumber) 
	{
		smallestPalindrome = buildThreeDigitNumber(firstNumber, secondNumber, thirdNumber);
	}
	else if (firstNumber != 0 && firstNumber == secondNumber)
	{
		smallestPalindrome = buildThreeDigitNumber(firstNumber, thirdNumber, secondNumber);
	}
	else if (firstNumber != 0 && firstNumber == thirdNumber)
	{
		smallestPalindrome = buildThreeDigitNumber(firstNumber, secondNumber, thirdNumber);
	}
	else if (secondNumber != 0 && secondNumber == thirdNumber)
	{
		smallestPalindrome = buildThreeDigitNumber(secondNumber, firstNumber, thirdNumber);
	}
	else 
	{
		int firstPalindrome = buildPalindromeNumber(firstNumber, min(secondNumber, thirdNumber), max(secondNumber, thirdNumber));
		int secondPalindrome = buildPalindromeNumber(secondNumber, min(firstNumber, thirdNumber), max(firstNumber, thirdNumber));
		int thirdPalindrome = buildPalindromeNumber(thirdNumber, min(firstNumber, secondNumber), max(firstNumber, secondNumber));

		smallestPalindrome = min(firstPalindrome, min(secondPalindrome, thirdPalindrome));
	}

	cout << smallestPalindrome;
	return 0;
}