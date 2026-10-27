#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    char nome[50];
    int dia, mes, ano;
    int nota;
} tipoEstudantes;

int lerinteiro();
float lerfloat();
void lerstring(char palavra[]);
char lerchar();
int lerQuantidadeEstudante(tipoEstudantes estudantes[]);
int procuraEstudante(tipoEstudantes estudantes[], int quant, int num);
tipoEstudantes lerDadosEstudante(tipoEstudantes estudantes[], int quant);
void lerNotas(tipoEstudantes estudantes[], int quant);
void mostrarDados(tipoEstudantes estudantes[], int quant);
int acrescentaAvaliado(tipoEstudantes estudantes[], int quant);
char menu(int inseridos, int avaliados, float percPositivas);
void contas(tipoEstudantes estudantes[], int quant, int *avaliados, float *percPositivas);
void gravaFicheiroBinario(tipoEstudantes estudantes[], int quant);
void gravaFicheiroTexto(tipoEstudantes estudantes[], int quant);
int leFicheiroBinario(tipoEstudantes estudantes[]);

void main(void) {
    tipoEstudantes estudantes[100] = {0};
    int quantEstudante = lerQuantidadeEstudante(estudantes);
    int avaliados = 0;
    float percPositivas = 0.0;
    char opcao;

    do {
         contas(estudantes, quantEstudante, &avaliados, &percPositivas);
         opcao = menu(quantEstudante, avaliados, percPositivas);
ss
         switch (opcao) {
            case 'A':
            case 'a':
                quantEstudante = acrescentaAvaliado(estudantes, quantEstudante);
                break;

            case 'I':
            case 'i':
                if (quantEstudante == 0) {
                    printf("\nNao ha estudantes inseridos!\n");
                } else {
                    lerNotas(estudantes, quantEstudante);
                }
                break;

            case 'M':
            case 'm':
                mostrarDados(estudantes, quantEstudante);
                break;

            case 'G':
            case 'g':
                gravaFicheiroBinario(estudantes, quantEstudante);
                gravaFicheiroTexto(estudantes, quantEstudante);
                break;

            case 'L':
            case 'l':
                quantEstudante = leFicheiroBinario(estudantes);
                break;

            case 'F':
            case 'f':
                printf("\nA terminar o programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 'F' && opcao != 'f');
}

int lerinteiro() {
    int numero;
    scanf("%d", &numero);
    return numero;
}

float lerfloat() {
    float numero;
    printf("Digite o valor: ");
    scanf("%f", &numero);
    return numero;
}

void lerstring(char palavra[]) {
    scanf("%s", palavra);
}

char lerchar() {
    char c;
    scanf(" %c", &c);
    return c;
}

int lerQuantidadeEstudante(tipoEstudantes estudantes[]){
    int quant = 0;
    for(int i = 0; i < 100; i++){
        if(estudantes[i].numero != 0)
            quant += 1;
    }
    return quant;
}

int procuraEstudante(tipoEstudantes estudantes[], int quant, int num) {
    int i;
    for (i = 0; i < quant; i++) {
         if (estudantes[i].numero == num) {
             return i;
         }
    }
    return -1;
}

tipoEstudantes lerDadosEstudante(tipoEstudantes estudantes[], int quant) {
    tipoEstudantes novo;
    int existe;

    do {
        printf("Digite o numero do estudante (1 a 9999): ");
        novo.numero = lerinteiro();

        existe = procuraEstudante(estudantes, quant, novo.numero);
        if (existe != -1) {
            printf("Numero repetido! Tente novamente.\n");
        }
    } while (novo.numero < 1 || novo.numero > 9999 || existe != -1);

    printf("Digite o nome: ");
    lerstring(novo.nome);

    novo.nota = -1;
    novo.dia = 0;
    novo.mes = 0;
    novo.ano = 0;

    return novo;
}

void lerNotas(tipoEstudantes estudantes[], int quant) {
    int i, querAvaliar;

    printf("\n--- Introducao de Notas ---\n");

    for (i = 0; i < quant; i++) {
        printf("Estudante %d (%s) foi avaliado? (1-Sim / 0-Nao): ", estudantes[i].numero, estudantes[i].nome);
        querAvaliar = lerinteiro();

        if (querAvaliar == 1) {
            do {
                printf("Digite a nota (0 a 20): ");
                estudantes[i].nota = lerinteiro();
            } while (estudantes[i].nota < 0 || estudantes[i].nota > 20);

            printf("Insere o dia da avaliacao: ");
            estudantes[i].dia = lerinteiro();
            printf("Insere o mes da avaliacao: ");
            estudantes[i].mes = lerinteiro();
            printf("Insere o ano da avaliacao: ");
            estudantes[i].ano = lerinteiro();
        }
    }
}

void mostrarDados(tipoEstudantes estudantes[], int quant) {
    int i;

    if (quant == 0) {
        printf("\nNao ha estudantes registados.\n");
        return;
    }

    printf("\n--- DADOS DOS ESTUDANTES ---\n");
    for (i = 0; i < quant; i++) {
        printf("Numero: %-5d | Nome: %-15s | ", estudantes[i].numero, estudantes[i].nome);
        if (estudantes[i].nota >= 0) {
            printf("Data Avaliacao: %02d/%02d/%04d | Nota: %d\n",
                   estudantes[i].dia, estudantes[i].mes, estudantes[i].ano, estudantes[i].nota);
        } else {
            printf("Data Avaliacao: --/--/---- | Nota: Sem Avaliacao\n");
        }
    }
}

int acrescentaAvaliado(tipoEstudantes estudantes[], int quant) {
    if (quant >= 100) {
        printf("Limite maximo de 100 estudantes atingido!\n");
        return quant;
    }

    estudantes[quant] = lerDadosEstudante(estudantes, quant);

    quant++;
    printf("Estudante inserido com sucesso!\n");
    return quant;
}

char menu(int inseridos, int avaliados, float percPositivas) {
    char op;

    printf("\n**************************************************\n");
    printf("** Menu Principal                               **\n");
    printf("**************************************************\n");
    printf("** Estudantes Inseridos: %-22d **\n", inseridos);
    printf("** Estudantes Avaliados: %-22d **\n", avaliados);
    printf("** Notas Positivas (%%): %-23.2f **\n", percPositivas);
    printf("**************************************************\n");
    printf("  A - Acrescenta Estudante\n");
    printf("  I - Introducao Notas\n");
    printf("  M - Mostrar Dados\n");
    printf("  G - Gravar dados em ficheiros\n");
    printf("  L - Ler dados de ficheiro\n");
    printf("  F - Fim\n");
    printf("Opcao--> ");

    op = lerchar();
    return op;
}

void contas(tipoEstudantes estudantes[], int quant, int *avaliados, float *percPositivas) {
    int i;
    int contaAvaliados = 0;
    int contaPositivas = 0;

    for (i = 0; i < quant; i++) {
        if (estudantes[i].nota >= 0) {
            contaAvaliados++;
            if (estudantes[i].nota >= 10) {
                contaPositivas++;
            }
        }
    }

    *avaliados = contaAvaliados;

    if (contaAvaliados > 0) {
        *percPositivas = ((float)contaPositivas / contaAvaliados) * 100.0;
    } else {
        *percPositivas = 0.0;
    }
}

void gravaFicheiroBinario(tipoEstudantes estudantes[], int quant) {
    FILE *f = fopen("estudantes.dat", "wb");

    if (f == NULL) {
        printf("Erro ao abrir ficheiro binario para gravacao!\n");
        return;
    }

    fwrite(&quant, sizeof(int), 1, f);
    fwrite(estudantes, sizeof(tipoEstudantes), quant, f);

    fclose(f);
    printf("Dados gravados com sucesso em 'estudantes.dat'!\n");
}

void gravaFicheiroTexto(tipoEstudantes estudantes[], int quant) {
    int i;
    FILE *f = fopen("estudantes.txt", "w");

    if (f == NULL) {
        printf("Erro ao abrir ficheiro de texto para escrita!\n");
        return;
    }

    fprintf(f, "LISTA DE ESTUDANTES (Total: %d)\n", quant);
    fprintf(f, "-------------------------------------------------------------\n");

    for (i = 0; i < quant; i++) {
        if (estudantes[i].nota >= 0) {
            fprintf(f, "Numero: %d | Nome: %s | Data Avaliacao: %02d/%02d/%d | Nota: %d\n",
                    estudantes[i].numero,
                    estudantes[i].nome,
                    estudantes[i].dia,
                    estudantes[i].mes,
                    estudantes[i].ano,
                    estudantes[i].nota);
        } else {
            fprintf(f, "Numero: %d | Nome: %s | Data Avaliacao: Sem Avaliacao | Nota: Sem Avaliacao\n",
                    estudantes[i].numero,
                    estudantes[i].nome);
        }
    }

    fprintf(f, "-------------------------------------------------------------\n");
    fclose(f);

    printf("Dados exportados com sucesso em estudantes.txt !\n");
}

int leFicheiroBinario(tipoEstudantes estudantes[]) {
    int quant = 0;
    FILE *f = fopen("estudantes.dat", "rb");

    if (f == NULL) {
        printf("Erro: Ficheiro binario 'estudantes.dat' nao encontrado!\n");
        return 0;
    }

    fread(&quant, sizeof(int), 1, f);
    fread(estudantes, sizeof(tipoEstudantes), quant, f);

    fclose(f);
    printf("Lidos %d estudantes com sucesso do ficheiro binario!\n", quant);
    return quant;
}
