#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    unsigned long long int n, k;
    std::cin >> n >> k;

    std::vector<unsigned long long int> numeros(n);
    std::unordered_set<unsigned long long int> complementos;

    for(unsigned long long int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    for(unsigned long long int i = 0; i < n; i++) {
        unsigned long long int complemento = k - numeros[i];
        if(complementos.find(complemento) != complementos.end()) {
            std::cout << numeros[i] << " " << complemento << std::endl;
            return 0;
        }
        complementos.insert(numeros[i]);
    }

    std::cout << "Nao existe" << std::endl;
    return 0;
}