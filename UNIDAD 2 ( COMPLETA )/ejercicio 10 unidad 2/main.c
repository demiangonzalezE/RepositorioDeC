#include <stdio.h>
#include <stdlib.h>

/// EJERCICIO 10 Ingresar un a�o por teclado, una vez ingresado mostrar por pantalla, ESTE A�O ES BISIESTO o ESTE A�O NO ES BISIESTO.
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
