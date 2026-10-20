#include <stdio.h>

float definirLimiteSeguranca(int seg);
float analisarCaudalFronteira(float limite);
void verficarPluviosidade(float caudalMedio, float limite);
int menu();

int main(void)
{
    int op;
    float limite =0;
    float caudalMedio=0;
    int limiteDefenido=0;

    do{
        op=menu();
        switch(op){
            case 1:
                limite=definirLimiteSeguranca(limite);
                limiteDefenido=1;
            break;
            case 2:
                if(limiteDefenido)
                    caudalMedio=analisarCaudalFronteira(limite);
                else
                    printf("Defina primeiro o Limite\n");
            break;
            case 3: if (limiteDefenido && caudalMedio >0)
                verficarPluviosidade(caudalMedio, limite);
                else
                    printf("Tem de definir as variaveis");
            break;
        }
    }while(op != 0);
}

int menu(){
    int op;
    printf("---Gestao do Rio---\n");
    printf("1. Definir limite\n");
    printf("2. Analisar Cauldal\n");
    printf("3. Verificar Pluvisiolidade\n");
    printf("0. Sair\n");
    printf("Opcao: ");
    scanf(" %d", &op);
    return op;
}

float definirLimiteSeguranca(int seg){
    float limite;
    printf("Insira o limitede seguranca para o caldal: ");
    scanf(" %f", &limite);
    return limite;}

float analisarCaudalFronteira(float limite){
    float cauda, soma, media;

    for (int i=1;i <=5;i++){
        printf("Introduza a medicao %d (m3/s):",i);
        scanf(" %f", &cauda);
        soma += cauda;
    }
    media = soma / 5;
    printf("\nCaudal media calculado: %.2f m3/s\n", media);

    if (media > limite) {
        printf("Atencao: O Caudal ultropassou o limite:");
    }
    else
        printf("O Caudal esta dentro do limite");
    return media;
}
void verficarPluviosidade(float caudalMedio, float limite){
    if (caudalMedio>limite){
        float p1,p2,p3;
        printf("Mediacao 1:"); scanf(" %f", &p1);
        printf("Mediacao 2:"); scanf(" %f", &p2);
        printf("Mediacao 3:"); scanf(" %f", &p3);
        if ( p1 == 0 && p2== 0 && p3 == 0)
            printf("\nAtencao: Caudal elevado mas sem pluviosidade.\n");
        else
            printf("\nAtencao: Cauldal elevado e preseca de pulviosidade.\n");
    }
    else
        printf("Verificacao desnecessaria: o caudal esta controlado.\n");

}
