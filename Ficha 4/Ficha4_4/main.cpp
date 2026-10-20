#include <stdio.h>
#include <math.h>

int leNumero();
int soma(int a, int b);
int subtracao(int a, int b);
float raizQuadrada(int a);
int potencia(int base, int exp);

void todasOperacoes(int n1, int n2) {
    printf("Soma = %d\n", soma(n1, n2));
    printf("Subtracao = %d\n", subtracao(n1, n2));
    printf("Raiz quadrada (%d) = %.2f\n", n1, raizQuadrada(n1));
    printf("Raiz quadrada (%d) = %.2f\n", n2, raizQuadrada(n2));
    printf("Potencia (%d, %d) = %d\n", n1, n2, potencia(n1, n2));
    printf("Potencia (%d, %d) = %d\n", n2, n1, potencia(n2, n1));
}

int main() {
    int n1, n2, op;

    do {
        printf("\n1. Soma\n2. Subtracao\n3. Raiz Quadrada\n4. Potencia\n5. Todas\n0. Sair\nOpcao: ");
        scanf("%d", &op);

        if (op >= 1 && op <= 5) {
            printf("--- Entrada de Dados ---\n");
            n1 = leNumero();
            n2 = leNumero();
        }

        switch(op) {
            case 1: printf("Soma = %d\n", soma(n1, n2)); break;
            case 2: printf("Subtracao = %d\n", subtracao(n1, n2)); break;
            case 3:
                printf("Raiz(%d) = %.2f\nRaiz(%d) = %.2f\n", n1, raizQuadrada(n1), n2, raizQuadrada(n2));
                break;
            case 4:
                printf("%d^%d = %d\n", n1, n2, potencia(n1, n2));
                break;
            case 5: todasOperacoes(n1, n2); break;
        }
    } while(op != 0);
    return 0;
}

int leNumero() {
    int n;
    printf("Indique um valor inteiro: ");
    scanf("%d", &n);
    return n;
}
int soma(int a, int b) { return a + b; }
int subtracao(int a, int b) { return a - b; }
float raizQuadrada(int a) { return sqrt((float)a); }
int potencia(int base, int exp) { return pow((double)base, (double)exp); }
