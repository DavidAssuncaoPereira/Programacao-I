#include <stdio.h>
#include <stdlib.h>

void main()
{
    int c, i;
    float vencimento = 0, bonus = 0, total = 0;
    printf("Insere o seu nivel (1, 2 ou 3): ");
    scanf("%i", &c);
    printf("Numero de dependentes: ");
    scanf("%i", &i);
    switch (c) {
        case 1:
            vencimento = 600;
            if (i == 1) {
                bonus = vencimento * 0.05;
            } else if (i >= 2) {
                bonus = vencimento * 0.09;
            }
            break;
        case 2:
            vencimento = 750;
            if (i == 1) {
                bonus = vencimento * 0.03;
            } else if (i >= 2) {
                bonus = vencimento * 0.07;
            }
            break;
        case 3:
            vencimento = 1000;
            if (i == 1) {
                bonus = vencimento * 0.02;
            } else if (i >= 2) {
                bonus = vencimento * 0.05;
            }
            break;
        default:
            printf("Categoria invalida!\n");
    }
    total = vencimento + bonus;
    printf("Vencimento Base: %.2f\n", vencimento);
    printf("Bonus por Dependentes: %.2f\n", bonus);
    printf("Total a receber: %.2f\n", total);
}

