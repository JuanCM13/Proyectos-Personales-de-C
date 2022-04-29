/*
 ============================================================================
Juan Cruz mendez div 1-c

Ejercicio 2-2:
Realizar un programa que permita el ingreso de 10 números enteros. Determinar el
promedio de los positivos, la cantidad de ceros y del menor de los negativos la suma
de los antecesores.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define RANGO 10

int utn_getNumero(int* numero,char* mensaje);

int main(void)
{

	setbuf(stdout, NULL);

	int i;
	int numero;
	int verificacion;
	int acumuladorPositivos;
	float promedioPositivos;
	int contadorCeros;
	int flagMenorNegativos;
	int menorNegativos;
	int posicionMenorNegativos;
	int sumaAntecesoresMenorNegativos;

	sumaAntecesoresMenorNegativos=0;
	flagMenorNegativos=1;
	contadorCeros=0;
	acumuladorPositivos=0;

	//int verificacionPromedio;

//	verificacion = (utn_getNumero(&numero,"Ingrese un numero entero\n" ));

	//printf("%d\n",verificacion);

	for(i=0;i<10;i++)
	{
		verificacion = (utn_getNumero(&numero,"Ingrese un numero entero\n" ));

		if(verificacion > -1)
		{
			if(numero > 0)
			{
				acumuladorPositivos+=numero;
			}
			else
			{
				if(numero < 0)
				{
					if(flagMenorNegativos || menorNegativos>numero)
					{
						flagMenorNegativos=0;
						menorNegativos=numero;
						for(i=posicionMenorNegativos;i>-1;i--)
						{
							sumaAntecesoresMenorNegativos+=numero;
						}
					}

			}
		}
    }


		promedioPositivos=(float)acumuladorPositivos/10;

		printf("El promedio de positivos dio: %f\n",promedioPositivos);
		printf("la cantidad de ceros ingresadas fue de: %d\n",contadorCeros);
		printf("La suma de los antecesores del menor numero negativo fue de: %d\n",sumaAntecesoresMenorNegativos);



		return 0;
}


int utn_getNumero (int* numero,char* mensaje)
{

	int buffer;
	int retorno;

	retorno=-1;

	if(numero != NULL && mensaje != NULL)
	{
		printf("%s\n",mensaje);
		scanf("%d",&buffer);

		*numero= buffer;
		retorno=0;
	}

	return retorno;
}
