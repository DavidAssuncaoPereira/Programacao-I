#include <stdio.h>


void obterPercurso(float *distancia, float *montante);
float precoCombustivel(int tipo) ;
float litrosConsumidos(float montante, float precoLitro);
char menuViatura();

int main() {
    char op;
    int tipo;
    float dist, montante, preco, litros;
    float distTotal = 0, litrosTotais = 0;

    do {
        op = menuViatura();

        if (op == 'I' || op == 'i') {
            obterPercurso(&dist, &montante);
            printf("Tipo de combustivel (1, 2 ou 3): ");
            scanf("%d", &tipo);

            preco = precoCombustivel(tipo);
            litros = litrosConsumidos(montante, preco);

            distTotal += dist;
            litrosTotais += litros;
            printf("Percurso registado!\n");

        } else if (op == 'C' || op == 'c') {
            if (distTotal > 0) {
                float consumoMedio = (litrosTotais * 100) / distTotal;
                printf("Consumo medio atual: %.2f L/100Km\n", consumoMedio);
            } else {
                printf("Ainda nao existem percursos registados.\n");
            }
        }
    } while (op != 'T' && op != 't');

    return 0;
}

void obterPercurso(float *distancia, float *montante) {
    printf("Distancia percorrida (Km): ");
    scanf("%f", distancia);
    printf("Montante despendido (Euros): ");
    scanf("%f", montante);
}

float precoCombustivel(int tipo) {
    switch (tipo) {
        case 1: return 1.55;
        case 2: return 1.65;
        case 3: return 1.80;
        default: return 0.0;
    }
}

float litrosConsumidos(float montante, float precoLitro) {
    if(precoLitro == 0) return 0;
    return montante / precoLitro;
}

char menuViatura() {
    char op;
    printf("\n(I)Introduzir percurso\n(C)Consumo medio\n(T)Terminar\nOpcao: ");
    scanf(" %c", &op);
    return op;
}
