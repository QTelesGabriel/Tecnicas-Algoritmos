#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int n;

    while(std::cin >> n && n != -1) {
        
        if(n % 2 == 0) {
            continue;
        }

        unsigned long long int resultado = 0;
        unsigned long long int numero;

        for (int i = 0; i < n; i++) {
            std::cin >> numero;
            resultado ^= numero;
        }

        std::cout << resultado << std::endl;
    }

    return 0;
}