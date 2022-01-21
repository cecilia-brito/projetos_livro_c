#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "forca.h"

#define maxAttemptsHard 6
#define maxAttemptsMedium 9
#define maxAttemptsEasy 12
#define wordSize 20

int maxAttempts;

char gameSecretWord[wordSize];

int attempts = 0;
char kicks[26]; 

void opening(){
    printf("/*******************************************/\n");
    printf(" Hello, player! Welcome to the hangman game! \n");
    printf("/*******************************************/\n");
}

void chooseWord(){
    FILE* wordFile;

    wordFile = fopen("words.txt", "r");

    if(wordFile == 0){
        printf("DB connection failed");
        exit(1);
    }

    int numWords;
    fscanf(wordFile, "%d", &numWords);

    srand(time(0));
    int random = rand() % numWords;

    for(int i = 0; i <= random; i++) {
        fscanf(wordFile, "%s", gameSecretWord);
    }
 
    fclose(wordFile);

}

int alreadyWasItKicked(char letter){

    int alreadyBeenKicked = 0;

    for(int i = 0; i < attempts; i++){
        if(letter == kicks[i]){
            alreadyBeenKicked = 1;
            break;
        }
    }

    return alreadyBeenKicked;
}

void drawHangmanGame(){

    int mistakes = wrongKicks();
 
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (mistakes>=1?'(':' '), (mistakes>=1?'_':' '), (mistakes>=1?')':' '));
    printf(" |      %c%c%c  \n", (mistakes>=3?'\\':' '), (mistakes>=2?'|':' '), (mistakes>=3?'/': ' '));
    printf(" |       %c     \n", (mistakes>=2?'|':' '));
    printf(" |      %c %c   \n", (mistakes>=4?'/':' '), (mistakes>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    printf("Você já fez %d tentativas você tem %d tentativas restantes\n\n", attempts, maxAttempts - attempts);
    
    for(int i = 0; i < strlen(gameSecretWord); i++){
        if (alreadyWasItKicked(gameSecretWord[i])){
            printf("%c ", gameSecretWord[i]);
        } else{
            printf(" ");
            printf("_ ");
        }
    }    

    printf("\n");
}

void playerKicked(){
    char currentPlayerKick;
    printf("\n\n -> Qual a letra: ");
    scanf(" %c", &currentPlayerKick);

    if(currentPlayerKick >= 65 && currentPlayerKick <= 90){
        if(letterExists(currentPlayerKick)){
            printf("Você acertou: a palavra tem a letra %c\n\n", currentPlayerKick);
        } else{
            printf("\nVocê errou: a palavra não tem a letra %c\n\n", currentPlayerKick);
        }

        kicks[attempts] = currentPlayerKick;
        
        attempts++;
    } else {
        printf("\n\nDigite em letras MAIÚSCULAS, por favor :)\n\n");
        playerKicked();
    }

    printf("\n");
}

int itIsHanged(){

    return  wrongKicks() > maxAttempts;

}

int itWon(){

    for(int i = 0; i < strlen(gameSecretWord); i++) {
        if(!alreadyWasItKicked(gameSecretWord[i])) {
            return 0;
        }
    }
 
    return 1;
}

void playerAddWord(){
    char want;

    printf("Você deseja adicionar uma nova palavra no jogo? S/N");
    scanf(" %c", &want);

    if(want == 'S' || want == 's'){
        char newWord[wordSize];

        printf("Digite a palavra em letras maiúsculas");
        scanf("%s", &newWord);

        for(int i = 0; i < strlen(newWord); i++){
            char word = newWord[i];
            while ((word <= 65) && (word >= 90)){
                printf("\n\nDigite letras MAIÚSCULAS, por favor :)\n\n");
                scanf("%s", &newWord);
            }    
        }
            FILE* wordFile;

            wordFile = fopen("words.txt", "r+");

            if(wordFile == 0){
                printf("DB Connection failed");
                exit(1);
            } 

            int amount;
            fscanf(wordFile, "%04d", &amount);
            amount++;

            fseek(wordFile, 0, SEEK_SET);
            fprintf(wordFile, "%04d", amount);
    
            fseek(wordFile, 0, SEEK_END);
            fprintf(wordFile, "\n%s", newWord);
    
            fclose(wordFile);
    } else {
        return 0;
    }
}

int letterExists(char letter) {
 
    for(int j = 0; j < strlen(gameSecretWord); j++) {
        if(letter == gameSecretWord[j]) {
            return 1;
        }
    }
 
    return 0;
}
 
int wrongKicks() {
    int  mistakes = 0;
 
    for(int i = 0; i < attempts; i++) {
        
        if(!letterExists(kicks[i])) {
            mistakes++;
        }
    }
 
    return mistakes;
}

void chooseDifficultLevel(){
    int level;
    printf("Escolha seu nível de dificuldade [1]fácil [3]médio [5]difícil\n");
    scanf("%d", &level);
    if((level != 1) && (level != 3) && (level != 5)){
        printf("-> Digite um nível válido");
        chooseDifficultLevel();
    } else {
        switch (level){
        case 1:
            maxAttempts = maxAttemptsEasy;
            break;
        
        case 3:
            maxAttempts = maxAttemptsMedium;
            break;
        
        case 5:
            maxAttempts = maxAttemptsHard;
            break;

        default:
            break;
        }
    }
}

int
main(void){

    opening();
    chooseWord();
    chooseDifficultLevel();

    do{

        drawHangmanGame();

        if(attempts < maxAttempts){

            playerKicked();
           
        } else{
             break;
        }

    } while(!itWon() && !itIsHanged());

      if(itWon()) {
        printf("\nParabéns, você ganhou!\n\n");
 
        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

        playerAddWord();
 
    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", gameSecretWord);
 
        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
}