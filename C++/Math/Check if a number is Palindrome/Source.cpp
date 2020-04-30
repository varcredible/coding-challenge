/* 

The solution was created without Google and etc.
Only me and my head. 

P.S. My goal was to make the solution without modern libries or STL.

*/

#include <iostream>

bool isPalindrome(int _n)
{
	int countOfDigits = 0;	
	for (size_t i = _n; i ; )
	{
		i /= 10;
		countOfDigits++;
	}

	int* number = new int[countOfDigits];
	int* reverseNumber = new int[countOfDigits];
	
	// Fill the number int* array
	for (size_t digitIndex = countOfDigits - 1, degree = 10; digitIndex < countOfDigits; digitIndex--, degree *= 10)
	{
		double reminder = _n % (1 * degree); 
		number[digitIndex] = reminder / (degree / 10);
		_n = (_n / degree) * degree;
	}

	// Fill the reverseNumber int* array
	for (size_t digitIndex = 0; digitIndex < countOfDigits; digitIndex++)
	{
		reverseNumber[digitIndex] = number[countOfDigits - 1 - digitIndex];
	}

	// Check if a number is Palindrome
	for (size_t digitIndex = 0, matches = 0; digitIndex < countOfDigits;  digitIndex++)
	{		
		if (number[digitIndex] == reverseNumber[digitIndex])
		{
			matches++;
		}

		if (digitIndex == countOfDigits - 1)
		{
			if (matches == countOfDigits)
			{
				delete[] reverseNumber;
				delete[] number;
				return true;
			}

			else
			{
				delete[] reverseNumber;
				delete[] number;
				return false;
			}
		}
	}
}

int main()
{
	isPalindrome(76667) ? printf("Yes") : printf("No"); // -> Output: Yes
	return 0;
}