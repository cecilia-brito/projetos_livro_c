#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(void){
    int num;
    int fatorial = 1;
    printf("Digite um número inteiro:\n");
    scanf("%d", &num);

    for (int i = num; i <= num && i > 0; i--){
        fatorial = fatorial * i;
    }

    printf("O fatorial de %d é: %d\n", num, fatorial);
}