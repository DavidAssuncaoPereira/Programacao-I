#include <stdio.h>
#include <string.h>

// a) Estrutura dos estudantes
struct tipoEstudantes {
    int numero;
    char nome[50];
    char dataValidacao[50];
    int nota; // -1 indica que ainda nao foi avaliado
};

int lerinteiro();
float lerfloat();
void lerstring(char palavra[]);
char lerchar();
int procuraEstudante(struct tipoEstudantes estudantes[], int quant, int num);
struct tipoEstudantes lerDadosEstudante(struct tipoEstudantes estudantes[], int quant);
void lerData(char data[]);
void lerNotas(struct tipoEstudantes estudantes[], int quant);
int acrescentaAvaliado(struct tipoEstudantes estudantes[], int quant);
void mostrarDados(struct tipoEstudantes estudantes[], int quant);
void contas(struct tipoEstudantes estudantes[], int quant, int *avaliados, float *percPositivas);
char menu(int inseridos, int avaliados, float percPositivas);
void gravaFicheiroBinario(struct tipoEstudantes estudantes[], int quant);
int leFicheiroBinario(struct tipoEstudantes estudantes[]);
void gravaFicheiroTexto(struct tipoEstudantes estudantes[], int quant);

void main(void) {
    struct tipoEstudantes estudantes[100];
    int quantEstudantes = 0;
    int avaliados = 0;
    float percPositivas = 0.0;
    char opcao;

    do {

        contas(estudantes, quantEstudantes, &avaliados, &percPositivas);
        opcao = menu(quantEstudantes, avaliados, percPositivas);
        switch (opcao) {
            case 'A':
            case 'a':
                quantEstudantes = acrescentaAvaliado(estudantes, quantEstudantes);
                break;

            case 'I':
            case 'i':
                if (quantEstudantes == 0) {
                    printf("\nNao ha estudantes inseridos!\n");
                } else {
                    lerNotas(estudantes, quantEstudantes);
                }
                break;

            case 'M':
            case 'm':
                mostrarDados(estudantes, quantEstudantes);
                break;

            case 'G':
            case 'g':
                gravaFicheiroBinario(estudantes, quantEstudantes);
                gravaFicheiroTexto(estudantes, quantEstudantes);
                break;

            case 'L':
            case 'l':
                quantEstudantes = leFicheiroBinario(estudantes);
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
    scanf(" %c", &c); // O espaco antes de %c ignora eventuais enters anteriores
    return c;
}


int procuraEstudante(struct tipoEstudantes estudantes[], int quant, int num) {
    int i;
    for (i = 0; i < quant; i++) {
        if (estudantes[i].numero == num) {
            return i;
        }
    }
    return -1;
}

struct tipoEstudantes lerDadosEstudante(struct tipoEstudantes estudantes[], int quant) {
    struct tipoEstudantes novo;
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

    novo.nota = -1; // Ainda nao avaliado
    strcpy(novo.dataValidacao, "Sem data");

    return novo;
}

void lerData(char data[]) {
    printf("Digite a data (ex: DD/MM/AAAA): ");
    lerstring(data);
}

int acrescentaAvaliado(struct tipoEstudantes estudantes[], int quant) {
    if (quant >= 100) {
        printf("Limite maximo de 100 estudantes atingido!\n");
        return quant;
    }

    estudantes[quant] = lerDadosEstudante(estudantes, quant);
    quant++;
    printf("Estudante inserido com sucesso!\n");
    return quant;
}

void lerNotas(struct tipoEstudantes estudantes[], int quant) {
    char data[50];
    int i, querAvaliar;

    printf("\n--- Introducao de Notas ---\n");
    lerData(data);

    for (i = 0; i < quant; i++) {
        printf("Estudante %d (%s) foi avaliado? (1-Sim / 0-Nao): ", estudantes[i].numero, estudantes[i].nome);
        querAvaliar = lerinteiro();

        if (querAvaliar == 1) {
            do {
                printf("Digite a nota (0 a 20): ");
                estudantes[i].nota = lerinteiro();
            } while (estudantes[i].nota < 0 || estudantes[i].nota > 20);

            strcpy(estudantes[i].dataValidacao, data);
        }
    }
}

void mostrarDados(struct tipoEstudantes estudantes[], int quant) {
    int i;

    if (quant == 0) {
        printf("\nNao ha estudantes registados.\n");
        return;
    }

    printf("\n--- DADOS DOS ESTUDANTES ---\n");
    for (i = 0; i < quant; i++) {
        printf("Numero: %-5d | Nome: %-15s | Data: %-10s | ", estudantes[i].numero, estudantes[i].nome, estudantes[i].dataValidacao);
        if (estudantes[i].nota >= 0) {
            printf("Nota: %d\n", estudantes[i].nota);
        } else {
            printf("Nota: Sem Avaliacao\n");
        }
    }
}

void contas(struct tipoEstudantes estudantes[], int quant, int *avaliados, float *percPositivas) {
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

void gravaFicheiroBinario(struct tipoEstudantes estudantes[], int quant) {
    FILE *f = fopen("estudantes.dat", "wb");

    if (f == NULL) {
        printf("Erro ao abrir ficheiro binario para gravacao!\n");
        return;
    }


    fwrite(&quant, sizeof(int), 1, f);

    fwrite(estudantes, sizeof(struct tipoEstudantes), quant, f);

    fclose(f);
    printf("Dados gravados com sucesso em 'estudantes.dat'!\n");
}

int leFicheiroBinario(struct tipoEstudantes estudantes[]) {
    int quant = 0;
    FILE *f = fopen("estudantes.dat", "rb");

    if (f == NULL) {
        printf("Erro: Ficheiro binario 'estudantes.dat' nao encontrado!\n");
        return 0;
    }


    fread(&quant, sizeof(int), 1, f);

    fread(estudantes, sizeof(struct tipoEstudantes), quant, f);

    fclose(f);
    printf("Lidos %d estudantes com sucesso do ficheiro binario!\n", quant);
    return quant;
}

A
void gravaFicheiroTexto(struct tipoEstudantes estudantes[], int quant) {
    int i;
    FILE *f = fopen("estudantes.txt", "w");

    if (f == NULL) {
        printf("Erro ao abrir ficheiro de texto para escrita!\n");
        return;
    }

    fprintf(f, "LISTA DE ESTUDANTES (Total: %d)\n", quant);
    fprintf(f, "-------------------------------------------------------------\n");
    for (i = 0; i < quant; i++) {
        fprintf(f, "Numero: %d | Nome: %s | Data: %s | Nota: %d\n",
                estudantes[i].numero,
                estudantes[i].nome,
                estudantes[i].dataValidacao,
                estudantes[i].nota);
    }
    fprintf(f, "-------------------------------------------------------------\n");

    fclose(f);
    printf("Dados exportados com sucesso em 'estudantes.txt'!\n");
}