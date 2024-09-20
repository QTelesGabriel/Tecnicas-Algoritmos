#include <iostream>
#include <deque>
#include <queue>

int main() {
    std::deque<int> baralho;
    std::queue<int> descarte;
    int n; 

    std::cin >> n;
    
    for(int i = n; i > 0; i--) {
        baralho.push_back(i);
    }

    while(baralho.size() > 1) {
        descarte.push(baralho.front());
        baralho.pop_front();
        baralho.emplace_back(baralho.front());
        baralho.pop_front();
    }

    if(baralho.size() == 1) {
        descarte.push(baralho.front());
        baralho.pop_front();
    }

    std::cout << "Descarte: ";
    while(descarte.size() > 2) {
        std::cout << descarte.front() << ", ";
        descarte.pop();
    }
    if(descarte.size() > 1) {
        std::cout << descarte.front();
        descarte.pop();
    }
    std::cout << std::endl;
    std::cout << "Ultima carta: " << descarte.front() << std::endl;

    descarte.pop();

    return 0;
}