#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("Insere um numero inteiro:");
    scanf(" %d", &n);
    if (n==0)
        printf("\nNulo");
    else
        if (n<0)
            printf("\nNegativo");
        else
            printf("\nPositivo");
    if (n % 2 ==0)
        printf("\nPar");
    else
        printf("\nImpar");
}
