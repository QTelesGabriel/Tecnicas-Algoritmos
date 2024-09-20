#include <iostream>
#include <cstdint>

int main()
{
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        uint64_t n;
        int p, q, pValor, qValor;

        std::cin >> n >> p >> q;

        // Descobrir o valor dos bits
        pValor = (n & ((uint64_t)1 << p)) >> p;
        qValor = (n & ((uint64_t)1 << q)) >> q;

        // Desativar o bits salvos
        n &= ~((uint64_t)1 << p);
        n &= ~((uint64_t)1 << q);

        // Trocar o valor dos bits
        n |= (uint64_t)pValor << q;
        n |= (uint64_t)qValor << p;

        std::cout << n << std::endl;  
        
    }

    return 0;
}