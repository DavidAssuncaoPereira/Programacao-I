#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct avaliacao {
    char nome[50];
    int nota;
};

int menu();
int lerQuantidadeAvaliados();
void lerNotas(struct avaliacao turma[], int n);
void mostrarDados(struct avaliacao turma[], int n);
void calculaMedia(struct avaliacao turma[], int n);
void notasPositivas(struct avaliacao turma[], int n);
void alteraNota(struct avaliacao turma[], int n);

int main() {
    struct avaliacao turma[25];
    int n = 0;
    int opcao;
    int notasInseridas = 0;

    do {
        opcao=menu();
        switch(opcao) {
            case 1:
                n = lerQuantidadeAvaliados();
                lerNotas(turma, n);
                notasInseridas = 1;


            break;

            case 2:
                if (notasInseridas) {
                    mostrarDados(turma, n);
                } else {
                    printf("Aviso: Precisa de introduzir dados primeiro (Opcao 1).\n");
                }
                break;

            case 3:
                if (notasInseridas) {
                    calculaMedia(turma, n);
                } else {
                    printf("Aviso: Precisa de introduzir dados primeiro (Opcao 1).\n");
                }
                break;
            case 4:
                if (notasInseridas) {

                } else {
                    printf("Aviso: Precisa de introduzir dados primeiro (Opcao 1).\n");
                }
                break;
            case 5:
                if (notasInseridas) {
                    notasPositivas(turma, n);
                } else {
                    printf("Aviso: Precisa de introduzir dados primeiro (Opcao 1).\n");
                }
                break;

            case 0:
                printf("A sair do programa. Ate breve!\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
}
int menu(){
    int opcao;
        printf("\n1 - Introduzir dados dos estudantes");
        printf("\n2 - Mostrar todas as notas");
        printf("\n3 - Calcular a media da turma");
        printf("\n4 - Alterar nota de um estudante");
        printf("\n5 - Mostrar alunos com nota positiva");
        printf("\n0 - Sair");
        printf("\n========================");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        return opcao;
}
int lerQuantidadeAvaliados() {
    int n;
    bool pass = false;
    do{
    printf("Insere o numero de estudantes: ");
    scanf(" %d", &n);
    if(n>25 || n<0)
        pass=true;
    }while(pass);
    return n;
}

void lerNotas(struct avaliacao turma[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Insere o nome do aluno %d: ", i + 1);
        scanf(" %s", turma[i].nome);
        printf("Insere a nota do aluno %d: ", i + 1);
        scanf(" %d", &turma[i].nota);
    }
}

void mostrarDados(struct avaliacao turma[], int n) {

    for(int i = 0; i < n; i++) {
        printf("O %s teve %d\n", turma[i].nome, turma[i].nota);
    }
}

void calculaMedia(struct avaliacao turma[], int n) {

    int soma = 0;
    for(int i = 0; i < n; i++) {
        soma += turma[i].nota;
    }
    float media = (float)soma / n;
    printf("A media e de: %.2f\n", media);
}

void notasPositivas(struct avaliacao turma[], int n) {

    printf("Alunos com nota positiva:\n");
    for(int i = 0; i < n; i++) {
        if(turma[i].nota >= 10) {
            printf("O aluno %s teve a nota %d\n", turma[i].nome, turma[i].nota);
        }
    }
}
void alteraNota(struct avaliacao turma[], int n){
    int alt;
    printf("Insere o numero do aluno que quer aleterar: ");
    scanf(" %d",&alt);
    alt--;
    printf("Insere a nota: ");
    scanf(" %d",&turma[alt].nota);
}

