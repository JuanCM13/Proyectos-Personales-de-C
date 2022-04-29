/*
 ============================================================================
MENDEZ JUAN CRUZ DIV 1-C

Ejercicio 1-2:
Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden
fue ingresado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define RANGO 5

int main(void)
{
	setbuf(stdout, NULL);

	int i;
	int minimo;
	int maximo;
	int numero;
	int contadorPosisionMaximo;
	int contadorPosisionMinimo;

	for(i=0;i<RANGO;i++)
	{
		printf("Ingresa un numero: ---- llevas ingresados %d numeros",i);
		scanf("%d",&numero);

		if(i==0)
		{
			minimo=numero;
			maximo=numero;
			contadorPosisionMaximo=i+1;
			contadorPosisionMinimo=i+1;
		}
		else
		{
			if(numero>maximo)
			{
				maximo=numero;
				contadorPosisionMaximo=i+1;
			}

			if(numero<minimo)
			{
				minimo=numero;
				contadorPosisionMinimo=i+1;
			}
		}


	}

	printf("El numero maximo ingresado fue: %d y su posision fue: %d\n el minimo fue: %d y su posision fue: %d\n",maximo,contadorPosisionMaximo, minimo, contadorPosisionMinimo);


	return EXIT_SUCCESS;
}
