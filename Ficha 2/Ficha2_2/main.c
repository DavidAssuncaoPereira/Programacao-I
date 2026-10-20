#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, n3;
    printf("Insere um numero: ");
    scanf("%i" , &n1);
    printf("Insere um numero: ");
    scanf("%i" , &n2);
    printf("Insere um numero: ");
    scanf("%i" , &n3);
    if (n1 != n2 && n1!=n3 && n2!= n3 )
        printf("Sao todos diferentes!");
    else
        printf("Ha pelo menos um numero repetido!");
}
