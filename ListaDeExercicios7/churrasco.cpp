#include <iostream>
#include <string>

struct No {
    No *esq;
    No *dir;
    std::string comida;

    No(std::string comida) : esq(nullptr), dir(nullptr), comida(comida) {}
};

void inserir(No *&raiz, std::string comida) {
    if(raiz == nullptr) {
        raiz = new No(comida);
        std::cout << "adicionando " << comida << std::endl;
    }
    else if(comida < raiz->comida) {
        inserir(raiz->esq, comida);
    }

    else if(comida > raiz->comida){
        inserir(raiz->dir, comida);
    }
    else {
        std::cout << comida << " ja tem" << std::endl;
    }
}

void listarTudo(No *&raiz) {
    if(raiz != nullptr) {
        listarTudo(raiz->esq);
        std::cout << raiz->comida << std::endl;
        listarTudo(raiz->dir);
    }
}

int main()
{
    No *raiz = nullptr;

    int alunos;
    std::cin >> alunos;

    for(int i = 0; i < alunos; i++) {
        int qtd;
        std::cin >> qtd;

        for(int j = 0; j < qtd; j++) {
            std::string comida;
            std::cin >> comida;
            inserir(raiz, comida);
        }
    }

    std::cout << "Itens do churrasco:" << std::endl;
    listarTudo(raiz);

    return 0;
}