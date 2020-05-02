#include <iostream>

int findHighestPowerOfTwo(const int _N)
{
	int HighestPower = 0;
	
	for (size_t powResult = 1; powResult <= _N; powResult *= 2)
	{
		HighestPower = powResult;
	}
	
	return HighestPower;
}

int main()
{
	findHighestPowerOfTwo(10); // -> Output: 8
	return 0;
}