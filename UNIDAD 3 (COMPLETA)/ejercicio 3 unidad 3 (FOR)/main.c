#include <stdio.h>
#include <stdlib.h>
///Pedir que se ingrese un numero por consola.
/// Una vez ingresado mostrar por pantalla, ES PRIMO o NO ES PRIMO.
///Recordar que un numero primo tiene solo dos divisores. (NEGATIVOS)

//NOTA: NO SE ENTIENDE MUY BIEN LA CONSIGNA, ME AYUDE DE CHATGPT PORQUE NO PODIA ENCONTRAR LA FORMA.


int main()
{
    int numero;
    int esPrimo;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

     if (numero < 2) {
        esPrimo = 0;
    } else {
        for (int i = 2; i < numero; i++) {
            if (numero % i == 0) {
                esPrimo = 0;
                break;
            }
        }
    }

    if (esPrimo) {
        printf("ES PRIMO\n");
    } else {
        printf("NO ES PRIMO\n");
    }








    return 0;
}
