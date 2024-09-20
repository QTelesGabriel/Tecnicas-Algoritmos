#include <iostream>

void collatz(unsigned long long int n) {
    if(n > 1) {
        std::cout << n << " ";
        if(n % 2 == 0) {
            collatz(n / 2);
        }
        else {
            collatz(3 * n + 1);
        }
    }
}

int main()
{
    unsigned long long int n;
    std::cin >> n;
    collatz(n);
    std::cout << 1 << std::endl;
    return 0;
}