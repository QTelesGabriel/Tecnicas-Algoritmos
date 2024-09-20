#include <iostream>
#include <vector>

int main()
{
    int n, c;
    std::cin >> n >> c;

    std::vector<long long int> arvore(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arvore[i];
    }

    for(int i = 0; i < c; i++) {
        int consulta;
        std::cin >> consulta;
        consulta--;

        if(n == 1 && arvore[0] == -1) {
            std::cout << "NULL" << std::endl;
        }
        else {
            int indiceFilhoEsq = 2 * consulta + 1;
            int indiceFilhoDir = 2 * consulta + 2;
            
            if(indiceFilhoEsq < n) {
                std::cout << (arvore[indiceFilhoEsq] != -1 ? std::to_string(arvore[indiceFilhoEsq]) : "NULL") << " ";
            }
            else {
                std::cout << "NULL ";
            }

            if(indiceFilhoDir < n) {
                std::cout << (arvore[indiceFilhoDir] != -1 ? std::to_string(arvore[indiceFilhoDir]) : "NULL");
            }
            else {
                std::cout << "NULL ";
            }

            std::cout << std::endl;
        }
    }

    return 0;
}