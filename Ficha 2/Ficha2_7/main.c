#include <stdio.h>

int main() {
    int n1, n2, r;
    char c1;
    printf("Insere o numero 1: ");
    scanf("%i", &n1);
    printf("Insere o numero 2: ");
    scanf("%i", &n2);
    printf("Insere a operacao: ");
    scanf(" %c", &c1);

    switch (c1) {
        case '+':
            r = n1 + n2;
            printf("Numero 1: %i\nNumero 2: %i\nOperacao: %c\n\nResultado: %i\n", n1, n2, c1, r);
            break;
        case '-':
            r = n1 - n2;
            printf("Numero 1: %i\nNumero 2: %i\nOperacao: %c\n\nResultado: %i\n", n1, n2, c1, r);
            break;
        case '*':
            r = n1 * n2;
            printf("Numero 1: %i\nNumero 2: %i\nOperacao: %c\n\nResultado: %i\n", n1, n2, c1, r);
            break;
        case '/':
            r = n1 / n2;
            printf("Numero 1: %i\nNumero 2: %i\nOperacao: %c\n\nResultado: %i\n", n1, n2, c1, r);
            break;
        case '%':
            r = n1 % n2;
            printf("Numero 1: %i\nNumero 2: %i\nOperacao: %c\n\nResultado: %i\n", n1, n2, c1, r);
            break;
        default:
            printf("Operacao invalida!\n");
            break;
    }
    return 0;
}

