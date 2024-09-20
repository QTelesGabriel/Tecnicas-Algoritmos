#include <iostream>
#include <cstdint>
#include <cmath>

bool ehPrimo(int num) {
    if(num == 1) {
        return false;
    }

    if(num <= 3) {
        return true;
    }

    if(num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    for(int i = 5; i <= sqrt(num); i += 2) {
        if(num % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        uint64_t v, vCopia, numeroDeBitsUm = 0;
        std::cin >> v;

        vCopia = v;

        while(v) {
            numeroDeBitsUm += v & 1;
            v >>= 1;
        }

        if(ehPrimo(numeroDeBitsUm)) {
            std::cout << vCopia << " eh um pribit" << std::endl;
        }
        else {
            std::cout << vCopia << " nao eh um pribit" << std::endl;
        }

    }
}