#include <stdio.h>
#include <stdlib.h>

int lerNumero();
int areaRetangulo(int n1, int n2);

int main()
{
    int l1,l2;
    int area;

    l1= lerNumero();
    l2= lerNumero();

    area=areaRetangulo(l1,l2);

    printf("A area e %d",area);
}

int areaRetangulo(int n1, int n2){
    int area;

    area=n1*n2;

    return area;
}

int lerNumero(){
    int n;

    printf("Insere o valor de um lado: ");
    scanf(" %d", &n);

    return n;
}
