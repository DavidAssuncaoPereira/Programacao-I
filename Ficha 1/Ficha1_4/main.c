#include <stdio.h>
#include <stdlib.h>

void main(){
    int n1, n2;
    int resultadoInt;
    float resultadoFloat;
    printf("Insere o primeiro valor = "); scanf("%d", &n1);
    printf("Insere o segundo valor = "); scanf("%d", &n2);

    resultadoInt=n1+n2;
    printf("soma  \t\t %d + %d = %4d\n", n1, n2, resultadoInt);
    resultadoInt=n1-n2;
    printf("Subtracao\t %d - %d = %4d \n",n1, n2, resultadoInt);
    resultadoInt=n1*n2;
    printf("Multiplicacao \t %d * %d = %4d \n",n1, n2, resultadoInt);
    resultadoFloat=n1/n2;
    printf("Divisao\t\t %d / %d = %4.0f \n",n1, n2, resultadoFloat);
    resultadoFloat=n1%n2;
    printf("Resto\t\t %d %% %d = %4.0f \n",n1, n2, resultadoFloat);

}
