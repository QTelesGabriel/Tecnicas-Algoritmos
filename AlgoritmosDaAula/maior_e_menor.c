#include <stdio.h>

int main()
{
    int contadorDeOperacoes = 0;
    int lista[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int maior = lista[0], menor = lista[0];

    for(int i = 0; i < 10; i++) {
        if(lista[i] > maior) {
            contadorDeOperacoes++;
            maior = lista[i];
        }
        for(int i = 0; i < 10; i++) {
            if(lista[i] < menor) {
                contadorDeOperacoes++;
                menor = lista[i];
            }
        }
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Número de operações: %d\n", contadorDeOperacoes);

    return 0;
}