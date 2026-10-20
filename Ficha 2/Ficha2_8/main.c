#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n[3];
    char c1;
    int temp;
    for(int i = 0; i < 3; i++){
        printf("Insere um numero: ");
        scanf(" %i", &n[i]);
    }
    printf("crescente(c) ou decrescente(d): ");
    scanf(" %c", &c1);
    if (c1 == 'c'){
        if (n[0] > n[1]) { temp = n[0]; n[0] = n[1]; n[1] = temp; }
        if (n[1] > n[2]) { temp = n[1]; n[1] = n[2]; n[2] = temp; }
        if (n[0] > n[1]) { temp = n[0]; n[0] = n[1]; n[1] = temp; }
        printf("Resultado crescente: %i %i %i\n", n[0], n[1], n[2]);
    }
    else if (c1 == 'd'){
        if (n[0] < n[1]) { temp = n[0]; n[0] = n[1]; n[1] = temp; }
        if (n[1] < n[2]) { temp = n[1]; n[1] = n[2]; n[2] = temp; }
        if (n[0] < n[1]) { temp = n[0]; n[0] = n[1]; n[1] = temp; }

        printf("Resultado decrescente: %i %i %i\n", n[0], n[1], n[2]);
    }
    else {
        printf("Opção inválida!\n");
    }
}

