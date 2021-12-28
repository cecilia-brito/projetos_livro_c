#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int
main(void){
    float num1;
    float num2;
    int operation;
    float result;

    printf("ESTÁ PRONTE PARA USAR A CALCULADORA? DIGITE DOIS NÚMEROS E ESCOLHA A OPERAÇÃO\n");

    printf("DIGITE O PRIMEIRO NÚMERO:\n");
    scanf("%f", &num1);
    
    printf("DIGITE O SEGUNDO NÚMERO:\n");
    scanf("%f", &num2);

    printf("ESCOLHA A OPERAÇÃO PRESSIONANDO [1]ADIÇÃO [2]SUBTRAÇÃO [3]MULTIPLICAÇÃO [4]DIVISÃO\n");
    scanf("%d", &operation);

    switch (operation)
    {
    case 1:
        result = num1 + num2;
        printf("%f + %f = %f\n", num1, num2, result);
        break;
    case 2:
        result = num1 - num2;
        printf("%f - %f = %f\n", num1, num2, result);
        break;
    case 3:
        result = num1 * num2;
        printf("%f x %f = %f\n", num1, num2, result);
        break;
    case 4:
        result = num1 / num2;
        printf("%f / %f = %f\n", num1, num2, result);
        break;
    default:
        break;
    }
}