#include <stdio.h>
#include <stdlib.h>

int
main(void){
    int base;
    int expoente;
    float potencia;
    potencia = 1.00;

    printf("Digite o número: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    if(expoente > 0){
        for(int i = 1; i <= expoente; i++){
            potencia *= base;
        }
    } else if(expoente == 0){
        potencia = 1.00;
    } else if(expoente < 0){
        int i = expoente * -1;
        potencia = 1.00;

        while(i > 0){
            potencia *= (float) 1/base;
            i--;
        } 
    }

    printf("-> %d^%d = %.2f\n", base, expoente, potencia);
}
