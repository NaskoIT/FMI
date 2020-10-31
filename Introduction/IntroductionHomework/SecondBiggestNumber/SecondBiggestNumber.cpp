/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 2
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int biggestNumber = num;
	int secondBiggestNumber = INT_MIN;

	while (num > 0) 
	{
		if (biggestNumber < num) 
		{
			secondBiggestNumber = biggestNumber;
			biggestNumber = num;
		}
		else if (biggestNumber > num && secondBiggestNumber < num) 
		{
			secondBiggestNumber = num;
		}

		cin >> num;
	}

	if (secondBiggestNumber == INT_MIN) 
	{
		cout << "-1";
		return -1;
	}
	else 
	{
		cout << secondBiggestNumber;
	}

	return 0;
}
