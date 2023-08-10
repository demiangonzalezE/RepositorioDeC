#include <stdio.h>
#include <stdlib.h>

//EJERCICIO 6 Pedir que se ingrese un numero, de decir si cumple con que sea par y múltiplo de 5.

int main()
{
    int num;
    printf("Ingrese un numero por favor \n");
    scanf("%d", &num);

    if ((num%2)==0 || num%5==0 ){
        printf("Tu numero cumple con las condiciones\n");
    }
    else{printf("Tu numero no cumple las condiciones");}



    return 0;
}
