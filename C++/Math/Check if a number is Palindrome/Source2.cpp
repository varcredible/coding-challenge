// A method using std::string`s // 

#include <iostream>
#include <string>

bool isPalindrome(const int _N) // _n == 76667
{
	std::string number = std::to_string(_N);
	std::string reverse_number = number;
	std::reverse(reverse_number.begin(), reverse_number.end());

	return (number == reverse_number) ? true : false; // 76667 == 76667 -> true
}

int main()
{
	isPalindrome(76667) ? printf("Yes") : printf("No"); // -> Output: Yes
	return 0;
}