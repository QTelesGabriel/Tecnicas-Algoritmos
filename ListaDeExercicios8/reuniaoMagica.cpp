#include <iostream>
#include <string>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin.tie(NULL);
    
    int qtd;
    std::cin >> qtd;

    for(int i = 0; i < qtd; i++) {
        std::set<char, std::greater<int>> cartas;
        std::string baralho1, baralho2;
        std::cin >> baralho1 >> baralho2;
        
        for(auto carta : baralho1) {
            cartas.insert(carta);
        }

        std::set<char> cartasRepetidas;
        bool baralhoPronto = true;

        for(auto carta : baralho2) {
            if(cartas.find(carta) != cartas.end()) {
                cartasRepetidas.insert(carta);
                baralhoPronto = false;
                cartas.erase(carta);
            }
        }

        if(baralhoPronto) {
            std::cout << "Baralhos prontos para o duelo" << std::endl;
        }
        else {
            for(auto carta : cartasRepetidas) {
                std::cout << carta;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}