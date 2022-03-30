#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include "comecome.h"
#include "map.h"

MAP m;

position user;

int finished(){
    return 0;
}

void findMap(MAP* m, position* p, char c){
    for(int i = 0; i < m->lines; i++){
        for(int j = 0; j < m->columns; j++){
            if(m->matriz == c){
                p->x = i;
                p->y = j;
                return;
            }
        }
    }
}

void move(char direction){

    switch(direction){
        case 'a':
            m.matriz[user.x][user.y - 1] = '@';
            user.y--;
            break;
        case 'w':
            m.matriz[user.x - 1][user.y] = '@';
            user.x--;
            break;
        case 's':
            m.matriz[user.x][user.y + 1] = '@';
            user.y++;
            break;
        case 'd':
            m.matriz[user.x + 1][user.y] = '@';
            user.x++;
            break;    
    }

    m.matriz[user.x][user.y] = '@';
}

int main(){
    readMap(&m);
    // alocatteMap()
    findMap(&m,&user,'@');
    do{
        printMap(&m);

        char command;
        scanf(" %c", &command);

        move(command);

    } while(!finished());

    
    freeMap(&m);
}