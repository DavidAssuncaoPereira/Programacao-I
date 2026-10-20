#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, c;
    int soma=0;
    int cont=0;
    printf("Insere um numero: ");
    scanf(" %i", &n);
    printf("(1) For\n(2) While\n(3)Do...While\n\n(0)Sair\n-");
    scanf(" %i",&c);
    switch(c){
case 1:
    for(int i = 0; i<n; i++){
        soma=i+soma;
        printf(" %i", soma);
    }break;
case 2:
    while(cont<n){
        soma=cont+soma;
        printf(" %i", soma);
        cont++;
    }
    break;
case 3:
    do{
        soma=cont+soma;
        printf(" %i", soma);
        cont++;
    }while(cont<n);
    break;
    case 0:exit(0);
    break;

}}
