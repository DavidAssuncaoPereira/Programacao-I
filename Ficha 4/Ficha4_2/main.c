#include <stdio.h>
#include <stdlib.h>

char exibirMenu(int *t, int *r, int *c, int *q);
int lerlado();

void main() {
    int t = 0, r = 0, c = 0, q = 0;
    char op;
    int l1, l2;
    float area;
    const float pi = 3.1416;

    do {
        op = exibirMenu(&t, &r, &c, &q);

        switch(op) {
            case 'T':
            case 't':
                printf("Insere a base: ");
                l1 = lerlado();
                printf("Insere a altura: ");
                l2 = lerlado();

                area = (float)(l1 * l2) / 2;
                printf("Area do Triangulo: %.2f\n", area);
                t++;
                break;

            case 'R':
            case 'r':
                printf("Insere o comprimento: ");
                l1 = lerlado();
                printf("Insere a largura: ");
                l2 = lerlado();

                area = l1 * l2;
                printf("Area do Retangulo: %.2f\n", area);
                r++;
                break;

            case 'Q':
            case 'q':
                printf("Insere o lado: ");
                l1 = lerlado();

                area = l1 * l1;
                printf("Area do Quadrado: %.2f\n", area);
                q++;
                break;

            case 'C':
            case 'c':
                printf("Insere o raio: ");
                l1 = lerlado();

                area = pi * l1 * l1;
                printf("Area do Circulo: %.2f\n", area);
                c++;
                break;

            case 'F':
            case 'f':
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while(op != 'F' && op != 'f');
}

char exibirMenu(int *t, int *r, int *c, int *q) {
    char op;

    printf("\n========================================\n");
    printf("Calculo de Areas\n");
    printf("Triangulo (%d) | Retangulo (%d) | Circulo (%d) | Quadrado (%d)\n", *t, *r, *c, *q);
    printf("========================================\n");
    printf("OPCOES:\n");
    printf("(T)riangulo\n(R)etangulo\n(Q)uadrado\n(C)irculo\n(F)im\n");
    printf("Selecione opcao: ");

    scanf(" %c", &op);
    return op;
}

int lerlado() {
    int n;
    scanf("%d", &n);
    return n;
}
