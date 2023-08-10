#include <stdio.h>
#include <stdlib.h>


///EJERCICIO 8 Pedir por pantalla 3 números, mostrar los 3 números de mayor a menor.


int main()
{
    int num1,num2,num3;

    printf("Ingrese el 1er numero\n");
    scanf("%d", &num1);

    printf("Ingrese el 2do numero\n");
    scanf("%d", &num2);

    printf("Ingrese el 3er numero\n");
    scanf("%d", &num3);


     if (num1 > num2 && num1 > num3) {
        if (num2 > num3) {
            printf("Orden: %d, %d, %d\n", num1, num2, num3);
        } else {
            printf("Orden: %d, %d, %d\n", num1, num3, num2);
        }
     }

        else if (num2 > num1 && num2 > num3){
            if (num1>num3){
                printf("orden: %d,%d,%d\n", num2, num1, num3);
            }
            else{
                printf("Orden: %d, %d, %d\n", num2,num3,num1);
            }
        }

        else if (num3 > num1 && num3 > num3){
            if (num1>num2){
                printf("Orden: %d, %d, %d\n", num3,num1,num2);
            }

            else{
                printf("Orden: %d, %d, %d\n", num3,num2,num1);
            }

        }









    return 0;
}
