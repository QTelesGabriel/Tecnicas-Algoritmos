#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);

    long int a, q;
    std::cin >> a >> q;

    std::vector<int> notas(a);
    for (long int i = 0; i < a; i++) {
        std::cin >> notas[i];
    }
    for (long int i = 0; i < q; i++) {
        long int nota;
        std::cin >> nota;

        auto indice = upper_bound(notas.begin(), notas.end(), nota);
        long int notasMaiores = notas.end() - indice;
        std::cout << notasMaiores << " notas maiores que " << nota << std::endl;
    }

    return 0;
}
