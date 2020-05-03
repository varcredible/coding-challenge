#include <iostream>

int findSubarray(int _arr[], const unsigned int _ARRAY_LENGTH, int _sum);

int main()
{
	int arr[] = { 1, 4, 0, 0, 3, 10, 5 };
	const unsigned int ARRAY_LENGTH = sizeof(arr) / sizeof(int);
	int sum = 7;
	findSubarray(arr, ARRAY_LENGTH, sum);
}

int findSubarray(int _arr[], const unsigned int _ARRAY_LENGTH, int _sum)
{
	int sumOfTheElements = 0;
	int nextIndexNumber = 0;

	for (size_t indexNumber = 0; indexNumber < _ARRAY_LENGTH; indexNumber++)
	{
		if (sumOfTheElements < _sum || _sum == 0)
		{
			sumOfTheElements += _arr[indexNumber];
		}

		else if(sumOfTheElements == _sum)
		{
			printf("Sum found between indexes %d and %d", nextIndexNumber, indexNumber - 1);
			return 0;
		}

		else
		{
			sumOfTheElements = 0;
			nextIndexNumber++;
			indexNumber = nextIndexNumber - 1;
		}
	}

	printf("No subarray found");
	return 0;
}