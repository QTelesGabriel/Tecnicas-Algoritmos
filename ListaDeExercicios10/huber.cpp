#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int INFINITO = 0x3f3f3f3f;
const int MAX_VERTICES = 810;

void dijkstra(std::vector<std::pair<int, int>> adj[], int origem, int destino) {
    int distancia[MAX_VERTICES];
    std::memset(distancia, INFINITO, sizeof(distancia));
    distancia[origem] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> filaPrioridade;
    filaPrioridade.push({0, origem});

    while (!filaPrioridade.empty()) {
        auto [dist, u] = filaPrioridade.top();
        filaPrioridade.pop();

        if (dist > distancia[u]) continue;

        for (auto [v, peso] : adj[u]) {
            if (distancia[v] > distancia[u] + peso) {
                distancia[v] = distancia[u] + peso;
                filaPrioridade.push({distancia[v], v});
            }
        }
    }

    if (distancia[destino] >= INFINITO) {
        std::cout << "Preso no IDP" << std::endl;
    } else {
        std::cout << "Distancia para chegar em casa: " << distancia[destino] << std::endl;
    }
}

int main() {
    int numeroLocais, numeroArestas;
    std::cin >> numeroLocais >> numeroArestas;

    std::vector<std::pair<int, int>> adj[MAX_VERTICES];

    for (int i = 0; i < numeroArestas; ++i) {
        int origem, destino, peso;
        std::cin >> origem >> destino >> peso;
        adj[origem].emplace_back(destino, peso);
        adj[destino].emplace_back(origem, peso);
    }

    dijkstra(adj, 1, numeroLocais);

    return 0;
}
