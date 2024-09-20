#include <iostream>
#include <vector>

int main()
{
    int m, c;
    std::cin >> m >> c;

    std::vector<std::vector<int>> hashMap(m);
    int num;

    for(int i = 0; i < c; i++) {
        std::cin >> num;
        hashMap[num % m].push_back(num);
    }

    for(int i = 0; i < (int)hashMap.size(); i++) {
        std::cout << i << " -> ";
        for(auto &n : hashMap[i]) {
            std::cout << n << " -> ";
        }
        std::cout << "\\" << std::endl;
    }

    return 0;
}