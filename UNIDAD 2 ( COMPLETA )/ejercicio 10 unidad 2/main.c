#include <stdio.h>
#include <stdlib.h>

/// EJERCICIO 10 Ingresar un año por teclado, una vez ingresado mostrar por pantalla, ESTE AÑO ES BISIESTO o ESTE AÑO NO ES BISIESTO.
int main()
{
    int anio;

    printf("Ingrese el anio:  \n");
    scanf("%d", &anio);

    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0){
        printf("ESTE ANIO ES BISIESTO ");
    }
    else{
        printf("ESTE ANIO NO ES BISIESTO ");
    }



    return 0;
}
