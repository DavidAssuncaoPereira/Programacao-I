#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, temp, soma, temp2;
    printf("Insere um numero: ");
    scanf(" %i", &n);
    temp=n;
    while(temp>0){
        temp2=temp%10;
        soma+=temp2;
        temp = temp /10;
    }
    printf("A soma do numeros e: %d", soma);
}
