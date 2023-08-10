#include <stdio.h>
#include <stdlib.h>




/// EJERCICIO 12  Pedir por pantalla 3 números flotantes, calcular el promedio de estos tres números.


int main()
{

float num1, num2, num3, promedio;

    printf("ingrese 1er numero: \n");
    scanf("%f",&num1);

    printf("\nIngrese 2do numero: \n");
    scanf("%f",&num2);

    printf("\nIngrese 3er numero \n");
    scanf("%f",&num3);


    promedio =(num1 + num2 + num3) / 3;

   printf("\nSu promedio es: %.2f", promedio);






    return 0;
}
