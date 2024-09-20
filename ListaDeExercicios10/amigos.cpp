#include <iostream>
#include <vector>

void dfs(int u, std::vector<bool>& visitado, std::vector<std::vector<int>>& amigos) {
    visitado[u] = true;
    for(auto v : amigos[u]) {
        if(!visitado[v]) {
            dfs(v, visitado, amigos);
        }
    }
}

int main() {
    int alunos, amizades;
    std::cin >> alunos >> amizades;

    std::vector<std::vector<int>> amigos(alunos + 1);

    int a, b;
    for(int i = 0; i < amizades; i++) {
        std::cin >> a >> b;
        amigos[a].push_back(b);
        amigos[b].push_back(a);
    }

    std::vector<bool> visitado(alunos + 1, false);
    visitado[0] = true;
    dfs(1, visitado, amigos);

    for(auto v : visitado) {
        if(!v) {
            std::cout << "Varios grupos de amigos\n";
            return 0;
        }
    }

    std::cout << "Todo mundo eh amigo de todo mundo\n";
    
    return 0;
}