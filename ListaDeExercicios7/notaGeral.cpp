#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long int alunos;
    scanf("%lld", &alunos);

    std::vector<long long int> notas(11, 0);
    int nota;

    for(long long int i = 0; i < alunos; i++) {
        scanf("%d", &nota);
        notas[nota]++;
    }

    for(int i = 0; i <= 10; i++) {
        for(long long int j = 0; j < notas[i]; j++) {
            printf("%d\n", i);
        }
    }

    return 0;
}