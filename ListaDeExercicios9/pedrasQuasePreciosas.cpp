#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    
    std::string catalogo;
    std::string pedras;

    long long int total;

    for(int i = 0; i < t; i++) {
        std::unordered_map<char, long long int> qtdPedras;
        std::set<char> catalogoSemRepeticao;
        total = 0;
        std::cin >> catalogo >> pedras;

        for(auto &p : pedras) {
            qtdPedras[p] = 0;
        }

        for(auto &p : pedras) {
            qtdPedras[p] += 1;
        }

        for(auto &c : catalogo) {
            catalogoSemRepeticao.insert(c);
        }

        for(auto &c : catalogoSemRepeticao) {
            total += qtdPedras[c];
        }

        std::cout << "Contem " << total << " pedras negociaveis" << std::endl;

    }

    return 0;
}