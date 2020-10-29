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

int main()
{
	int firstNumber;
	int secondNumber;
	int thirdNumber;
	cin >> firstNumber;
	cin >> secondNumber;
	cin >> thirdNumber;

	int firstPalindrome = buildPalindromeNumber(firstNumber, min(secondNumber, thirdNumber), max(secondNumber, thirdNumber));
	int secondPalindrome = buildPalindromeNumber(secondNumber, min(firstNumber, thirdNumber), max(firstNumber, thirdNumber));
	int thirdPalindrome = buildPalindromeNumber(thirdNumber, min(firstNumber, secondNumber), max(firstNumber, secondNumber));

	int smallestPalindrome = min(firstPalindrome, min(secondPalindrome, thirdPalindrome));
	cout << smallestPalindrome;
}