#include <stdio.h>

int somaIgual(long long int v[1000000], long long int comeco, long long int fim, long long int s) {
    while(comeco < fim) {
        long long int soma = v[comeco] + v[fim];
        if(soma == s) {
            return 1;
        }
        else if(soma > s) {
            fim--;
        }
        else if(soma < s) {
            comeco++;
        }
    }

    return 0;
}

int main()
{
    int t;
    long long int n, s;
    long long int v[1000000];

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf("%lld", &n);

        for(int j = 0; j < n; j++) {
            scanf("%lld ", &v[j]);
        }

        scanf("%lld", &s);

        long long int comeco, fim;
        comeco = 0;
        fim = n-1;

        if(somaIgual(v, comeco, fim, s)) {
            printf("SIM\n");
        }
        else {
            printf("NAO\n");
        }
    }

    return 0;
}