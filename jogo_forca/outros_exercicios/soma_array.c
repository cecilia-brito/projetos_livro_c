#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(void){
    int amountInt;
    int sum = 0;
    printf("Digite a quantidade de números que você quer somar: ");
    scanf("%d", &amountInt);
    int intergers[amountInt];
    printf("Digite os números inteiros: \n");
    for (int i = 0; i < amountInt; i++){
        printf(" -> ");
        scanf("%d", &intergers[i]);
    }
    for(int i = 0; i < amountInt; i++){
        sum += intergers[i];
    }

    printf("A soma dos números que você digitou é: %d\n\n", sum);
}