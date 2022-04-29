/*
 ============================================================================
 Name        : calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void DesplegarMenu(int*);
int utn_getNumero(int*, char[]);

int main(void)
{
	setbuf(stdout, NULL);

	int numeroUno;
	int numeroDos;
	int opcion;
	char barrer;

	do
	{

		DesplegarMenu(&opcion);

		switch(opcion)
		{
		case 1:
				utn_getNumero(&numeroUno,"Ingrese el primer operando: \n");
		break;
		case 2:
				utn_getNumero(&numeroDos,"Ingrese el segundo operando: \n");
		break;
		}

		printf("Limpiamos la pantalla?? s/n\n");
		fflush(stdin);
		scanf("%c",&barrer);

			if(barrer == 's')
			{
			    //printf("ENTRE");
				system("cls");
			}

	}while(opcion != 4);

	//printf(" la opcion ingresada es: %d\n",opcion);
	//printf("El primer operando es: %d\n el segundo es: %d\n",numeroUno, numeroDos);
	return EXIT_SUCCESS;
}

void DesplegarMenu(int* opcion)
{
	int buffer;

	if(opcion != NULL)
	{

		do
		{
			printf("1. Ingresar 1er operando\n");
			printf("2. Ingresar 2do operando \n");
			printf("3. Calcular todas las operaciones\n");
			printf("a Calcular la suma \n");
			printf("b) Calcular la resta \n");
			printf("c) Calcular la division \n");
			printf("d) Calcular la multiplicacion \n");
			printf("e) Calcular el factorial \n");
			printf("4. Informar resultados\n");
			printf("a) “El resultado de A+B es: r”\n");
			printf("b) “El resultado de A-B es: r”\n");
			printf("c) “El resultado de A/B es: r” o “No es posible dividir por cero”\n");
			printf("d) “El resultado de A*B es: r”\n");
			printf("e) “El factorial de A es: r1 y El factorial de B es: r2”\n");
			printf("5. Salir\n");
			scanf("%d",&buffer);
			//printf("la opcion es: %d",buffer);

			if(buffer == 1 || buffer == 2 || buffer == 3 || buffer == 4)
			{
				*opcion = buffer;
				printf("%d",*opcion);
				break;
			}
			else
			{
				printf("\n\nError, reingrese un numerop en el rango de opciones: \n\n");
			}

		}while(1);

	}

}

int utn_getNumero(int* numero, char mensaje[])
{

	int retorno = -1;
	int auxiliar;

	if(numero != NULL && mensaje != NULL )
	{
		printf("%s",mensaje);
		scanf("%d",&auxiliar);
		*numero = auxiliar;
		retorno = 0;
	}

	return retorno;
}


