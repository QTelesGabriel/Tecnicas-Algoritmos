#include <iostream>
#include <cstdint>

int main()
{
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        uint64_t a, b, y;
        std::cin >> a >> b;
        std::cin >> y;

        unsigned long long int c;
        c = y ^ (a | b);

        if(y == (c | a | b)) {
            std::cout << c << std::endl;
        }
        else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}