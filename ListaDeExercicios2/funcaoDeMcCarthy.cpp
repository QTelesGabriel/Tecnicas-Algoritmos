#include <iostream>

unsigned long long int mcCarthy(unsigned long long  int n) {
    if(n > 100) {
        return n - 10;
    }
    else {
        return mcCarthy(mcCarthy(n + 11));
    }
}

int main()
{
    long int c;
    std::cin >> c;

    for(long int i = 0; i < c; i++) {
        unsigned long long int n;
        std::cin >> n;
        std::cout << mcCarthy(n) << std::endl;
    }
}