// My goal was to make the solution without modern libries, std:: or STL //

#include <iostream>

bool isPalindrome(const int _N);
int getCountOfDigit(const int __N);
int* fillTheArrayNUMBER(int __n, int* number, const int _COUNTOFDIGITS);
int* fillTheArrayREVERSENUMBER(const int* _NUMBER, int* _reverseNumber, const int _COUNTOFDIGITS);
bool IsThePalindromeNumber(const int* _NUMBER, const int* _REVERSENUMBER, const int _COUNTOFDIGITS);

int main()
{
	isPalindrome(76667) ? printf("Yes") : printf("No"); // -> Output: Yes
	return 0;
}

bool isPalindrome(const int _N)
{
	int countOfDigits = getCountOfDigit(_N);
	int* number = new int[countOfDigits];
	int* reverseNumber = new int[countOfDigits];


	fillTheArrayNUMBER(_N, number, countOfDigits);
	fillTheArrayREVERSENUMBER(number, reverseNumber, countOfDigits);


	bool result = IsThePalindromeNumber(number, reverseNumber, countOfDigits);

	delete[] reverseNumber;
	delete[] number;

	return result;
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

int* fillTheArrayNUMBER(int __n, int* number, const int _COUNTOFDIGITS)
{
	for (size_t digitIndex = _COUNTOFDIGITS - 1, degree = 10; digitIndex < _COUNTOFDIGITS; digitIndex--, degree *= 10)
	{
		double reminder = __n % (1 * degree);
		number[digitIndex] = reminder / (degree / 10);
		__n = (__n / degree) * degree;
	}

	return number;
}

int* fillTheArrayREVERSENUMBER(const int* _NUMBER, int* _reverseNumber, const int _COUNTOFDIGITS)
{
	for (size_t digitIndex = 0; digitIndex < _COUNTOFDIGITS; digitIndex++)
	{
		_reverseNumber[digitIndex] = _NUMBER[_COUNTOFDIGITS - 1 - digitIndex];
	}

	return _reverseNumber;
}

bool IsThePalindromeNumber(const int* _NUMBER, const int* _REVERSENUMBER, const int _COUNTOFDIGITS)
{
	for (size_t digitIndex = 0, matches = 0; digitIndex < _COUNTOFDIGITS; digitIndex++)
	{
		if (_NUMBER[digitIndex] == _REVERSENUMBER[digitIndex])
		{
			matches++;
		}

		if (digitIndex == _COUNTOFDIGITS - 1)
		{
			return (matches == _COUNTOFDIGITS) ? true : false;
		}
	}
}