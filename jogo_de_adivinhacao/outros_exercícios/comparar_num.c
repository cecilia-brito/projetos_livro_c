#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int 
main(void){
    int num1;
    int num2;
    int num3;
    int maiornum;
    int medionum;
    int menornum;

    printf("Digite três números inteiros");
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
   
   if(num1>=num2 && num1>=num3){
       maiornum = num1;
   } else if (num2>=num1 && num2>=num3){
       maiornum = num2;
   } else if (num3>=num1 && num3>= num2){
       maiornum = num3;
   }

   if(num1<=num2 && num1<=num3){
       menornum = num1;
   } else if (num2<=num1 && num2<=num3){
       menornum = num2;
   } else if (num3<=num1 && num3<= num2){
       menornum = num3;
   }
   
   if(menornum == num1 && maiornum == num2){
       medionum == num3;
   } else if (menornum == num2 && maiornum == num3){
       medionum == num1;
   } else{
       medionum = num2;
   }
   
    printf("%d, %d, %d", menornum, medionum, maiornum);
}