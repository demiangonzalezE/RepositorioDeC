#include <stdio.h>
#include <stdlib.h>

//Un usuario debe tipear 20 números enteros.
//Calcular la suma de los números pares,
//el producto de los impares.
//Calcular la media de los números mayores a 5. // me me faltan estos ultimos dos pero la idea de como usar for esta :))
//Y el promedio de los números mayores a 20.


int main()
{
    int numeros;
    int sumaPares = 0;
    int producto = 1;

    for (int i = 0; i<5; i++ ){
            printf("Ingrese 20 numeros enteros: ");
            scanf("%d",&numeros);

             if (numeros % 2 == 0){

                sumaPares+=numeros;
                }
             if(numeros % 2 == 1){
                producto*=numeros;
             }
    }

    printf("\nLa suma de los numeros pares es: %d", sumaPares );

    printf("\nEl producto de los numeros impares es:  %d", producto );

















 return 0;
}


