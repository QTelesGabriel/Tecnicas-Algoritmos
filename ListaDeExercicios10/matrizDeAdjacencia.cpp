#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int vertices, conexoes;
    std::cin >> vertices >> conexoes;

    int matriz[vertices + 1][vertices + 1];
    for(int i = 1; i <= vertices; i++) {
        for(int j = 1; j <= vertices; j++) {
            matriz[i][j] = 0;
        }
    }

    int a, b;
    for(int i = 0; i < conexoes; i++) {
        std::cin >> a >> b;
        matriz[a][b] = 1;
        matriz[b][a] = 1;
    }

    for(int i = 1; i <= vertices; i++) {
        for(int j = 1; j <= vertices; j++) {
            std::cout << matriz[i][j] << (j == vertices ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}