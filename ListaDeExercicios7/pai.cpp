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
            int indicePai = (consulta - 1) / 2;
            if(consulta == 0) std::cout << "RAIZ" << std::endl;
            else std::cout << arvore[indicePai] << std::endl;
        }
    }

    return 0;
}