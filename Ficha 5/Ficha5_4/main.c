#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void contarVogais(char *palavra);
void inverterString(char *palavra);
void removerEspacos(char *palavra);

int main()
{
    char palavra[100];

    printf("Insere uma frase: ");

    fgets(palavra, sizeof(palavra), stdin);


    palavra[strcspn(palavra, "\n")] = '\0';

    contarVogais(palavra);

    printf("A frase invertida: ");
    inverterString(palavra);
    printf("\n");

    removerEspacos(palavra);

    return 0;
}

void contarVogais(char *palavra)
{
    int cont = 0;
    for(int i = 0; palavra[i] != '\0'; i++)
    {
        char c = tolower(palavra[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            cont++;
        }
    }
    printf("A frase tem %d vogais\n", cont);
}

void inverterString(char *palavra)
{
    int inicio = 0;
    int fim = strlen(palavra) - 1;
    char temp;

    while (inicio < fim)
    {
        temp = palavra[inicio];
        palavra[inicio] = palavra[fim];
        palavra[fim] = temp;

        inicio++;
        fim--;
    }
    printf("%s", palavra);
}


void removerEspacos(char *palavra)
{
    int i = 0, j = 0;
    int espacosSuprimidos = 0;
    char semEspacos[100];

    while (palavra[i] != '\0')
    {
        if (palavra[i] == ' ')
        {
            espacosSuprimidos++;
        }
        else
        {
            semEspacos[j] = palavra[i];
            j++;
        }
        i++;
    }
    semEspacos[j] = '\0';

    printf("String sem espaços: %s\n", semEspacos);
    printf("Quantidade de espaços suprimidos: %d\n", espacosSuprimidos);
}
