// A method using strings // 

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const int _N);

int main() {
	isPalindrome(76667) ? printf("Yes") : printf("No"); // -> Output: Yes
	return 0;
}

bool isPalindrome(const int _N) {
	string number = to_string(_N);
	string reverse_number = number;
	reverse(reverse_number.begin(), reverse_number.end());

	return (number == reverse_number) ? true : false;
}
