#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor;
    float final
    printf("Insere o valor:")
    scanf("%i",&valor);
    if(valor<=500){
        final=500;
        printf("Total = %f", final);
    else if(valor<=1250){
        final=500*0.04;
        printf("Total = %f", final);
    }
    else if(valor<=2000){
        final=500*0.06;
        printf("Total = %f", final);
    }
    else if(valor>2000){
        final=500*0.08;
        printf("Total = %f", final);
    }
}
