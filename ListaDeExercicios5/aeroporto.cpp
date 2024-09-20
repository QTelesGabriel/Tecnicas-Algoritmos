#include <iostream>
#include <queue>
#include <vector>
#include <string>

int main()
{
    std::string voo;
    std::vector<std::string> filaDeAvioes;
    
    do {
        std::cin >> voo;
        filaDeAvioes.push_back(voo);
    } while(voo != "0");

    filaDeAvioes.pop_back();

    std::vector<std::queue<std::string>> filasNSLO;
    std::queue<std::string> filaN;
    std::queue<std::string> filaS;
    std::queue<std::string> filaL;
    std::queue<std::string> filaO;

    filasNSLO.push_back(filaN);
    filasNSLO.push_back(filaS);
    filasNSLO.push_back(filaL);
    filasNSLO.push_back(filaO);

    int i = 0;
    for(auto v : filaDeAvioes) {
        if(v == "N") i = 0;
        else if(v == "S") i = 1;
        else if(v == "L") i = 2;
        else if(v == "O") i = 3;
        else filasNSLO[i].push(v);
    }
    
    i = 0;
    while(!filasNSLO[0].empty() || !filasNSLO[1].empty() || !filasNSLO[2].empty() || !filasNSLO[3].empty()) {
        
        if(!filasNSLO[i].empty()) {
            std::cout << filasNSLO[i].front();
            filasNSLO[i].pop();
            if(!filasNSLO[0].empty() || !filasNSLO[1].empty() || !filasNSLO[2].empty() || !filasNSLO[3].empty()) {
                std::cout << " ";
            }
        }

        i = (i + 1) % 4;
    }
}