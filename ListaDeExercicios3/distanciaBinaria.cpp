#include <iostream>
#include <cstdint>

int main() 
{
    int n; 
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        uint64_t a, b;
        std::cin >> a >> b;
        a ^= b;

        unsigned long long int contador = 0;

        while (a) {
            contador += a & 1;
            a >>= 1;
        }

        std::cout << contador << std::endl;
    }

    return 0;
}