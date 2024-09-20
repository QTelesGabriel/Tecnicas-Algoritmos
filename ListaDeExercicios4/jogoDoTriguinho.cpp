#include <iostream>
#include <cstdint>

int main()
{
    long int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        uint64_t objetivo, trigosDepositados;
        trigosDepositados = 0;
        std::cin >> objetivo;

        while(objetivo) {
            trigosDepositados += objetivo & 1;
            objetivo >>= 1;
        }
        
        std::cout << trigosDepositados << std::endl;     
    }
}