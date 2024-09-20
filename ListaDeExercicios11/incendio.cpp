#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int INF = 0x3f3f3f3f;
std::vector<std::pair<int, int>> grafo[801];
int distancias[801];

void dijkstra(int origem) {
    std::memset(distancias, INF, sizeof(distancias));
    distancias[origem] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> filaPrioridade;
    filaPrioridade.push({0, origem});
    
    while (!filaPrioridade.empty()) {
        auto [distanciaAtual, pontoAtual] = filaPrioridade.top(); filaPrioridade.pop();
        if (distanciaAtual > distancias[pontoAtual]) {
            continue;
        }
        for (auto [pontoVizinho, peso]: grafo[pontoAtual]) {
            if (distancias[pontoVizinho] > distancias[pontoAtual] + peso) {
                distancias[pontoVizinho] = distancias[pontoAtual] + peso;
                filaPrioridade.push({distancias[pontoVizinho], pontoVizinho});
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int numPontos, numCorredores;
    std::cin >> numPontos >> numCorredores;

    for (int i = 0; i < numCorredores; i++) {
        int pontoA, pontoB;
        std::cin >> pontoA >> pontoB;
        grafo[pontoA].emplace_back(pontoB, 1);
        grafo[pontoB].emplace_back(pontoA, 1);
    }

    int posAgente, posExtintor, posFoco;
    std::cin >> posAgente >> posExtintor >> posFoco;

    dijkstra(posAgente);
    int distAgenteParaExtintor = distancias[posExtintor];

    dijkstra(posExtintor);
    int distExtintorParaFoco = distancias[posFoco];

    int resultado = distAgenteParaExtintor + distExtintorParaFoco;

    std::cout << resultado << std::endl;

    return 0;
}
