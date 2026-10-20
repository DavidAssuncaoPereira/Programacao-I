#include <stdio.h>
#include <stdlib.h>

void main()
{
    int l1,l2,l3;
    printf("Linha 1: ");
    scanf("%i",&l1);
    printf("\nLinha 2: ");
    scanf("%i",&l2);
    printf("\nLinha 3: ");
    scanf("%i",&l3);

    if (l1-l2<l3 && l3<l1+l2){
        if(l1 == l2 && l1 == l3)
            printf("\n equilatro");
        else if (l1 != l2 && l1!=l3 && l2!= l3 ){
            printf("\nescaleno")
            else if (l1 == l2 || l2==l3|| l1==l3)
                    printf("\nIsoxeles");
        }
    }
    else
        printf("Não é um Triangulo");
}
