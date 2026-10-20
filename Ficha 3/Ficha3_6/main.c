#include <stdio.h>
#include <stdlib.h>

int menu(int n){
    int c;
    printf("****Menu****");
    printf("\n\n(1) - Incrementa\t\t\tNumero: %i\n(2) - Decrementa\n(3)- Zero\n\n(0) - Sair\n- ", n);
    scanf(" %i", &c);
    return c;
}

void main()
{
    int c,n;
    printf("Insere um valor: ");
    scanf(" %i", &n);
    do{
        c=menu(n);
    switch(c){
        case 1: n++; break;
        case 2: n--; break;
        case 3: n=0; break;
        case 0: exit(0); break;
        default: printf("Opcao invalida\n"); }
    }while(c!=0);
}
