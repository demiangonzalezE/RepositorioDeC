#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;///Es el limite
    int termino1=0;
    int termino2=1;
    int sumadeterminos=0;
    int pos=2;

    printf ("Ingrese un numero: ");
    scanf("%d", &numero);

    if (numero == 0) {
        printf("La posicion del numero en la sucesion de Fibonacci es: 0\n");
    } else if (numero == 1) {
        printf("La posicion del numero en la sucesion de Fibonacci es: 1\n");
    }

    else {
        while (sumadeterminos < numero) {
            sumadeterminos = termino1 + termino2;
            termino1 = termino2;
            termino2 = sumadeterminos;
            pos++;
        }

        if (sumadeterminos == numero) {
            printf("La posicion del numero en la sucesion de Fibonacci es: %d\n", pos);
        } else {
            printf("El numero no se encuentra en la sucesion de Fibonacci.\n");
        }
    }








    return 0;

}

