#include <iostream>
#include <set>

int main()
{
    int qtd, rankSorteado;
    std::cin >> qtd >> rankSorteado;

    std::set<int> cadeiras;
    int cadeiraEscolhida;
    for(int i = 0; i < qtd; i++) {
        std::cin >> cadeiraEscolhida;
        cadeiras.insert(cadeiraEscolhida);
        if((int)cadeiras.size() < rankSorteado) {
            auto it = cadeiras.end();
            it--;
            std::cout << *it << std::endl;
        }
        else {
            auto it = cadeiras.begin();
            for(int i = 1; i < rankSorteado; i++) {
                it++;
            }
            std::cout << *it << std::endl;
        }
    }

    return 0;
}