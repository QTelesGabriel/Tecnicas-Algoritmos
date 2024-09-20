#include <iostream>
#include <string>

struct Materias {
    Materias *esq;
    Materias *dir;
    std::string materia;

    Materias(std::string materia) : esq(nullptr), dir(nullptr), materia(materia) {}
};

struct No {
    No *esq;
    No *dir;
    int matricula;
    Materias *materia;

    No(int matricula) : esq(nullptr), dir(nullptr), matricula(matricula), materia(nullptr) {}
};

void inserirMateria(Materias *&materia, std::string mat, bool &corrompido, int &erros) {
    if(materia == nullptr) {
        materia = new Materias(mat);
    }
    else if(materia->materia == mat) {
        corrompido = true;
        erros++;
    }
    else if(materia->materia > mat) {
        inserirMateria(materia->esq, mat, corrompido, erros);
    }
    else if(materia->materia < mat) {
        inserirMateria(materia->dir, mat, corrompido, erros);
    }
}

void inserirMatricula(No *&raiz, int &matricula, std::string &materia, bool &corrompido, int &erros) {
    if(raiz == nullptr) {
        raiz = new No(matricula);
        inserirMateria(raiz->materia, materia, corrompido, erros);
    }
    else if(raiz->matricula == matricula) {
        inserirMateria(raiz->materia, materia, corrompido, erros);
    }
    else if(matricula < raiz->matricula) {
        inserirMatricula(raiz->esq, matricula, materia, corrompido, erros);
    }
    else if(matricula > raiz->matricula) {
        inserirMatricula(raiz->dir, matricula, materia, corrompido, erros);
    }
}

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
        
        bool corrompido = false;
        int erros = 0;

        No *raiz = nullptr;
        int matricula;
        std::string materia;
        for(int i = 0; i < linhas; i++) {
            std::cin >> matricula;
            std::cin >> materia;
            inserirMatricula(raiz, matricula, materia, corrompido, erros);
        }

        if(corrompido) std::cout << "Corrompido com " << erros << " erro(s)" << std::endl;
        else std::cout << "Arquivo OK" << std::endl;
    }

    return 0;
}