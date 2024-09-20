#include <iostream>
#include <cmath>

bool ehPrimo(long long int v) {
    if(v <= 1) {
        return false;
    }
    if(v <= 3) {
        return true;
    }
    if(v % 2 == 0 || v % 3 == 0) {
        return false;
    }
    for(int i = 5; i <= sqrt(v); i++) {
        if(v % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    long int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        long long int v;
        std::cin >> v;
        if((ehPrimo(v) && ehPrimo(v + 2)) || (ehPrimo(v) && ehPrimo(v - 2))) {
            std::cout << "O numero " << v << " eh um primo gemeo" << std::endl;
        }
        else {
            std::cout << "O numero " << v << " nao eh um primo gemeo" << std::endl;
        }
    }
}