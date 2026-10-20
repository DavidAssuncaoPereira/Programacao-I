#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n=-1;
    int i,soma=0,r,c;
    printf("Insira o numero de elementos a inserir: ");
    scanf(" %i", &c);
    for(i = 0; i!=c; i++){
        printf("Insere um numero: ");
        scanf(" %i", &n);
        soma+=n;
    }
    r=soma/i;
    printf("A media e : %i", r);
}
