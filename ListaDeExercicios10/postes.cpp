#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

typedef std::tuple<int, int, int> Aresta;
typedef std::pair<int, int> Par;

std::vector<Par> prim(int origem, const std::vector<std::vector<Par>>& grafo, int numPostes) {
    std::priority_queue<Aresta, std::vector<Aresta>, std::greater<Aresta>> filaPrioridade;
    std::vector<Par> mst;
    std::vector<bool> visitado(numPostes + 1, false);
    filaPrioridade.push({0, origem, origem});
    int custoTotal = 0;

    while (!filaPrioridade.empty()) {
        auto [peso, u, v] = filaPrioridade.top();
        filaPrioridade.pop();
        if (visitado[v]) continue;
        visitado[v] = true;
        if (u != v) mst.push_back({u, v});
        custoTotal += peso;
        for (auto [destino, pesoAresta] : grafo[v]) {
            if (!visitado[destino]) {
                filaPrioridade.push({pesoAresta, v, destino});
            }
        }
    }

    if ((int)mst.size() != numPostes - 1) return {};
    return mst;
}

int main() {
    int numCasos;
    std::cin >> numCasos;

    for(int i = 0; i < numCasos; i++) {
        int numPostes, numArestas;
        std::cin >> numPostes >> numArestas;

        std::vector<std::vector<Par>> grafo(numPostes + 1);
        for (int i = 0; i < numArestas; ++i) {
            int poste1, poste2, distancia;
            std::cin >> poste1 >> poste2 >> distancia;
            grafo[poste1].push_back({poste2, distancia});
            grafo[poste2].push_back({poste1, distancia});
        }

        std::vector<Par> mst = prim(1, grafo, numPostes);
        if (mst.empty()) {
            std::cout << "Não é possível conectar todos os postes\n";
        } else {
            int custoTotal = 0;
            for (const auto& [u, v] : mst) {
                for (const auto& [destino, pesoAresta] : grafo[u]) {
                    if (destino == v) {
                        custoTotal += pesoAresta;
                        break;
                    }
                }
            }
            std::cout << custoTotal << std::endl;
        }
    }

    return 0;
}