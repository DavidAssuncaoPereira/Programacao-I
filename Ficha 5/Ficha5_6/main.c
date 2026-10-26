#include <stdio.h>

#define MAX_ATLETAS 20
#define TOTAL_CORRIDAS 6


void ler_tempo_atletas_corrida(int numAtletas, int corridaIdx, int dorsais[], float tempos[][TOTAL_CORRIDAS]) {
    printf("\n--- Registo de Tempos da Corrida %d ---\n", corridaIdx + 1);
    for (int i = 0; i < numAtletas; i++) {
        do {
            printf("Tempo do atleta dorsal %d (segundos): ", dorsais[i]);
            scanf("%f", &tempos[i][corridaIdx]);
        } while (tempos[i][corridaIdx] <= 0.0f);
    }
}


void mostrar(int numAtletas, int dorsais[], float tempos[][TOTAL_CORRIDAS]) {
    printf("\n=== Tabela Geral de Tempos (s) ===\n");
    printf("Atleta ");
    for (int c = 0; c < TOTAL_CORRIDAS; c++) {
        printf("| Corr. %d ", c + 1);
    }
    printf("\n--------------------------------------------------------------\n");

    for (int i = 0; i < numAtletas; i++) {
        printf("Nº %-4d", dorsais[i]);
        for (int c = 0; c < TOTAL_CORRIDAS; c++) {
            printf("| %7.2f ", tempos[i][c]);
        }
        printf("\n");
    }
}

void media_corrida(int numAtletas, int corridaIdx, float tempos[][TOTAL_CORRIDAS]) {
    float soma = 0.0f;
    for (int i = 0; i < numAtletas; i++) {
        soma += tempos[i][corridaIdx];
    }
    printf("Tempo medio da Corrida %d: %.2f segundos\n", corridaIdx + 1, soma / numAtletas);
}


int vencedor_corrida(int numAtletas, int corridaIdx, int dorsais[], float tempos[][TOTAL_CORRIDAS]) {
    int melhorIdx = 0;
    for (int i = 1; i < numAtletas; i++) {
        if (tempos[i][corridaIdx] < tempos[melhorIdx][corridaIdx]) {
            melhorIdx = i;
        }
    }
    printf("Vencedor da Corrida %d -> Atleta nº %d com %.2fs\n", 
           corridaIdx + 1, dorsais[melhorIdx], tempos[melhorIdx][corridaIdx]);
    return melhorIdx;
}


void vencedor_campeonato(int numAtletas, int dorsais[], float tempos[][TOTAL_CORRIDAS]) {
    int vitorias[MAX_ATLETAS] = {0};
    float temposTotais[MAX_ATLETAS] = {0.0f};

    
    for (int c = 0; c < TOTAL_CORRIDAS; c++) {
        int vIdx = 0;
        for (int i = 1; i < numAtletas; i++) {
            if (tempos[i][c] < tempos[vIdx][c]) {
                vIdx = i;
            }
        }
        vitorias[vIdx]++;
    }

    
    for (int i = 0; i < numAtletas; i++) {
        for (int c = 0; c < TOTAL_CORRIDAS; c++) {
            temposTotais[i] += tempos[i][c];
        }
    }

    
    int campeao = 0;
    for (int i = 1; i < numAtletas; i++) {
        if (vitorias[i] > vitorias[campeao]) {
            campeao = i;
        } else if (vitorias[i] == vitorias[campeao]) {
            if (temposTotais[i] < temposTotais[campeao]) {
                campeao = i;
            }
        }
    }

    printf("\n=========================================\n");
    printf("VENCEDOR DO CAMPEONATO: Atleta nº %d\n", dorsais[campeao]);
    printf("Numero de Vitorias: %d\n", vitorias[campeao]);
    printf("Tempo Total: %.2fs\n", temposTotais[campeao]);
    printf("=========================================\n");
}

int main() {
    
    int dorsais[MAX_ATLETAS];
    float tempos[MAX_ATLETAS][TOTAL_CORRIDAS];

    int numAtletas;
    do {
        printf("Numero de atletas participantes (1 a %d): ", MAX_ATLETAS);
        scanf("%d", &numAtletas);
    } while (numAtletas < 1 || numAtletas > MAX_ATLETAS);

    
    printf("\n--- Registo de Dorsais ---\n");
    for (int i = 0; i < numAtletas; i++) {
        printf("Dorsal do atleta %d: ", i + 1);
        scanf("%d", &dorsais[i]);
    }

    
    for (int c = 0; c < TOTAL_CORRIDAS; c++) {
        ler_tempo_atletas_corrida(numAtletas, c, dorsais, tempos);
    }

    mostrar(numAtletas, dorsais, tempos);

    
    printf("\n=== Estatisticas por Corrida ===\n");
    for (int c = 0; c < TOTAL_CORRIDAS; c++) {
        media_corrida(numAtletas, c, tempos);
        vencedor_corrida(numAtletas, c, dorsais, tempos);
    }

    vencedor_campeonato(numAtletas, dorsais, tempos);

    return 0;
}