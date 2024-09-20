#include <iostream>
#include <string>

int main()
{
    while(true) {
        unsigned long long int d;
        std::cin >> d;
        if(d == -1) {
            break;
        }

        std::string numero;
        std::cin >> numero;

        unsigned long long int soma = 0;
        for(char num : numero) {
            soma += (unsigned long long int)(num - 48);
        }

        if(soma % 3 == 0) {
            std::cout << soma << " sim" << std::endl;
        }
        else {
            std::cout << soma << " nao" << std::endl;
        }

    }

    return 0;
}