// #include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o skittles skittles.c -lcs50 -lm

int
main(void){
    int gotItRight = 0;
    int hanged = 0;
    char gameSecretWord[20];
    gameSecretWord[0] = "M";
    gameSecretWord[1] = "E";
    gameSecretWord[2] = "L";
    gameSecretWord[3] = "A";
    gameSecretWord[4] = "N";
    gameSecretWord[5] = "C";
    gameSecretWord[6] = "I";
    gameSecretWord[7] = "A";
    gameSecretWord[8] = "\0";

    do{
        char playerKick;
        printf("Qual a letra: \n");
        scanf("%c", &playerKick);
        for(int i = 0; i < strlen(gameSecretWord); i++){
            if(gameSecretWord[i] == playerKick){
                printf("A posição %d tem essa letra\n", i + 1);
            }
        }
        

    } while(!gotItRight && !hanged);

}