// Birthday.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	const int MONEY_GIFT = 30;
	const int BIRTHDAY_EXPENSES = 5;
	const int ADDED_MONEY_TO_GIFT = 30;
	int age;
	int laptopPrice;
	int presentPrice;

	cin >> age;
	cin >> laptopPrice;
	cin >> presentPrice;

	int evenBirthdays = age / 2;
	// Sum first elements n of some arithmetic progression formula
	int evenBirtdaysReceivedMoney = ((2 * MONEY_GIFT + (evenBirthdays - 1) * ADDED_MONEY_TO_GIFT) / 2) * evenBirthdays;
	int evenBirthdaysExpenses = evenBirthdays * BIRTHDAY_EXPENSES;

	int oddBirthdays = age - evenBirthdays;
	int oddBirthdaysReceivedMoney = oddBirthdays * presentPrice;

	int totalReceivedMoney = evenBirtdaysReceivedMoney - evenBirthdaysExpenses + oddBirthdaysReceivedMoney;

	if (totalReceivedMoney >= laptopPrice) 
	{
		cout << "yes" << endl;
		cout << totalReceivedMoney - laptopPrice;
	}
	else 
	{
		cout << "no" << endl;
		cout << laptopPrice - totalReceivedMoney;
	}
}
