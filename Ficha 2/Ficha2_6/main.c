#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("Insere um numero do mes:");
    scanf("%i",&n);
    switch (n){
    case 1: printf("\nJaneiro"); break;
    case 2: printf("\nFevereiro");break;
    case 3: printf("\nMarco");break;
    case 4: printf("\nAbril");break;
    case 5: printf("\nMaio");break;
    case 6: printf("\nJunho");break;
    case 7: printf("\nJulho");break;
    case 8: printf("\nAgosto");break;
    case 9: printf("\nsetembro");break;
    case 10: printf("\nOutobro");break;
    case 11: printf("\nNovembro");break;
    case 12: printf("\nDezembro");break;
    default: printf("\nNão é um mes do ano");}
}
