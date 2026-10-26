#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 150


void escreverIniciais(const char nome[]) {
    printf("Iniciais: ");
    int novaPalavra = 1;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (isspace(nome[i])) {
            novaPalavra = 1;
        } else if (novaPalavra) {
            putchar(toupper(nome[i]));
            putchar('.');
            novaPalavra = 0;
        }
    }
    putchar('\n');
}


int contarPalavras(const char nome[]) {
    int total = 0;
    int dentroDePalavra = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isspace(nome[i])) {
            if (!dentroDePalavra) {
                total++;
                dentroDePalavra = 1;
            }
        } else {
            dentroDePalavra = 0;
        }
    }
    return total;
}


void formatarApelidoNome(const char nome[]) {
    int tam = strlen(nome);
    int fimUltima = tam - 1;

    
    while (fimUltima >= 0 && isspace(nome[fimUltima])) {
        fimUltima--;
    }

    if (fimUltima < 0) {
        printf("Nome vazio!\n");
        return;
    }

    
    int iniUltima = fimUltima;
    while (iniUltima >= 0 && !isspace(nome[iniUltima])) {
        iniUltima--;
    }
    iniUltima++; 

    
    printf("Formato (Apelido, Nome): ");
    for (int i = iniUltima; i <= fimUltima; i++) {
        putchar(nome[i]);
    }

    
    int iniPrimeiro = 0;
    while (isspace(nome[iniPrimeiro])) {
        iniPrimeiro++;
    }

    if (iniPrimeiro < iniUltima) {
        printf(", ");
        
        int fimAnterior = iniUltima - 1;
        while (fimAnterior >= 0 && isspace(nome[fimAnterior])) {
            fimAnterior--;
        }
        for (int i = iniPrimeiro; i <= fimAnterior; i++) {
            putchar(nome[i]);
        }
    }
    putchar('\n');
}

int main() {
    char nomeCompleto[MAX_NOME];

    printf("Introduza o seu nome completo: ");
    fgets(nomeCompleto, MAX_NOME, stdin);
    nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0';

    escreverIniciais(nomeCompleto);
    printf("Total de palavras: %d\n", contarPalavras(nomeCompleto));
    formatarApelidoNome(nomeCompleto);

    return 0;
}