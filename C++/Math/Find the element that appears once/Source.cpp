#include <iostream>

int findTheElement(int _arr[], const int _ARRAY_LENGTH);

int main()
{
	int arr[] = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 3 };
	const int ARRAY_LENGHT = sizeof(arr) / sizeof(int);

	std::cout << findTheElement(arr, ARRAY_LENGHT) << std::endl; // -> Output: 2

	return 0;
}

int findTheElement(int _arr[], const int _ARRAY_LENGTH)
{
	int ones = 0;

	for (size_t i = 0; i < _ARRAY_LENGTH; i++)
	{
		int mismatches = 0; // must be equal to the ARRAY_LENGHT

		for (size_t j = 0; j < _ARRAY_LENGTH; j++)
		{
			if (_arr[i] != _arr[j])
			{
				mismatches++;

				if (mismatches + 1 == _ARRAY_LENGTH)
				{
					ones = _arr[i];
				}
			}
		}
	}

	return ones;
}
