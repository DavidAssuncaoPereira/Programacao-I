#include <stdio.h>
#include <stdlib.h>

void main() {
    int dia, mes, ano;
    int data_valida = 1;
    int dias_no_mes;
    printf("Introduza o dia: ");
    scanf("%d", &dia);
    printf("Introduza o mês: ");
    scanf("%d", &mes);
    printf("Introduza o ano: ");
    scanf("%d", &ano);
    if (ano < 1 || mes < 1 || mes > 12) {
        data_valida = 0;
    } else {
        switch (mes) {
            case 4: case 6: case 9: case 11:
                dias_no_mes = 30;
                break;
            case 2:
                if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
                    dias_no_mes = 29;
                } else {
                    dias_no_mes = 28;
                }
                break;
            default:
                dias_no_mes = 31;
                break;
        }
        if (dia < 1 || dia > dias_no_mes) {
            data_valida = 0;
        }
    }
    if (data_valida) {
        printf("\nA data %02d/%02d/%d e VALIDA.\n", dia, mes, ano);
    } else {
        printf("\nA data %02d/%02d/%d e INVALIDA.\n", dia, mes, ano);
    }
}
