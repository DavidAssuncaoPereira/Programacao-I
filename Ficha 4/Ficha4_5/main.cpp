#include <stdio.h>
#include <math.h>

int binomioDiscriminante(int a, int b, int c);
int numDeZerosReais(int a, int b, int c, float *r1, float *r2);

int main() {
    int a, b, c, numRaizes;
    float raiz1, raiz2;
    printf("Introduza coeficientes a, b, c (a!=0): ");
    scanf("%d %d %d", &a, &b, &c);

    if (a == 0) {
        printf("O coeficiente 'a' tem de ser diferente de 0!\n");
        return 1;
    }

    numRaizes = numDeZerosReais(a, b, c, &raiz1, &raiz2);

    if (numRaizes == 0) {
        printf("A equacao tem raizes imaginarias.\n");
    } else if (numRaizes == 1) {
        printf("A equacao tem uma raiz (zero duplo): %.2f\n", raiz1);
    } else {
        printf("A equacao tem duas raizes reais: %.2f e %.2f\n", raiz1, raiz2);
    }

    return 0;
}
int binomioDiscriminante(int a, int b, int c) {
    return (b * b) - (4 * a * c);
}

int numDeZerosReais(int a, int b, int c, float *r1, float *r2) {
    int delta = binomioDiscriminante(a, b, c);
    int r;
    if (delta < 0) {
        r=0;
    } else if (delta == 0) {
        *r1 = (float)-b / (2 * a);
        r=1;
    } else {
        *r1 = (-b + sqrt(delta)) / (2 * a);
        *r2 = (-b - sqrt(delta)) / (2 * a);
        r=2;
    }
    return r;
}
