#include <stdio.h>

void troca(int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int lista[] = {4, 2, 5, 9, 3, 4, 2, 1};
    int ordenado;
    for(int j = 0; j < 8; j++) {
        ordenado = 1;
        for(int i = 0; i < 8 - 1; i++) {
            if(lista[i] > lista[i + 1]) {
                troca(&lista[i], &lista[i + 1]);
                ordenado = 0;
            }
        }
        if(ordenado) {
            break;
        }
    }

    for(int i = 0; i < 7; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}