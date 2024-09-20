#include <iostream>
#include <cstdint>

int main()
{
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        long int a, b, c, y;
        std::cin >> a >> b;
        std::cin >> y;

        c = y ^ (a ^ b);

        if((a ^ b ^ c) == y) {
            std::cout << c << std::endl;
        }
        else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}