#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    unsigned long long int k;
    std::cin >> n >> k;

    std::vector<unsigned long long int> numeros(n);
    for(int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    for(int i = 0; i < n - 2; i++) {
        std::unordered_map<unsigned long long int, int> visto;
        for(int j = i + 1; j < n; j++) {
            unsigned long long int complemento = k - numeros[i] - numeros[j];
            if(visto.find(complemento) != visto.end()) {
                std::cout << numeros[i] << " " << numeros[j] << " " << complemento << std::endl;
                return 0;
            }
            visto[numeros[j]] = j;
        }
    }

    std::cout << "Nao existe" << std::endl;
    return 0;
}
