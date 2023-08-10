#include <stdio.h>
#include <stdlib.h>

///EJERCICIO 7 Pedir dos números, mostrar por pantalla el mayor de ellos
int main()
{
   int num1;
   int num2;

    printf("Ingrese el primer numero\n");
        scanf("%d", &num1);

    printf("Ingrese el segundo numero\n\n");
        scanf("%d", &num2);

        if(num1 < num2){
                printf("El segundo numero es el mayor");
            }
            else { printf("El primer numero es el mayor");
            }
    return 0;
}
