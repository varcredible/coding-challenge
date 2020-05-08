#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << (n / 100 - ((n % 10 * 10) + (n % 100 / 10))) + 1 << std::endl;
    return 0;
}
