#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
      
struct Jogador {
    std::string nome;
    std::string tempo;
};

int main()
{
    unsigned long long int j;
    std::cin >> j;
    std::cin.get();

    std::vector<Jogador> jogadores;

    for(unsigned long long int i = 0; i < j; i++) {
        Jogador jogador;
        std::cin >> jogador.nome >> jogador.tempo;
        jogadores.push_back(jogador);
    }

    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& jogador1, const Jogador& jogador2) {
        if(jogador1.tempo != jogador2.tempo) {
            return jogador1.tempo > jogador2.tempo;
        }
        return jogador1.nome > jogador2.nome;
    });

    unsigned long long int k = 1;
    for(auto& jogador : jogadores) {
        std::cout << k << ". " << jogador.tempo << " - " << jogador.nome << std::endl;
        k++;
    }

    return 0;
}