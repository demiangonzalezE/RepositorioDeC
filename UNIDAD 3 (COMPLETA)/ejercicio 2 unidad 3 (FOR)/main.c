#include <stdio.h>
#include <stdlib.h>

///MOSTRAR todos los n�meros divisibles por 2, por 6 y por 7 que no sean divisibles por 4 y sean menores a 10000.


int main()
{
    int i;

        for (i = 0; i < 10000; i ++){
           if (i%2 == 0 && i%6 == 0 && i%7 == 0 && i%4 != 0){
            printf("%d\n", i);
        }
    }








    return 0;
}
