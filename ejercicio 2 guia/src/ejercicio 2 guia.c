/*
 ============================================================================
 Name        : ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 1-2: ingresar 3 números y mostrar cuál de los tres es el mayor.
Ejemplo:
Si ingresamos 5, 9 y 3 el programa mostrará: “El mayor de los números es el segundo”
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	setbuf(stdout,NULL);

		int numeroUno;
		int numeroDos;
		int numeroTres;

		printf("Ingresate un numero:\n");
		scanf("%d",&numeroUno);

		printf("Ingresate otro numero:\n");
		scanf("%d",&numeroDos);

		printf("Ingresate otro numero:\n");
		scanf("%d",&numeroTres);

		if(numeroUno>numeroDos && numeroUno > numeroTres)
		{
			printf("El primer numero es el mayor");
		}
		else
		{
			if(numeroDos>numeroTres)
			{
				printf("El segundo numero es el mayor");
			}
			else
			{
				printf("El tercer numero es el mayor");
			}
		}


	return EXIT_SUCCESS;
}
