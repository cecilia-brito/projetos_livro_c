#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(void){
    int sum;
    for(int i = 1; i <= 100; i++){
        sum += i;
    }
    printf("%d\n", sum);
}