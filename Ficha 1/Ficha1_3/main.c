#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n1, dobro;
    float n2, area;
    const float pi = 3.1416;
    printf("Insira um numero para calcular o dobro: ");
    scanf("%d", &n1);
    dobro=n1*2;
    printf("O dobro = %d\n\n", dobro);

    printf("Insere o raio: ");
    scanf("%f", &n2);
    float perimetro = 2*pi*n2;
    printf("Valor da perimetro = %f \n", perimetro);
    printf("\nValor da perimetro = %.2f", perimetro);
    printf("\n\nValor da perimetro = %7.2f\n", perimetro);
    area=pi*(n2*n2);
    printf("Valor da area = %f \n", area);
    printf("\nValor da area = %.2f", area);
    printf("\n\nValor da area = %7.2f", area);

    return;
}
