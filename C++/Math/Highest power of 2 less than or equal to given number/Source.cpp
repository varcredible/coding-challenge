#include <iostream>

int findTheHighestPowerOfTwo(const int _N);

int main()
{
	std::cout << findTheHighestPowerOfTwo(10); // -> Output: 8

	return 0;
}

int findTheHighestPowerOfTwo(const int _N)
{
	int HighestPower = 0;

	for (size_t powResult = 1; powResult <= _N; powResult *= 2)
	{
		HighestPower = powResult;
	}

	return HighestPower;
}
