/******************************************************************************

MENDEZ JUAN CRUZ---- DIV 1C

Ejercicio 1-1:
Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a) El promedio de los números positivos.
b) El promedio de los números negativos.
*******************************************************************************/
#include <stdio.h>

int main()
{

	setbuf(stdout, NULL);

    char respuesta;
    int numero;
    int contadorP;
    int contadorN;
    int acumuladorP;
    int acumuladorN;
    float promedioP;
    float promedioN;

    contadorN=0;
    contadorP=0;
    acumuladorN=0;
    acumuladorP=0;

    do
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&numero);

        if(numero>0)
        {
            contadorP++;
            acumuladorP+=numero;
        }
        else
        {
            contadorN++;
            acumuladorN+=numero;
        }

        printf("seguimos? y/n\n");
        fflush(stdin);
        scanf("%c",&respuesta);

    }while(respuesta=='y');


    promedioN=(float)acumuladorN/contadorN;
    promedioP=(float)acumuladorP/contadorP;

    printf("El promedio de positivos es de %.2f %%\n El promedio de negativos es: %.2f %%\n",promedioP,promedioN);

    return 0;
}
