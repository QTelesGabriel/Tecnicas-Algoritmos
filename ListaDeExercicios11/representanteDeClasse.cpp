#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int& quantidade, int u, std::vector<std::vector<int>>& conexoes, std::vector<bool>& visitados) {
    if(!visitados[u]) {
        visitados[u] = true;
        for(auto v : conexoes[u]) {
            if(!visitados[v]) {
                quantidade++;
                dfs(quantidade, v, conexoes, visitados);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int qtdAlunos, qtdConexoes;
    std::cin >> qtdAlunos >> qtdConexoes;

    std::vector<std::vector<int>> conexoes(qtdAlunos + 1);

    int aluno1, aluno2;
    for(int i = 0; i < qtdConexoes; i++) {
        std::cin >> aluno1 >> aluno2;
        conexoes[aluno1].push_back(aluno2);
        conexoes[aluno2].push_back(aluno1);
    }

    std::vector<int> qtdAlunosPorGrupo;
    std::vector<bool> visitados(qtdAlunos + 1, false);

    for(int i = 1; i <= qtdAlunos; i++) {
        if(!visitados[i]) {
            int quantidade = 1;
            dfs(quantidade, i, conexoes, visitados);
            qtdAlunosPorGrupo.push_back(quantidade);
        }
    }

    auto maiorElemento = std::max_element(qtdAlunosPorGrupo.begin(), qtdAlunosPorGrupo.end());

    std::cout << "O grupo mais numeroso tem " << *maiorElemento << " aluno(s)\n";

    return 0;
}