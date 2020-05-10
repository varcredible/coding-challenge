#include <iostream>
#include <string>
using namespace std;

int replaceAllZeros(const int _N);
string findAndChangeZeros(string& _number);

int main()
{
	cout << replaceAllZeros(102); // -> Output: 152
	return 0;
}

int replaceAllZeros(const int _N)
{
	string number = to_string(_N);

	findAndChangeZeros(number);

	int result = stoi(number);
	return result;
}

string findAndChangeZeros(string& _number)
{
	for (size_t indexDigit = 0; indexDigit < _number.length(); indexDigit++)
	{
		(_number[indexDigit] == '0') ? _number[indexDigit] = '5' : _number[indexDigit] = _number[indexDigit];
	}

	return _number;
}
