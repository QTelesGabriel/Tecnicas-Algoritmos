#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> lista(n-1);
    
    for(int i = 0; i < n-1; i++) {
        std::cin >> lista[i];
    }

    std::sort(lista.begin(), lista.end());

    int j = 0;
    for(int i = 0; i < n-1; i++) {
        if(lista[i] - j != 1) {
            std::cout << j+1 << std::endl;
            exit(0);
        }
        j++;
    }

    std::cout << j+1 << std::endl;

    return 0;
}