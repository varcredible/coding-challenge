// My goal was to make the solution without modern libries or STL //

#include <iostream>

bool isThePalindromeNumber(const int* _NUMBER, const int* _REVERSENUMBER, const int _COUNT_OF_DIGITS)
{
	for (size_t digitIndex = 0, matches = 0; digitIndex < _COUNT_OF_DIGITS; digitIndex++)
	{
		if (_NUMBER[digitIndex] == _REVERSENUMBER[digitIndex])
		{
			matches++;
		}

		if (digitIndex == _COUNT_OF_DIGITS - 1)
		{
			return (matches == _COUNT_OF_DIGITS) ? true : false;
		}
	}
}

int getCountOfDigit(const int __N)
{
	int countOfDigits = 0;

	for (size_t i = __N; i; )
	{
		i /= 10;
		countOfDigits++;
	}

	return countOfDigits;
}

int* fillTheArrayREVERSENUMBER(const int* _NUMBER, int* _reverseNumber, const int _COUNT_OF_DIGITS)
{
	for (size_t digitIndex = 0; digitIndex < _COUNT_OF_DIGITS; digitIndex++)
	{
		_reverseNumber[digitIndex] = _NUMBER[_COUNT_OF_DIGITS - 1 - digitIndex];
	}

	return _reverseNumber;
}

int* fillTheArrayNUMBER(int __n, int* number, const int _COUNT_OF_DIGITS)
{
	for (size_t digitIndex = _COUNT_OF_DIGITS - 1, degree = 10; digitIndex < _COUNT_OF_DIGITS; digitIndex--, degree *= 10)
	{
		double reminder = __n % (1 * degree);
		number[digitIndex] = reminder / (degree / 10);
		__n = (__n / degree) * degree;
	}

	return number;
}

bool isPalindrome(const int _N)
{
	int countOfDigits = getCountOfDigit(_N);
	int* number = new int[countOfDigits];
	int* reverseNumber = new int[countOfDigits];


	fillTheArrayNUMBER(_N, number, countOfDigits);
	fillTheArrayREVERSENUMBER(number, reverseNumber, countOfDigits);


	bool result = isThePalindromeNumber(number, reverseNumber, countOfDigits);

	delete[] reverseNumber;
	delete[] number;

	return result;
}

int main()
{
	isPalindrome(76667) ? printf("Yes") : printf("No"); // -> Output: Yes

	return 0;
}
