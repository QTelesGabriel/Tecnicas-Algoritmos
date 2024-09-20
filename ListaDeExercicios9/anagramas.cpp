#include <iostream>
#include <string>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        std::string primeiro, segundo;
        std::cin >> primeiro >> segundo;

        std::map<char, int> primeiroMap, segundoMap;

        for(auto &p : primeiro) {
            primeiroMap[p]++;
        }
        for(auto &s : segundo) {
            segundoMap[s]++;
        }

        if(primeiroMap == segundoMap) {
            std::cout << "ANAGRAMAS" << std::endl;
        }
        else {
            std::cout << "DIFERENTES" << std::endl;
        }
    }

    return 0;
}