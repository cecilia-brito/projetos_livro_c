#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void){
    double points = 1000;
    int tries = 0;
    int won = 0;
    int kick;
    int Maxtries;

    srand(time(NULL));
    int randomNumber = rand() % 100;

    printf("Seja bem-vinde ao jogo de adivinhação! Acerte o número aleatório e vença o jogo! \n");
    

    do{
        printf("Qual é seu chute?\n");
        scanf("%d", &kick);
        
        if(kick <0){
            printf("Você não pode chutar números negativos! Tente novamente\n");
            tries--;
        } else if (kick == randomNumber){
            won = 1;
            printf("Parabéns você ganhou!\n");
            points -= (double) ((abs(kick) - randomNumber)/2);
            tries++;
            printf("Seus pontos foram: %.1f", points);
            break;

        } else if(kick > randomNumber) {
            printf("O número que você chutou é muito alto!\n");
            points -= (double) ((abs(kick) - randomNumber)/2);
            tries++;

        } else{
            printf("O número que você chutou é baixo!\n");
            points -= (double) ((abs(kick) - randomNumber)/2);
            tries++;
        }

    } while (won == 0);
    
    
}