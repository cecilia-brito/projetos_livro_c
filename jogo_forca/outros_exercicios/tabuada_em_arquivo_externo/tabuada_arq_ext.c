#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int 
main(void){
    int num;
    printf("Digite o número para ser calculado sua tabuada: ");
    scanf("%d", &num);

    FILE* arq_tabuada;

    arq_tabuada = fopen("tabuada.txt", "r+");

    if(arq_tabuada == 0){
        printf("DB Connection failed");
        exit(1);
    } else {
        int amount;

        fscanf(arq_tabuada, "%04d", &amount);
        amount = 20;

        fseek(arq_tabuada, 0, SEEK_SET);
        fprintf(arq_tabuada, "%04d", amount);
        for(int i = 1; i <= amount; i++){
            int result = num * i;
            fseek(arq_tabuada, 0, SEEK_END);
            fprintf(arq_tabuada, "\n%d x %d = %d", num, i, result);
        }
    
        fclose(arq_tabuada);
    }
}