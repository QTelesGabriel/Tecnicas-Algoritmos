#include <iostream>
#include <vector>
#include <queue>

const int oo = 0x3f3f3f3f;

bool caminhoMinimo(int u, int destino, std::vector<std::vector<int>>& caminhos, std::vector<int>& dist) {
    std::queue<int> fila;
    fila.push(u);
    dist[u] = 0;
    while(!fila.empty()) {
        u = fila.front();
        fila.pop();
        for(auto v : caminhos[u]) {
            if(dist[v] == oo) {
                fila.push(v);
                dist[v] = dist[u] + 1;
                if(v == destino) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int ilhas, pontes;
    std::cin >> ilhas >> pontes;

    const int ORIGEM = 1;
    const int DESTINO = ilhas;

    std::vector<std::vector<int>> caminhos(ilhas + 1);
    std::vector<int> dist(ilhas + 1, oo);

    int ilha1, ilha2;
    for(int i = 0; i < pontes; i++) {
        std::cin >> ilha1 >> ilha2;
        caminhos[ilha1].push_back(ilha2);
        caminhos[ilha2].push_back(ilha1);
    }

    if(caminhoMinimo(ORIGEM, DESTINO, caminhos, dist)) {
        std::cout << dist[DESTINO] << "\n";
    } else {
        std::cout << "-1\n";
    }

    return 0;
}