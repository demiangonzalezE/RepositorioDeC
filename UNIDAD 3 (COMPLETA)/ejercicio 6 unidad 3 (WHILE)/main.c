#include <stdio.h>
#include <stdlib.h>
///CON WHILE DETERMINAR SI UN NUMERO ES PRIMO O NO ...  ((NO LO ENTENDI LA VERDAD)) ME CUESTAN LOS NUMEROS PRIMOS!!!!
///1-Comienza con i igual a 1 y c igual a 0.
///2-En cada iteración, verifica si num es divisible por i (es decir, si num % i == 0).
///3-Si num es divisible por i, incrementa c en 1.
///4-Incrementa i en 1.
///5-Repite los pasos 2-4 hasta que i sea mayor que num.

int main()
{

    int i=1, num, c=0; ///c=cantidad de divisores i= los numeros de la tabla jojojo

    printf("Ingrese un numero:  \n");
    scanf("%d", &num);

        while(i <= num){

            if ( num % i == 0){

                c++;
            }
         i++;
        }

        if (c == 2){
            printf("Tu numero es Primo!!");
        }
        else{
            printf("Tu numero no es primo :(");
        }











    return 0;
}
