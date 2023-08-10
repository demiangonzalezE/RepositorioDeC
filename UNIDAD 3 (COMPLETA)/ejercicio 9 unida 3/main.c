#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num;
  int suma= 0;


  do{
        printf("Ingrese un numeros positivos: \n");
        scanf("%d", &num);

    if(num<0){
       printf("Su numero no es valido");
       break;
    }
    suma = suma + num;
    printf ("La suma va siendo: %d\n", suma);


    if (suma>1500){
        printf ("La suma dio mas de 1500. Fin");
        break;
    }



  } while (num != 0 );






    return 0;
}
