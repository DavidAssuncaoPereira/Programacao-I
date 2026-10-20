#include <stdio.h>

int obtemNumero;
int somaFor(int n);
int somaWhile(int n);
int somaDoWhile(int n);
char menuSomas(int cFor, int cWhile, int cDo);

int main() {
    int n, cFor = 0, cWhile = 0, cDo = 0;
    char op;

    do {
        op = menuSomas(cFor, cWhile, cDo);
        if (op >= '1' && op <= '3') n = obtemNumero();

        switch(op) {
            case '1': printf("Soma = %d\n", somaFor(n)); cFor++; break;
            case '2': printf("Soma = %d\n", somaWhile(n)); cWhile++; break;
            case '3': printf("Soma = %d\n", somaDoWhile(n)); cDo++; break;
        }
    } while (op != '4');
    return 0;
}

int obtemNumero() {
    int n;
    do {
        printf("Introduza um limite positivo: ");
        scanf("%d", &n);
    } while (n <= 0);
    return n;
}
int somaFor(int n) {
    int soma = 0;
    for(int i = 1; i <= n; i++) soma += i;
    return soma;
}
int somaWhile(int n) {
    int soma = 0, i = 1;
    while(i <= n) { soma += i; i++; }
    return soma;
}
int somaDoWhile(int n) {
    int soma = 0, i = 1;
    do { soma += i; i++; } while(i <= n);
    return soma;
}
char menuSomas(int cFor, int cWhile, int cDo) {
    char op;
    printf("\nUso: For(%d) While(%d) Do-While(%d)\n", cFor, cWhile, cDo);
    printf("1. Ciclo For\n2. Ciclo While\n3. Ciclo Do-While\n4. Sair\nOpcao: ");
    scanf(" %c", &op);
    return op;
}
