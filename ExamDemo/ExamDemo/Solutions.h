// Only this file should be uploaded in Moodle
// This file should be created in the beginning of the exam because we cannot paste code in this file. 

int firstTask(int a, int b) {
	return a + b;
}

double secondTask(double arr[], int size) {
	double sum = 0.0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int* thirdTask(int lowerBound, int upperBound) {
	int size = upperBound - lowerBound + 1;
	int* sequence = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		sequence[i] = lowerBound + i;
	}

	return sequence;
}

