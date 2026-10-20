#include <stdio.h>
#include <stdlib.h>

void main() {
    int numero, soma = 0;
    printf("Introduza um número entre 1 e 10: ");
    scanf("%d", &numero);
    if (numero >= 1 && numero <= 10) {
        for (int i = 1; i <= numero; i++) {
            soma += i;
        }
        printf("A soma de todos os números até %d é: %d\n", numero, soma);
    } else {
        printf("Número inválido! Por favor, introduza um número entre 1 e 10.\n");
    }
}
