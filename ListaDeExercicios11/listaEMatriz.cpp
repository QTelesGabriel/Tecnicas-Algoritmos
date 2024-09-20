#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int vertices;
    std::cin >> vertices;

    int grafo[vertices + 1][vertices + 1];
    for(int i = 1; i <= vertices; i++) {
        for(int j = 1; j <= vertices; j++) {
            grafo[i][j] = 0;
        }
    }

    int qtdVAdjacentes;
    for(int i = 1; i <= vertices; i++) {
        std::cin >> qtdVAdjacentes;
        int vAdjacente;
        for(int j = 1; j <= qtdVAdjacentes; j++) {
            std::cin >> vAdjacente;
            grafo[i][vAdjacente] = 1;
        }
    }

    for(int i = 1; i <= vertices; i++) {
        for(int j = 1; j <= vertices; j++) {
            std::cout << grafo[i][j] << (j == vertices ? "" : " ");
        }
        std::cout << "\n";
    }


    return 0;
}