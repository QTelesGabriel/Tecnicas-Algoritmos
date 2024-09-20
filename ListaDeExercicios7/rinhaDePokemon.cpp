#include <iostream>
#include <string>
#include <queue>

struct Pokemon {
    std::string nome;
    int forca;

    bool operator<(const Pokemon& outro) const {
        if(forca == outro.forca) {
            return nome < outro.nome;
        }
        return forca < outro.forca;
    }
};

int main()
{
    int quantidade;
    std::cin >> quantidade;

    std::priority_queue<Pokemon> pokemons;

    for(int i = 0; i < quantidade; i++) {
        Pokemon p;
        std::cin >> p.nome >> p.forca;
        pokemons.push(p);
    }

    while(pokemons.size() > 1) {
        Pokemon p1 = pokemons.top();
        pokemons.pop();
        Pokemon p2 = pokemons.top();
        pokemons.pop();

        std::cout << p1.nome << " (" << p1.forca << ") x (" << p2.forca << ") " << p2.nome << " : ";

        if(p1.forca > p2.forca) {
            p1.forca -= p2.forca;
            pokemons.push(p1);
            std::cout << p1.nome << " venceu" << std::endl;
        }
        else if(p1.forca < p2.forca) {
            p2.forca -= p2.forca;
            pokemons.push(p2);
            std::cout << p2.nome << " venceu" << std::endl;
        }
        else {
            std::cout << "empate" << std::endl;
        }
    }

    if(pokemons.empty()) {
        std::cout << "nenhum vencedor" << std::endl;
    }
    else {
        std::cout << pokemons.top().nome << " venceu com " << pokemons.top().forca << std::endl;
    }
}