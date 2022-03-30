#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include "map.h"

MAP m;

void readMap(MAP* m){
    FILE* f;
    f = fopen("map.txt", "r");
    if(f == 0){
        printf("Error on map read");
        exit(1);
    }
    
    fscanf(f, "%d %d", &m->lines, &m->columns);

    alocatteMap(m);

    for(int i = 0; i < m->lines; i++){
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void alocatteMap(MAP* m){
    m->matriz = malloc(sizeof(char*) * m->lines);

    for(int i = 0; i < m->lines; i++){
        m->matriz = malloc(sizeof(char) * m->columns + 1);
    }
}

void freeMap(MAP* m){
    for(int i = 0; i < m->lines; i++){
        free(m->matriz[i]);
    }
}

void printMap(MAP* m){
    for(int i = 0; i < m->lines; i++){
        printf("\n%s", m->matriz[i]);
    }
}
