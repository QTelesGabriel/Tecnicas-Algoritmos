#include <iostream>
#include <string>
#include <queue>

int main()
{
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::string bloco;        
        std::cin >> bloco;
        std::queue<char> pedras;

        for(auto b : bloco) {
            if(b == '<' || b == '>') {
                pedras.push(b);
            }
        }
      
        std::queue<bool> abertos;
        int pedrasPreciosas = 0;
        int contador = (int)pedras.size();
        for(int i = 0; i < contador; i++) {
            if(pedras.front() == '<') {
                abertos.push(true);
            }
            if(pedras.front() == '>' && !abertos.empty()) {
                abertos.pop();
                pedrasPreciosas++;
            }
            pedras.pop();
        }

        std::cout << pedrasPreciosas << std::endl;
    }

    return 0;
}