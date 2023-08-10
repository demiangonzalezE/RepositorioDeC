#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numero;
    int binario = 0;
    int factor = 1;

    printf("Ingrese un numero decimal: ");
    scanf("%d", &numero);

    while (numero > 0) {
        int bit = numero % 2;
        binario += bit * factor;
        numero /= 2;
        factor *= 10;
    }

    printf("El número en binario es: %d\n", binario);
    return 0;
}
