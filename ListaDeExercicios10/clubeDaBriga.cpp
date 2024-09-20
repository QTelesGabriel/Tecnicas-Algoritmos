#include <iostream>
#include <vector>

void qtdDeGangues(int u, std::vector<std::vector<int>>& gangues, std::vector<bool>& visitados) {
    if(!visitados[u]) {
        visitados[u] = true;
        for(auto c : gangues[u]) {
            qtdDeGangues(c, gangues, visitados);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int totalParticipantes, qtdPares;
    std::cin >> totalParticipantes >> qtdPares;

    std::vector<std::vector<int>> gangues(totalParticipantes + 1);

    int lutador1, lutador2;
    for(int i = 0; i < qtdPares; i++) {
        std::cin >> lutador1 >> lutador2;
        gangues[lutador1].push_back(lutador2);
        gangues[lutador2].push_back(lutador1);
    }

    std::vector<bool> visitados(totalParticipantes + 1, false);
    int quantidadeGangues = 0;

    for(int i = 1; i <= totalParticipantes; i++) {
        if(!visitados[i]) {
            qtdDeGangues(i, gangues, visitados);
            quantidadeGangues++;
        }
    }

    std::cout << quantidadeGangues << " gangue(s) no clube da briga\n";

    return 0;
}