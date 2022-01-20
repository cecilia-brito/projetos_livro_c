// #include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void opening(){
    printf("/*******************************************/\n");
    printf(" Hello, player! Welcome to the hangman game! \n");
    printf("/*******************************************/\n");
}

char playerKicked(char currentPlayerKick, char kicks[], int* attempts){

    printf("Qual a letra: \n");
    scanf(" %c", &currentPlayerKick);

    kicks[*attempts] = currentPlayerKick;
    
    (*attempts)++;
}

int wasItKicked(char playerKick, char kicks[], int* attempts){

    int found = 0;

    for(int i = 0; i < (*attempts); i++){
        if(playerKick == kicks[i]){
            found = 1;
            break;
        }
    }

    return found;
}

int didPlayerGetItRight(char secretWord[], char kicks[]){
    for(int i = 0; i < strlen(secretWord); i++){
        if(secretWord[i] == kicks[i]){
                printf("A posição %d tem essa letra\n", i + 1);
        }
    }
}

int
main(void){

    #define maxAttempts 5

    int attempts = 0;
    int gotItRight = 0;
    int hanged = 0;

    char gameSecretWord[20];
    sprintf(gameSecretWord, "MELANCIA");

    char currentPlayerKick;
    char kicks[26]; 

    opening();

    do{

        printf("Você já fez %d tentativas você tem %d tentativas restantes", attempts, maxAttempts - attempts);

        for(int i = 0; i < strlen(gameSecretWord); i++){
            printf("_ ");
        }

        printf("\n");

        playerKicked(currentPlayerKick, kicks, &attempts);

        didPlayerGetItRight(gameSecretWord, kicks);

        wasItKicked(currentPlayerKick, kicks, &attempts);

    } while(!gotItRight && !hanged);

}