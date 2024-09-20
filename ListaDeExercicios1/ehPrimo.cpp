#include <iostream>
#include <cmath>

bool ehPrimo(int v) {
    if(v == 1) {
        return false;
    }

    if(v <= 3) {
        return true;
    }

    if(v % 2 == 0 || v % 3 == 0) {
        return false;
    }

    for(int i = 5; i <= sqrt(v); i += 2) {
        if(v % i == 0) {
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
        int v;
        std::cin >> v;

        if(ehPrimo(v)) {
            std::cout << "o numero " << v << " eh primo" << std::endl;
        }
        else {
            std::cout << "o numero " << v << " nao eh primo" << std::endl;
        }
    }

    return 0;
}