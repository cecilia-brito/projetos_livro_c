#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(void){
    for(int i = 1; i <= 50; i++){
        if(i % 2 == 0){
            printf("%d\n", i);
        }
    }
}