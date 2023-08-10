#include <stdio.h>
#include <stdlib.h>

///Ingresar un numero que represente un día de la semana, y mostrar por pantalla 1 – Lunes, …. 7 – Domingo,
///cualquier otro numero ERROR.



int main()
{

   int dia;

   printf("Ingrese un numero del 1 al 7 y se le dira que dia es:  \n");
   scanf("%d", &dia);

   switch (dia){

       case 1: printf("Lunes");
       break;
       case 2: printf("Martes");
       break;
       case 3: printf("Miercoles");
       break;
       case 4: printf("Jueves");
       break;
       case 5: printf("Viernes");
       break;
       case 6: printf("Sabado");
       break;
       case 7: printf("Domingo");
       break;
       default: printf("El numero no corresponde a un dia de la semana");




   }




    return 0;
}
