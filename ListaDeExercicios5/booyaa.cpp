#include <iostream>
#include <queue>
#include <cmath>

int main()
{
    long long int f, d, inscritos;
    std::cin >> f >> d;

    std::queue<long long int> inscricoes;
    long long int somaInscritos = 0;

    for (int i = 0; i < 30; i++) {
        std::cin >> inscritos;
        inscricoes.push(inscritos);
        somaInscritos += inscritos;
    }

    for (long long int i = 0; i < d; i++) {
        long long int media = std::ceil(somaInscritos / 30.0);
        f += media;
        somaInscritos = somaInscritos + media - inscricoes.front();
        inscricoes.push(media);
        inscricoes.pop();
    }

    std::cout << f << std::endl;

    return 0;
}
