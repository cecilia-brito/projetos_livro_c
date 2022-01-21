#include <stdio.h>
#include <stdlib.h>

int
main(){
    int number = 0;
    int soma = 0;

    printf("Digite um número inteiro positivos: ");
    scanf("%d", &number);

    while(number < 0){
        printf("digite um número inteiro positivo, por favor: ");
        scanf("%d", &number);
    } 

    int numbers[number];
    
    for(int i = 0; i < number; i++){
        printf("digite %d números inteiro(s) por favor: ", number);
        scanf("%d", &numbers[i]);

        while (numbers[i] < 0) {
            printf("digite um número inteiro positivo, por favor: ");
            scanf("%d", &numbers[i]);
        }   
    }

    for (int i = 0; i < number; i++){
        soma += (numbers[i] % 2 == 0) ? numbers[i]: 0;
    }

    printf("A soma dos números pares da sequência de inteiros é: %d\n", soma);
}