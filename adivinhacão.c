#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void){
    int points = 1000;
    int tries = 0;
    int won = 0;
    int kick;

    srand(time(NULL));
    int randomNumber = rand() % 100;

    printf("Seja bem-vinde ao jogo de adivinhação! Acerte o número aleatório e vença o jogo! \n");
    

    while(!won){
        scanf("Digite seu chute: %d \n", kick);
        if(kick == randomNumber){
            printf("Parabéns você ganhou!");
            break;
        } else if(kick > randomNumber) {
            printf("O número que você chutou é muito alto!\n");
        } else{
            printf("O número que você chutou é baixo!\n");
        }
    }
    
}