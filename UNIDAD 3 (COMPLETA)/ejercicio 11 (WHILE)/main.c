#include <stdio.h>
#include <stdlib.h>

///Calcular el valor medio de los n�meros que tipea el usuario. El usuario deja de tipear n�meros cuando ingresa un 0.


int main() {
    int numeros;
    int cantnum = 0;
    float suma = 0.0;

    printf("Ingrese numeros (0 para mostrar y salir):\n");

    while (1) {
        printf("Ingrese un n�mero: ");
        scanf("%d", &numeros);

        if (numeros == 0) {
            break;
        }

        suma += numeros; // Acumulamos la suma de los n�meros ingresados
        cantnum++; // Incrementamos la cantidad de n�meros ingresados
    }

    if (cantnum == 0) {
        printf("No se ingresaron numeros.\n");
    } else {
        float media = suma / cantnum; // Calculamos el valor medio
        printf("El valor medio de los numeros ingresados: %f\n", media);
    }














    return 0;
}
