#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo = 0;

int isPrimo(int num){
    int j = 2;
    do{
         if((num % j) != 0){
            primo = 1;
        } else if(num == j) {
            primo = 1;
        }else{
            primo = 0;
            break;
        }
        j++;
    } while(j < num);

    return primo;
}

int
main(void){
    int intervalStart;
    int intervalEnd;
    int sum = 0;

    printf("Digite um número inteiro positivo, que será o início do intervalo, por favor: ");
    scanf("%d", &intervalStart);
    while(intervalStart < 0){
        scanf("%d", &intervalStart);
    }
    printf("Digite um número inteiro positivo, que será o fim do intervalo, por favor:");
    scanf("%d", &intervalEnd);
    while(intervalEnd < 0){
        scanf("%d", &intervalEnd);
    }
    printf("Os números primos nesse intervalo são:");
    for(int i = intervalStart; i <= intervalEnd; i++){
        if(isPrimo(i)){
            sum += i;
            printf(" %d", i);
        }
    }

    printf("\n\nA soma dos números primos no intervalo %d - %d é: %d\n\n", intervalStart, intervalEnd, sum);
}