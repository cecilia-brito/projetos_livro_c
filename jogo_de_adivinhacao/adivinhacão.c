#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gameRun(){

    double points = 1000;
    int level;
    int tries = 0;
    int won = 0;
    int maxTries;
    int intervalStart;
    int intervalEnd;
    int kick;
    int playAgain;
    

    printf("    *                  *           \n");
    printf("         __                *       \n");
    printf("      ,db'    *     *              \n");
    printf("     ,d8/       *        *    *    \n");
    printf("     888                          Seja bem-vinde ao\n");
    printf("     `db\\       *     *          jogo de adivinhação! Acer-\n");
    printf("       `o`_                    ** te o número aleatório e   \n");
    printf("   *               *   *    _      * vença o jogo!\n");
    printf("         *                 / )     \n");
    printf("     *    (\\__/) *       ( (  *    \n");
    printf("   ,-.,-.,)    (.,-.,-.,-.) ).,-.,-.\n");
    printf("  | @|  ={      }= | @|  / / | @|o |\n");
    printf(" _j__j__j_)     `-------/ /__j__j__j_ \n");
    printf(" ________(               //___________\n");
    printf("  ||  || @|| \\              |||| o||O || @||\n");
    printf("  ||o ||  ||,'\\       ,   ,'""||  ||  ||  ||  hjw\n");
    printf(" vV\\|/vV|`-'\\  ,---\\   | \\Vv\\hjwVv\\///v");
    printf("            _) )    `. \\ /\n");
    printf("           (__/       ) )\n");
    printf("                     (_/\n");

    printf(" \n");

    printf("Escolha seu nível de dificuldade [1]fácil [3]médio [5]difícil\n");
    scanf("%d", &level);
    
    //choose the level and configure tries for game
    switch (level)
    {
        case 1:
            maxTries = 20;
            break;

         case 3:
            maxTries = 16;
            break;

        case 5:
            maxTries = 6;
            break;

        default:
            maxTries = 6;
            break;
    }

    //get up input user about interval of random number 
    printf("Escolha o intervalo onde o número estará:\n");
    printf("Início do intervalo:\n");
    scanf("%d", &intervalStart);
    printf("Fim do intervalo:\n");
    scanf("%d", &intervalEnd);
    
    //seed setting up
    srand(time(NULL));
    int randomNumber = rand() % (intervalEnd + 1 - intervalStart) + intervalStart;

    printf("O intervalo escolhido foi %d - %d\n", intervalStart, intervalEnd);
    
    //run game
    do{
        int remainsTries = maxTries - tries;
        printf("Qual é seu chute? Você possui %d tentativas\n", remainsTries);
        scanf("%d", &kick);
        
        if(kick < 0){
            printf("Você não pode chutar números negativos! Tente novamente\n");
            tries--;
        } else if (kick == randomNumber){
            won = 1;
            printf("Parabéns você ganhou com %d tentativas!\n", tries);
            double lessPoints = (double) ((abs(kick) - randomNumber)/2);
            points = points - lessPoints;
            tries++;

            printf("Seus pontos foram: %.1f \n", points);

            //asks for user if they would like to play again and starts the game if answer will be "Yes"
            printf("Deseja jogar novamente? [1] para jogar novamente [0] para encerrar\n");
            scanf("%d", &playAgain);
            switch (playAgain){
                case 1:
                    gameRun();
                    break;
            
                case 0:
                    break;

                default:
                    break;
            }
            break;

        } else if(kick > randomNumber) {
            printf("O número que você chutou é muito alto!\n");
            double lessPoints = (double) ((abs(kick) - randomNumber)/2);
            points = points - lessPoints;
            tries++;

        } else{
            printf("O número que você chutou é baixo!\n");
             double lessPoints = (double) ((abs(kick) - randomNumber)/2);
            points = points + lessPoints;
            tries++;
        }

    } while ((won == 0) && (tries < maxTries));
    
    //tests if user lost or no and asks if they would like to play again
    if (!won){
        printf("Você perdeu :C Tente novamente!\n");
        printf("Deseja jogar novamente? [1] para jogar novamente [0] para encerrar\n");
        scanf("%d", &playAgain);
        switch (playAgain){
        case 1:
            gameRun();
            break;
            
        case 0:
            break;

        default:
            break;
        }
    }    
}

int
main(void){
    
    //call function thats runs the game
    gameRun();
    return 0;
}