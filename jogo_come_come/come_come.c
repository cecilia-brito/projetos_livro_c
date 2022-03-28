#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(){

    char map[5][10 + 1];

    FILE* f;
    f = fopen("map.txt", "r");
    if(f == 0){
        printf("Error on map read");
        exit(1);
    }
    
    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", map[i]);
        printf("%s\n", map[i]);
    }

    fclose(f);
}