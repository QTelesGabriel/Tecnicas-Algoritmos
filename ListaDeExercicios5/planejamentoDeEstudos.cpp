#include <iostream>
#include <vector>

bool consegueEstudarTudo(std::vector<unsigned long long int> questoes, unsigned long long int meio, unsigned long long int h)
{
    unsigned long long int quantidadeDeQuestoesPorVez = 0;
    for(auto q : questoes) {
        if(q % meio == 0) {
            quantidadeDeQuestoesPorVez += q / meio;
        }
        else {
            quantidadeDeQuestoesPorVez += q / meio + 1;
        }
    }

    return quantidadeDeQuestoesPorVez <= h;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    unsigned long long int n, h;
    std::cin >> n >> h;

    std::vector<unsigned long long int> questoes;
    unsigned long long int questao, maior = 0, menor = 1;

    for(unsigned int i = 0; i < n; i++) {
        std::cin >> questao;
        questoes.push_back(questao);
        if(questao > maior) maior = questao;
    }

    unsigned long long int meio;

    while(menor < maior) {
        meio = menor + (maior - menor) / 2;
        if(consegueEstudarTudo(questoes, meio, h)) {
            maior = meio;
        }
        else {
            menor = meio + 1;
        }
    }

    std::cout << menor << std::endl;

    return 0;
}