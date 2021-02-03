#include <iostream>
#include "Solutions.h"

using namespace std;

void testFirstTask() {
	int result = firstTask(10, 15);
	cout << result;
}

void testSecondTask() {
	int size = 4;
	double arr[] = { 10.5, 19.5, 30, 50 };
	cout << secondTask(arr, size);
}

void testThirdTask() {
	int lowerBound = 10;
	int upperBound = 25;
	int size = upperBound - lowerBound + 1;
	int* sequence = thirdTask(10, 25);
	
	for (int i = 0; i < size; i++)
	{
		cout << sequence[i] << " ";
	}

	cout << endl;
	delete[] sequence;
}

int main()
{
	testThirdTask();
}
