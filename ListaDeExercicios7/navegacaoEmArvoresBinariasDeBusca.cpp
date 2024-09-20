#include <iostream>

struct No {
    No *esq;
    No *dir;
    long long int valor;

    No(long long int valor) : valor(valor), esq(nullptr), dir(nullptr) {}
};

void inserir(No *&raiz, long long int valor) {
    if(raiz == nullptr) {
        raiz = new No(valor);
    }
    else if(valor < raiz->valor) {
        inserir(raiz->esq, valor);
    }
    else {
        inserir(raiz->dir, valor);
    }
}

void printIn(No *&raiz) {
    if(raiz != nullptr) {
        printIn(raiz->esq);
        std::cout << raiz->valor << " ";
        printIn(raiz->dir);
    }
}

void printPre(No *&raiz) {
    if(raiz != nullptr) {
        std::cout << raiz->valor << " ";
        printPre(raiz->esq);
        printPre(raiz->dir);
    }
}

void printPos(No *&raiz) {
    if(raiz != nullptr) {
        printPos(raiz->esq);
        printPos(raiz->dir);
        std::cout << raiz->valor << " ";
    }
}

int main()
{
    No *raiz = nullptr;
    int n; 
    std::cin >> n;
    
    long long int valor;
    for(int i = 0; i < n; i++) {
        std::cin >> valor;
        inserir(raiz, valor);
    }

    std::cout << "In.: ";
    printIn(raiz);
    std::cout << std::endl;

    std::cout << "Pre: ";
    printPre(raiz);
    std::cout << std::endl;

    std::cout << "Pos: ";
    printPos(raiz);
    std::cout << std::endl;

    return 0;
}