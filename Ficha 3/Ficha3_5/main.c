#include <stdio.h>
#include <stdlib.h>

void main()
{
   int n,m;
   float r=0;
   do{
    printf("Insere o valor de n: ");
    scanf(" %i", &n);
    printf("Insere o valor de m: ");
    scanf(" %i", &m);
   }while(m>=n);
   for(;m < n; m++){
        r+=(float)(2*m)/(5+m*m);
   }
   printf("A soma e: %.2f", r);
}
