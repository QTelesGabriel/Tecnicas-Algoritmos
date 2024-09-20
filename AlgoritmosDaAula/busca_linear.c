#include <stdio.h>

int main()
{
    int N = 3
    int lista[] = {3, 1, 5};
    int valor = 8;

    for(int i = 0; i < N; i++) {
        if(lista[i] == valor) {
            puts("Valor encontrado");   //puts já adiciona um \n no final da string
            break;
        }
    }

    return 0;
}