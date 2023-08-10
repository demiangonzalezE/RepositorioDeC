#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso,altura,imc;


    printf("indicar peso\n");
    scanf("%f",&peso);


    printf("indicar altura\n");
    scanf("%f",&altura);



    imc=peso/(altura*altura);

    printf("Su indice de masa corporal es: %.1f \n",imc);



    if(imc<18.5){

        printf(" Su peso es inferior al normal");

    }
        else{
                if(imc>=18.5 && imc<=24.9){

                printf(" Su peso es normal\n");

            }

            else{
                    if(imc>=25.0 && imc<=30.0){

                    printf(" Su peso es superior al normal");

                }

             else{
                    printf(" Obesidad");

            }

        }

        }


    return 0;
}
