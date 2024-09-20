#include <iostream>
#include <string>
#include <map>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int arquivos;
    std::cin >> arquivos;

    for(int i = 0; i < arquivos; i++) {
        int linhas;
        std::cin >> linhas;

        std::map<int, std::set<std::string>> alunos;
        
        bool corrompido = false;
        int erros = 0;
        int matricula;
        std::string materia;

        for(int i = 0; i < linhas; i++) {
            std::cin >> matricula >> materia;
            auto it = alunos[matricula].find(materia);
            if(it == alunos[matricula].end()) {
                alunos[matricula].insert(materia);
            }
            else {
                corrompido = true;
                erros++;
            }
        }

        if(corrompido) std::cout << "Corrompido com " << erros << " erro(s)" << std::endl;
        else std::cout << "Arquivo OK" << std::endl;
    }

    return 0;
}