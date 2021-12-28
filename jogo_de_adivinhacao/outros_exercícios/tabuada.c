#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(void){
    int num;
    int multiplicacao;

    printf("Digite o número inteiro que você quer a tabuada:");
    scanf("%d", &num);
    for(int i = 1; i <= 10; i++){
        multiplicacao = num * i;
        printf("%dx%d=%d\n",num, i, multiplicacao);
    }
}