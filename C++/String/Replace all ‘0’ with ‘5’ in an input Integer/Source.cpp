#include <iostream>
#include <string>

int replaceAllZeros(const int _N);
std::string findAndChangeZeros(std::string& _number);

int main()
{
	std::cout << replaceAllZeros(102); // -> Output: 152
	return 0;
}

int replaceAllZeros(const int _N)
{
	std::string number = std::to_string(_N);

	findAndChangeZeros(number);

	int result = stoi(number);
	return result;
}

std::string findAndChangeZeros(std::string& _number)
{
	for (size_t indexDigit = 0; indexDigit < _number.length(); indexDigit++)
	{
		(_number[indexDigit] == '0') ? _number[indexDigit] = '5' : _number[indexDigit] = _number[indexDigit];
	}

	return _number;
}
