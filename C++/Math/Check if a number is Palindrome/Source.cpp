/* 

This code only works with four-digit numbers. 
If you're interested in solving any-digit numbers then check the other versions out in the current repository.

*/

#include <iostream>
using namespace std;

int main() 
{
    int n = 2002;
    (((n / 100 - ((n % 10 * 10) + (n % 100 / 10))) + 1) == 1) ? cout << "YES" : cout << "NO"; // -> Output: YES
    
    return 0;
}
