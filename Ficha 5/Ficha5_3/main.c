#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

int menuPrincipal();
void inicializarQuartos(int quartos[], int n);
void estadoQuartos(int quartos[], int n);
int quartosNumEstado(int quartos[], int n, int estado);
int leQuarto(int quartos[], int n, int intencao);
 

int main()
{
    int quartos;
    int n = 10;
    int opcao;
    int q;
     
    inicializarQuartos(quartos, n);

    do
    {
        opcao = menuPrincipal();
        switch(opcao)
        {
        case 1:
            printf("\n--- Reservar ---\n");
            estadoQuartos(quartos, n);
            q = leQuarto(quartos, n, 0);
            quartos[q] = 1;
            printf("Quarto reservado com sucesso!\n");
            break;
        case 2:
            printf("\n--- Desmarcar reserva / desocupar ---\n");
            estadoQuartos(quartos, n);
            q = leQuarto(quartos, n, 1);
            quartos[q] = 0;
            printf("Reserva desmarcada com sucesso!\n");
            break;

        case 3:
            printf("\n--- Estado de ocupacoes ---\n");
            estadoQuartos(quartos, n);
            printf("\nTotal de quartos livres: %d\n", quartosNumEstado(quartos, n, 0));
            printf("Total de quartos ocupados: %d\n", quartosNumEstado(quartos, n, 1));
            break;

        case 0:
            printf("A sair do programa. Ate breve!\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
        }

    }
    while(opcao != 0);

} 

int menuPrincipal()
{
    int opcao;
    printf("\n1 - Reservar");
    printf("\n2 - Desmarcar reserva / desocupar");
    printf("\n3 - Ver estado de ocupacoes");
    printf("\n0 - Sair");
    printf("\n========================");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
} 

void inicializarQuartos(int quartos[], int n)
{
    for(int i = 0; i < n; i++)
    {
        quartos[i] = 0;
    }
} 

void estadoQuartos(int quartos[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(quartos[i] == 0)
        {
            printf("Quarto %d: Livre\n", i + 1);
        }
        else
        {
            printf("Quarto %d: Ocupado\n", i + 1);
        }
    }
} 

int quartosNumEstado(int quartos[], int n, int estado)
{
    int contador = 0;
    for(int i = 0; i < n; i++)
    {
        if(quartos[i] == estado)
        {
            contador++;
        }
    }
    return contador;
} 

int leQuarto(int quartos[], int n, int intencao)
{
    int numQuarto;
    bool pass;
     

    do
    {
        pass = false;
        printf("Insere o numero do quarto (1 a 10): ");
        scanf(" %d", &numQuarto);

        if(numQuarto > 10 || numQuarto < 1)
        {
            printf("Erro: Numero de quarto invalido!\n");
            pass = true;
        }
        else
        {

            int indice = numQuarto - 1;

            if(intencao == 0 && quartos[indice] == 1)
            {
                printf("Erro: Esse quarto ja esta ocupado!\n");
                pass = true;
            }
            if(intencao == 1 && quartos[indice] == 0)
            {
                printf("Erro: Esse quarto ja esta livre!\n");
                pass = true;
            }
        }

    }
    while(pass);

    return numQuarto - 1;

}
