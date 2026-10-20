#include <stdio.h>
#include <stdlib.h>

int menu(){
    int c;
    printf("Menu\t\t|\tpreco\n\t\t|\n1-Prego\t\t|\t2.40€\n2-Cachorro\t|\t1.00€\n3-Batatas\t|\t1.80€\n4-Bolo\t\t|\t0.50€\n5-Sumo\t\t|\t0.60€\n0-Acabar\n");
    scanf(" %i", &c);
    return c;

}

void main()
{
    int c;
    int Prego=0, Cachorro=0, Batata=0, Bolo=0, Sumo=0;
    float Total;
    do{
        c=menu();
        switch(c){
        case 1: Prego++; printf("Prego adicionado \n"); break;
        case 2: Cachorro++; printf("Cachorro adicionado \n"); break;
        case 3: Batata++; printf("Batata adicionado \n"); break;
        case 4: Bolo++; printf("Bolo adicionado \n"); break;
        case 5: Sumo++; printf("Sumo adicionado \n"); break;
        case 0: printf("Prego\t -\t %i\nCachorro -\t %i\nBatata\t -\t %i\nBolo\t -\t %i\nSumo\t -\t %i\n",Prego,Cachorro, Batata, Bolo, Sumo); Total=Prego*2.4+Cachorro*1+Batata*1.8+Bolo*0.5+Sumo*0.60; printf("Total: %.2f",Total); break;
        default: printf("Opcao invalida");break}

    }while(c!=0);

}
