#include <iostream>
#include <vector>

bool somaIgual(std::vector<long int> lista, int s) {
    long int comeco = 0;
    long int fim = lista.size() - 1;

    while(comeco < fim) {
        long int soma = lista[comeco] + lista[fim];
        if(soma == s) {
            return true;
        }
        if(soma < s) {
            comeco++;
        }
        else {
            fim--;
        }
    }

    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<long int> lista(n);

        for(int j = 0; j < n; j++) {
            std::cin >> lista[j];
        }

        int s;
        std::cin >> s;

        if(somaIgual(lista, s)) {
            std::cout << "SIM" << std::endl;
        }
        else {
            std::cout << "NAO" << std::endl;
        }
    }

    return 0;
}