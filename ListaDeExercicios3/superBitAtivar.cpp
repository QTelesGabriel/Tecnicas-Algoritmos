#include <iostream>
#include <cstdint>

int main()
{
    int n, b;
    std::cin >> n >> b;
    
    for(int i = 0; i < n; i++) {
        uint32_t num;
        std::cin >> num;

        num |= (0b1 << b);

        std::cout << num << std::endl;

    }

    return 0;
}