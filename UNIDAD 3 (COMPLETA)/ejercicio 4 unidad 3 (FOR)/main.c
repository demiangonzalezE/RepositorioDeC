#include <stdio.h>
#include <stdlib.h>

///  Pedir que se ingrese un numero por teclado. Calcular el factorial del numero.

int main()
{

    int num,factorial;


    factorial = 1;


   printf("ingresar numero: \n");
   scanf("%d", &num);


    for (int i = 1; i<= num; i++){
        factorial = factorial*i;

   }

    printf("%d", factorial);





    return 0;
}
