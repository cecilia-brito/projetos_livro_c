#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo = 0;

void itIsntPrimoWhatIsYourdividers(int num, int dividers[]){
    for(int i = 2; i <= num; i++){
        dividers[i - 1] = (num % i == 0) ? i : 0; 
    }
}

int isPrimo(int num, int dividers[]){
    for(int i = 2; i < num; i++){
        if((num % i) != 0){
            primo = 1;
        } else{
            primo = 0;
            itIsntPrimoWhatIsYourdividers(num, dividers);
            break;
        }
    }
    return primo;
}

int
main(void){
    int num;
    int count;
    printf("Digite um número inteiro positivo, por favor: ");
    scanf("%d", &num);
    int dividers[abs(num)];
    dividers[0] = 1;

    if(isPrimo(num, dividers)){
        printf("O número %d é primo e só é divísivel por 1 e por ele mesmo\n\n", num);
    } else {
        printf("O número %d não é primo\n\n", num);
        printf("Seus divisores são: ");
        for(int i = 0; i < num; i++){
            if(dividers[i] != 0 && dividers[i] <= num){
                printf("%d ", dividers[i]);
                count++;
            }
        }
        printf("\n\nPortanto o número tem %d divisores\n\n", count);
    }
    
}