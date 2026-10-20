#include <stdio.h>
#include <stdlib.h>

void main()
{
    int numero;
    int n2;
    printf("David\n");
    printf("Leiria\n\n");
    printf("Insere um numero: ");
    fflush(stdin);
    scanf("%d", &numero);
    printf("O numero e: %d\n", numero);
    printf("Insere o segundo numero: ");
    scanf("%d", &n2);
    printf("Valor = %d",n2);

}
