/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 1
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int terminateProgram()
{
	cout << "-1";
	return -1;
}

int main()
{
	const double MONEY_GIFT = 30;
	const double BIRTHDAY_EXPENSES = 5;
	const double ADDED_MONEY_TO_GIFT = 30;
	int age;
	double laptopPrice;
	double presentPrice;

	cin >> age;
	if(!cin || age <= 0) 
	{
		return terminateProgram();
	}

	cin >> laptopPrice;
	if (!cin || laptopPrice <= 0)
	{
		return terminateProgram();
	}

	cin >> presentPrice;
	if (!cin || presentPrice <= 0)
	{
		return terminateProgram();
	}

	int evenBirthdays = age / 2;
	// Sum first elements n of some arithmetic progression formula (2 * a + (n - 1) * d) * (n / 2)
	double evenBirtdaysReceivedMoney = ((2 * MONEY_GIFT + ((double)evenBirthdays - 1) * ADDED_MONEY_TO_GIFT) / 2) * evenBirthdays;
	double evenBirthdaysExpenses = evenBirthdays * BIRTHDAY_EXPENSES;

	int oddBirthdays = age - evenBirthdays;
	double oddBirthdaysReceivedMoney = oddBirthdays * presentPrice;

	double totalReceivedMoney = evenBirtdaysReceivedMoney - evenBirthdaysExpenses + oddBirthdaysReceivedMoney;

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

	return 0;
}
